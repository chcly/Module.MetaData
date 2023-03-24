#include "MetaData/MetaFile.h"
#include "MetaData/Class.h"
#include "MetaData/Constructor.h"
#include "MetaData/CvQualifiedType.h"
#include "MetaData/Destructor.h"
#include "MetaData/Field.h"
#include "MetaData/File.h"
#include "MetaData/FundamentalType.h"
#include "MetaData/Method.h"
#include "MetaData/Namespace.h"
#include "MetaData/OperatorMethod.h"
#include "PointerType.h"
#include "ReferenceType.h"
#include "Utils/String.h"
#include "Xml/File.h"

namespace Rt2::MetaData
{

    constexpr TypeFilter FileTags[MaxTypeCode] = {
        {        "CastXML",        MinTypeCode},
        {          "Class",           ClassTag},
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
    };

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

    void MetaFile::linkContext(Type* obj, const Xml::Node* node)
    {
        if (!obj || !node)
            throw Exception("invalid arguments");

        if (String ctx = node->attribute("context"); 
            !ctx.empty())
        {
            if (Type * ctxObj = find(ctx); ctxObj != nullptr)
                ctxObj->addChild(obj);
            else
                Console::println("missing context member: ", ctx);
        }
    }

    void MetaFile::linkNamespace(Namespace* obj, const Xml::Node* node)
    {
        if (const String members = node->attribute("members"); 
            !members.empty())
        {
            StringArray memLink;
            Su::splitRejectEmpty(memLink, members, ' ');

            for (const auto& link : memLink)
            {
                if (Type* cacheType = find(link); cacheType!=nullptr)
                    obj->_members.push_back(cacheType);
                else
                    Console::println("missing namespace member: ", link);
            }
        }

    }

    void MetaFile::linkClass(Namespace* obj, const Xml::Node* node)
    {
    }

    void MetaFile::linkType(const Xml::Node* node)
    {
        if (!node)
            throw Exception("invalid node");

        Type* cacheType = find(node->attribute("id"));

        // it must be the same, so check
        if (!cacheType)
            throw Exception("failed to find type:", node->attribute("id"));

        if (cacheType->type() != node->type())
            throw Exception("type mismatch:", cacheType->type(), ',', node->type());

        switch ((TypeCode)node->type())
        {
        case NamespaceTag:
            linkNamespace(cacheType->cast<Namespace>(), node);
            linkContext(cacheType, node);
            break;
        case ClassTag:
            break;
        case ConstructorTag:
            break;
        case CvQualifiedTypeTag:
            break;
        case DestructorTag:
            break;
        case FieldTag:
            break;
        case FundamentalTypeTag:
            break;
        case FileTag:
            break;
        case MethodTag:
            break;
        case OperatorMethodTag:
            break;
        case ReferenceTypeTag:
            break;
        case PointerTypeTag:
            break;
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
