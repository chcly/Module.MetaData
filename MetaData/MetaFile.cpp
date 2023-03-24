#include "MetaData/MetaFile.h"
#include "MetaData/Class.h"
#include "MetaData/Constructor.h"
#include "MetaData/CvQualifiedType.h"
#include "MetaData/Destructor.h"
#include "MetaData/Field.h"
#include "MetaData/File.h"
#include "MetaData/Function.h"
#include "MetaData/FundamentalType.h"
#include "MetaData/Method.h"
#include "MetaData/Namespace.h"
#include "MetaData/OperatorMethod.h"
#include "MetaData/Struct.h"
#include "PointerType.h"
#include "ReferenceType.h"
#include "Utils/Char.h"
#include "Utils/String.h"
#include "Xml/File.h"

namespace Rt2::MetaData
{

    constexpr TypeFilter FileTags[MaxTypeCode] = {
        {        "CastXML",        MinTypeCode},
        {          "Class",           ClassTag},
        {         "Struct",          StructTag},
        {       "Function",        FunctionTag},
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
            return flags;
        }
    };
    using Ac = AttributeConverter;

    MetaFile::~MetaFile()
    {
        clear();
    }


    void MetaFile::clear()
    {
        for (const auto& type : _types)
            delete type.second;
        _types.clear();
    }

    Type* MetaFile::find(const String& id)
    {
        if (!id.empty())
        {
            if (const size_t pos = _types.find(id);
                pos != Npos)
                return _types.at(pos);
        }
        return nullptr;
    }


    void MetaFile::createType(const Xml::Node* node)
    {
        if (!node)
            throw Exception("invalid node");

        const String id = node->attribute("id");
        if (id.empty())
            throw Exception("missing id attribute");

        const String name = node->attribute("name");

        if (node->type() < MinTypeCode || node->type() > MaxTypeCode)
            throw Exception("invalid type code: ", node->type());

        Type* type = create(id, name, (TypeCode)node->type());
        if (type == nullptr)
            throw Exception("failed to create a usable type instance for: ", id);

        if (_types.find(type->id()) != Npos)
            throw Exception("duplicate id found: ", id);

        _types.insert(type->id(), type);
    }

    void MetaFile::link(Type* obj, const Xml::Node* node)
    {
        if (!obj || !node)
            throw Exception("invalid arguments");

        if (String ctx = node->attribute("context");
            !ctx.empty())
        {
            if (Type* ctxObj = find(ctx); ctxObj != nullptr)
                ctxObj->addChild(obj);
            else
                Console::println("missing context member: ", ctx);
        }
    }

    void MetaFile::mergeMembers(TypeArray& dest, const Xml::Node* node)
    {
        if (const String members = node->attribute("members");
            !members.empty())
        {
            StringArray memLink;
            Su::splitRejectEmpty(memLink, members, ' ');

            for (const auto& link : memLink)
            {
                if (Type* cacheType = find(link); cacheType != nullptr)
                    dest.push_back(cacheType);
                else
                    Console::println("missing member: ", link);
            }
        }
    }

    void MetaFile::link(Namespace* obj, const Xml::Node* node)
    {
        mergeMembers(obj->_members, node);
    }

    void MetaFile::link(Class* obj, const Xml::Node* node)
    {
        mergeMembers(obj->_members, node);

        obj->_sizeInBytes = Char::toUint64(node->attribute("size", "0"));

        obj->_align = Char::toUint64(node->attribute("align", "0"));
    }

    void MetaFile::link(Function* obj, const Xml::Node* node)
    {
        obj->_returns = find(node->attribute("returns"));

        obj->_flags = Ac::flags(node);
    }

    void MetaFile::link(Struct* obj, const Xml::Node* node)
    {
        mergeMembers(obj->_members, node);

        obj->_sizeInBytes = Char::toUint64(node->attribute("size", "0"));

        obj->_align = Char::toUint64(node->attribute("align", "0"));
    }

    void MetaFile::link(Field* obj, const Xml::Node* node)
    {
        obj->_offset = Char::toUint64(node->attribute("offset", "0"));

        obj->_access = Ac::access(node->attribute("access"));

        obj->_type = find(node->attribute("type"));
    }

    void MetaFile::link(Constructor* obj, const Xml::Node* node)
    {
        obj->_access = Ac::access(node->attribute("access"));

        obj->_flags = Ac::flags(node);
    }

    void MetaFile::link(Destructor* obj, const Xml::Node* node)
    {
        obj->_access = Ac::access(node->attribute("access"));

        obj->_flags = Ac::flags(node);
    }

    void MetaFile::link(Method* obj, const Xml::Node* node)
    {
        obj->_access = Ac::access(node->attribute("access"));

        obj->_flags = Ac::flags(node);

        obj->_returns = find(node->attribute("returns"));
    }

    void MetaFile::link(OperatorMethod* obj, const Xml::Node* node)
    {
        obj->_access = Ac::access(node->attribute("access"));

        obj->_flags = Ac::flags(node);

        obj->_returns = find(node->attribute("returns"));
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

        obj->_type = find(node->attribute("type"));
    }

    void MetaFile::link(PointerType* obj, const Xml::Node* node)
    {
        obj->_sizeInBytes = Char::toUint64(node->attribute("size", "0"));

        obj->_align = Char::toUint64(node->attribute("align", "0"));

        obj->_type = find(node->attribute("type"));
    }

    void MetaFile::link(CvQualifiedType* obj, const Xml::Node* node)
    {
        obj->_flags = Ac::flags(node);

        obj->_type = find(node->attribute("type"));
    }

    void MetaFile::link(File* obj, const Xml::Node* node)
    {
        _files.push_back(obj);
    }

    void MetaFile::linkType(const Xml::Node* node)
    {
        if (!node)
            throw Exception("invalid node");

        Type* cacheType = find(node->attribute("id"));

        // it must be the same, so check
        if (!cacheType)
            throw Exception("failed to find type:", node->attribute("id"));

        if (cacheType->code() != node->type())
            throw Exception("type mismatch:", cacheType->code(), ',', node->type());

        link(cacheType, node);

        switch ((TypeCode)node->type())
        {
        case NamespaceTag:
            link(cacheType->cast<Namespace>(), node);
            break;
        case ClassTag:
            link(cacheType->cast<Class>(), node);
            break;
        case FieldTag:
            link(cacheType->cast<Field>(), node);
            break;
        case ConstructorTag:
            link(cacheType->cast<Constructor>(), node);
            break;
        case CvQualifiedTypeTag:
            link(cacheType->cast<CvQualifiedType>(), node);
            break;
        case DestructorTag:
            link(cacheType->cast<Destructor>(), node);
            break;
        case FundamentalTypeTag:
            link(cacheType->cast<FundamentalType>(), node);
            break;
        case FileTag:
            link(cacheType->cast<File>(), node);
            break;
        case MethodTag:
            link(cacheType->cast<Method>(), node);
            break;
        case OperatorMethodTag:
            link(cacheType->cast<OperatorMethod>(), node);
            break;
        case ReferenceTypeTag:
            link(cacheType->cast<ReferenceType>(), node);
            break;
        case PointerTypeTag:
            link(cacheType->cast<PointerType>(), node);
            break;
        case FunctionTag:
            link(cacheType->cast<Function>(), node);
            break;
        case StructTag:
            link(cacheType->cast<Struct>(), node);
            break;
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
        case ArgumentTag:
        case MinTypeCode:
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
