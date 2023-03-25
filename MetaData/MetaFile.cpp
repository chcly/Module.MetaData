#include "MetaData/MetaFile.h"
#include "MetaData/Argument.h"
#include "MetaData/ArgumentList.h"
#include "MetaData/Class.h"
#include "MetaData/Constructor.h"
#include "MetaData/CvQualifiedType.h"
#include "MetaData/Destructor.h"
#include "MetaData/Field.h"
#include "MetaData/File.h"
#include "MetaData/Function.h"
#include "MetaData/FunctionType.h"
#include "MetaData/FundamentalType.h"
#include "MetaData/Method.h"
#include "MetaData/Namespace.h"
#include "MetaData/OperatorMethod.h"
#include "MetaData/PointerType.h"
#include "MetaData/ReferenceType.h"
#include "MetaData/Struct.h"
#include "MetaData/Typedef.h"
#include "TypeListBuilder.h"
#include "Utils/Char.h"
#include "Utils/StreamConverters/Hex.h"
#include "Xml/File.h"

namespace Rt2::MetaData
{

    constexpr TypeFilter FileTags[MaxTypeCode] = {
        {        "CastXML",        MinTypeCode},
        {          "Class",           ClassTag},
        {         "Struct",          StructTag},
        {       "Function",        FunctionTag},
        {   "FunctionType",    FunctionTypeTag},
        {    "Constructor",     ConstructorTag},
        {"CvQualifiedType", CvQualifiedTypeTag},
        {     "Destructor",      DestructorTag},
        {          "Field",           FieldTag},
        {"FundamentalType", FundamentalTypeTag},
        {           "File",            FileTag},
        {         "Method",          MethodTag},
        {      "Namespace",       NamespaceTag},
        { "OperatorMethod",  OperatorMethodTag},
        {  "ReferenceType",   ReferenceTypeTag},
        {    "PointerType",     PointerTypeTag},
        {       "Argument",        ArgumentTag},
        {        "Typedef",         TypedefTag}
    };

    class AttributeConverter
    {
    public:
        static AccessType access(const String& val)
        {
            if (val == "public")
                return PublicTag;
            if (val == "private")
                return PrivateTag;
            if (val == "protected")
                return ProtectedTag;
            return UnknownTag;
        }

        static uint8_t flags(const Xml::Node* node)
        {
            uint8_t flags = NoFlags;
            if (node->attribute("inline", "0") == "1")
                flags |= Inline;
            if (node->attribute("extern", "0") == "1")
                flags |= Extern;
            if (node->attribute("explicit", "0") == "1")
                flags |= Explicit;
            if (node->attribute("artificial", "0") == "1")
                flags |= Artificial;
            if (node->attribute("const", "0") == "1")
                flags |= Const;
            return flags;
        }

        static void specialName(const int64_t code, String& dest)
        {
            switch (code)
            {
            case PointerTypeTag:
                dest = "*";
                break;
            case ReferenceTypeTag:
                dest = "&";
                break;
            case CvQualifiedTypeTag:
                dest = "const";
                break;
            case FunctionTypeTag:
                dest = "(*)()";
                break;
            default:
                dest = Su::join('<', Hex(code), '>');
                break;
            }
        }
    };
    using Ac = AttributeConverter;

    MetaFile::~MetaFile()
    {
        clear();
    }

    TypeListBuilder MetaFile::list()
    {
        return TypeListBuilder(this);
    }

    Type* MetaFile::assert_find(const String& id)
    {
        if (Type* val = find(id))
            return val;
        throw Exception("assert_find failed to resolve: ", id);
    }

