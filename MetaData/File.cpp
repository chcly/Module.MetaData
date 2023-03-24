#include "MetaData/File.h"
#include "MetaData/Class.h"
#include "MetaData/Constructor.h"
#include "MetaData/CvQualifiedType.h"
#include "MetaData/Destructor.h"
#include "MetaData/Field.h"
#include "MetaData/FundamentalType.h"
#include "MetaData/Location.h"
#include "MetaData/Method.h"
#include "MetaData/Namespace.h"
#include "MetaData/OperatorMethod.h"
#include "PointerType.h"
#include "ReferenceType.h"
#include "Utils/String.h"
#include "Xml/File.h"

namespace Rt2::MetaData
{
   

    constexpr TypeFilter FileTags[FileTagsMax] = {
        {        "CastXML",            RootTag},
        {          "Class",           ClassTag},
        {    "Constructor",     ConstructorTag},
        {"CvQualifiedType", CvQualifiedTypeTag},
        {     "Destructor",      DestructorTag},
        {          "Field",           FieldTag},
        {"FundamentalType", FundamentalTypeTag},
        {       "Location",        LocationTag},
        {         "Method",          MethodTag},
        {      "Namespace",       NamespaceTag},
        { "OperatorMethod",  OperatorMethodTag},
        {  "ReferenceType",   ReferenceTypeTag},
        {    "PointerType",     PointerTypeTag},
    };

    File::~File()
    {
        clear();
    }

    void File::clear()
    {
        for (const auto& type : _types)
            delete type.second;
        _types.clear();
    }

    void File::createType(const Xml::Node* node)
    {
        if (!node)
            throw Exception("invalid node");

        const String id = node->attribute("id");
        if (id.empty())
            throw Exception("missing id attribute");

        const String name = node->attribute("name");

        int64_t code = node->getTypeCode();
        if (code < RootTag || code > FileTagsMax)
            throw Exception("invalid type code");

        Type* type = create(id, name, (TypeCode)code);
        if (type == nullptr)
            throw Exception("failed to create a usable type instance for: ", id);

        if (_types.find(type->id()) != Npos)
            throw Exception("duplicate id found: ", id);

        _types.insert(type->id(), type);
    }

    void File::linkType(const Xml::Node* node)
    {
        if (!node)
            throw Exception("invalid node");
    }

    void File::loadImpl(const Xml::Node* node)
    {
        if (!node)
            throw Exception("invalid node");

        _format = node->attribute("format");

        Xml::Node::forEach(node->children(), this, &File::createType);
        Xml::Node::forEach(node->children(), this, &File::linkType);
    }

    Type* File::create(const String& strId, const String& name, const TypeCode id)
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
        case LocationTag:
            return new Location(strId, name, id);
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
        case RootTag:
        case FileTagsMax:
        default:
            return nullptr;
        }
    }

    void File::load(IStream& stream)
    {
        try
        {
            if (const Xml::Node* root = Xml::File::detachRead(
                    FileTags,
                    std::size(FileTags),
                    stream,
                    "MetaData::load"))
            {
                loadImpl(root->firstChildOf(RootTag));
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