    ContextType* MetaFile::context_find(const String& id)
    {
        switch (Type* base = assert_find(id);
                base->code())
        {
        case ClassTag:
            return context<Class>(base);
        case NamespaceTag:
            return base->assert_cast<Namespace>()->context();
        case FunctionTag:
            return base->assert_cast<Function>()->context();
        case TypedefTag:
            return base->assert_cast<Typedef>()->context();
        case FieldTag:
            return context<Field>(base);
        case StructTag:
            return base->assert_cast<Struct>()->context();
        case DestructorTag:
            return base->assert_cast<Destructor>()->context();
        case MethodTag:
            return base->assert_cast<Method>()->context();
        case ConstructorTag:
            return base->assert_cast<Constructor>()->context();
        case OperatorMethodTag:
            return base->assert_cast<OperatorMethod>()->context();
        case FunctionTypeTag:
        case CvQualifiedTypeTag:
        case FundamentalTypeTag:
        case FileTag:
        case ReferenceTypeTag:
        case PointerTypeTag:
        case ArgumentTag:
        case MaxTypeCode:
        case LocationTag:
        case MinTypeCode:
        case NullCode:
        default:
            return nullptr;
        }
    }

    void MetaFile::clear()
    {
        for (const auto& [key, value] : _types)
            delete value;
        _types.clear();
    }

    Type* MetaFile::find(const String& id)
    {
        if (!id.empty())
        {
            if (const Types::iterator it = _types.find(id);
                it != _types.end())
                return it->second;
        }
        return nullptr;
    }

    Type* MetaFile::find(const String& id, const TypeCode type)
    {
        if (Type* obj = find(id);
            obj && obj->isTypeOf(type))
            return obj;
        return nullptr;
    }

    void MetaFile::createType(const Xml::Node* node)
    {
        if (!node)
            throw Exception("invalid node");

        const String id = node->attribute("id");
        if (id.empty())
            throw Exception("missing id attribute");

        String name = node->attribute("name");
        if (name.empty())
            Ac::specialName(node->type(), name);

        if (node->type() < MinTypeCode || node->type() > MaxTypeCode)
            throw Exception("invalid type code: ", node->type());

        Type* type = create(id, name, (TypeCode)node->type());
        if (type == nullptr)
            throw Exception("failed to create a usable type instance for: ", id);

        if (_types.find(type->id()) != _types.end())
            throw Exception("duplicate id found: ", id);

        _types[type->id()] = type;
    }

    void MetaFile::link(const Type* obj, const Xml::Node* node)
    {
        if (!obj || !node)
            throw Exception("invalid arguments");

        if (String ctx = node->attribute("context");
            !ctx.empty())
        {
            ContextType* self = context_find(obj->id());
            if (!self)
                throw Exception("missing context ", obj->id());

            if (Type* type = assert_find(ctx))
                self->_context = type;
            else
                Console::println("missing context member: ", ctx);
        }
    }

    void MetaFile::link(Typedef* obj, const Xml::Node* node)
    {
        obj->_type = assert_find(node->attribute("type"));
    }

    void MetaFile::mergeMembers(ContextType* dest, const Xml::Node* node)
    {
        if (const String members = node->attribute("members");
            !members.empty())
        {
            StringArray memLink;
            Su::splitRejectEmpty(memLink, members, ' ');

            for (const auto& link : memLink)
            {
                if (Type* cacheType = assert_find(link); cacheType != nullptr)
                    dest->_members.push_back(cacheType);
                else
                    Console::println("missing member: ", link);
            }
        }
    }

    void MetaFile::linkArgument(ArgumentListType* obj, const Xml::Node* node)
    {
        Argument* arg = obj->create();
        linkLocation(arg->location(), node);

        arg->_type = assert_find(node->attribute("type"));
        arg->_name = node->attribute("name");
    }

    void MetaFile::linkArgumentList(ArgumentListType* obj, const Xml::Node* node)
    {
        for (const Xml::Node* chi : node->children())
        {
            if (chi->isTypeOf(ArgumentTag))
                linkArgument(obj, chi);
        }
    }

    void MetaFile::linkLocation(Location* obj, const Xml::Node* node)
    {
        obj->_file = find<File>(node->attribute("file"));
        obj->_line = Char::toUint64(node->attribute("line", "0"));
    }

    void MetaFile::link(Namespace* obj, const Xml::Node* node)
    {
        mergeMembers(obj->context(), node);
    }

    void MetaFile::link(Class* obj, const Xml::Node* node)
    {
        mergeMembers(&obj->_context, node);
        linkLocation(obj->location(), node);

        obj->_sizeInBytes = Char::toUint64(node->attribute("size", "0"));

        obj->_align = Char::toUint64(node->attribute("align", "0"));
    }

    void MetaFile::link(Function* obj, const Xml::Node* node)
    {
        linkLocation(obj->location(), node);
        linkArgumentList(obj->arguments(), node);

        obj->_returns = assert_find(node->attribute("returns"));

        obj->_flags = Ac::flags(node);
    }

    void MetaFile::link(FunctionType* obj, const Xml::Node* node)
    {
        obj->_returns = assert_find(node->attribute("returns"));
    }

    void MetaFile::link(Struct* obj, const Xml::Node* node)
    {
        mergeMembers(obj->context(), node);
        linkLocation(obj->location(), node);

        obj->_sizeInBytes = Char::toUint64(node->attribute("size", "0"));

        obj->_align = Char::toUint64(node->attribute("align", "0"));
    }

    void MetaFile::link(Field* obj, const Xml::Node* node)
    {
        linkLocation(obj->location(), node);

        obj->_offset = Char::toUint64(node->attribute("offset", "0"));

        obj->_access = Ac::access(node->attribute("access"));

        obj->_type = assert_find(node->attribute("type"));
    }

    void MetaFile::link(Constructor* obj, const Xml::Node* node)
    {
        linkLocation(&obj->_location, node);
        linkArgumentList(obj->arguments(), node);

        obj->_access = Ac::access(node->attribute("access"));

        obj->_flags = Ac::flags(node);
    }

    void MetaFile::link(Destructor* obj, const Xml::Node* node)
    {
        linkLocation(obj->location(), node);

        obj->_access = Ac::access(node->attribute("access"));

        obj->_flags = Ac::flags(node);
    }

    void MetaFile::link(Method* obj, const Xml::Node* node)
    {
        linkLocation(obj->location(), node);
        linkArgumentList(obj->arguments(), node);

        obj->_access = Ac::access(node->attribute("access"));

        obj->_flags = Ac::flags(node);

        obj->_returns = assert_find(node->attribute("returns"));
    }

    void MetaFile::link(OperatorMethod* obj, const Xml::Node* node)
    {
        linkLocation(obj->location(), node);
        linkArgumentList(obj->arguments(), node);

        obj->_access = Ac::access(node->attribute("access"));

        obj->_flags = Ac::flags(node);

        obj->_returns = assert_find(node->attribute("returns"));
    }

    void MetaFile::link(FundamentalType* obj, const Xml::Node* node)
    {
        obj->_sizeInBytes = Char::toUint64(node->attribute("size", "0"));

        obj->_align = Char::toUint64(node->attribute("align", "0"));
    }

    void MetaFile::link(ReferenceType* obj, const Xml::Node* node)
    {
        obj->_sizeInBytes = Char::toUint64(node->attribute("size", "0"));

        obj->_align = Char::toUint64(node->attribute("align", "0"));

        obj->_type = assert_find(node->attribute("type"));
    }

    void MetaFile::link(PointerType* obj, const Xml::Node* node)
    {
        obj->_sizeInBytes = Char::toUint64(node->attribute("size", "0"));

        obj->_align = Char::toUint64(node->attribute("align", "0"));

        obj->_type = assert_find(node->attribute("type"));
    }

    void MetaFile::link(CvQualifiedType* obj, const Xml::Node* node)
    {
        obj->_flags = Ac::flags(node);

        obj->_type = assert_find(node->attribute("type"));
    }

    void MetaFile::linkType(const Xml::Node* node)
    {
        if (!node)
            throw Exception("invalid node");

        Type* type = assert_find(node->attribute("id"));
        if (type->code() != node->type())
            throw Exception("type mismatch:", type->code(), ',', node->type());

        link(type, node);

        switch ((TypeCode)node->type())
        {
        case NamespaceTag:
            link(type->assert_cast<Namespace>(), node);
            break;
        case ClassTag:
            link(type->assert_cast<Class>(), node);
            break;
        case FieldTag:
            link(type->assert_cast<Field>(), node);
            break;
        case ConstructorTag:
            link(type->assert_cast<Constructor>(), node);
            break;
        case CvQualifiedTypeTag:
            link(type->assert_cast<CvQualifiedType>(), node);
            break;
        case DestructorTag:
            link(type->assert_cast<Destructor>(), node);
            break;
        case FundamentalTypeTag:
            link(type->assert_cast<FundamentalType>(), node);
            break;
        case MethodTag:
            link(type->assert_cast<Method>(), node);
            break;
        case OperatorMethodTag:
            link(type->assert_cast<OperatorMethod>(), node);
            break;
        case ReferenceTypeTag:
            link(type->assert_cast<ReferenceType>(), node);
            break;
        case PointerTypeTag:
            link(type->assert_cast<PointerType>(), node);
            break;
        case FunctionTag:
            link(type->assert_cast<Function>(), node);
            break;
        case StructTag:
            link(type->assert_cast<Struct>(), node);
            break;
        case TypedefTag:
            link(type->assert_cast<Typedef>(), node);
            break;
        case FunctionTypeTag:
            link(type->assert_cast<FunctionType>(), node);
            break;
        case FileTag:
        case LocationTag:
        case ArgumentTag:
        case MinTypeCode:
        case MaxTypeCode:
        default:
            break;
        }
    }

    void MetaFile::loadImpl(const Xml::Node* node)
    {
        if (!node)
            throw Exception("invalid node");

        _format = node->attribute("format");

        Xml::Node::forEach(node->children(), this, &MetaFile::createType);
        Xml::Node::forEach(node->children(), this, &MetaFile::linkType);
    }

    Type* MetaFile::create(const String& strId, const String& name, const TypeCode id)
    {
        switch (id)
        {
        case ClassTag:
            return new Class(strId, name, id);
        case ConstructorTag:
            return new Constructor(strId, name, id);
        case CvQualifiedTypeTag:
            return new CvQualifiedType(strId, name, id);
        case DestructorTag:
            return new Destructor(strId, name, id);
        case FieldTag:
            return new Field(strId, name, id);
        case FundamentalTypeTag:
            return new FundamentalType(strId, name, id);
        case FileTag:
            return new File(strId, name, id);
        case MethodTag:
            return new Method(strId, name, id);
        case NamespaceTag:
            return new Namespace(strId, name, id);
        case OperatorMethodTag:
            return new OperatorMethod(strId, name, id);
        case ReferenceTypeTag:
            return new ReferenceType(strId, name, id);
        case PointerTypeTag:
            return new PointerType(strId, name, id);
        case FunctionTag:
            return new Function(strId, name, id);
        case StructTag:
            return new Struct(strId, name, id);
        case TypedefTag:
            return new Typedef(strId, name, id);
        case FunctionTypeTag:
            return new FunctionType(strId, name, id);
        case ArgumentTag:
        case MinTypeCode:
        case LocationTag:
        case MaxTypeCode:
        default:
            return nullptr;
        }
    }

    void MetaFile::load(IStream& stream)
    {
        try
        {
            if (const Xml::Node* root = Xml::File::detachRead(
                    FileTags,
                    std::size(FileTags),
                    stream,
                    "MetaData::load"))
            {
                loadImpl(root->firstChildOf(MinTypeCode));
                delete root;
            }
        }
        catch (Exception& ex)
        {
            Console::writeError(ex.what());
            clear();
            throw;
        }
    }
}  // namespace Rt2::MetaData
