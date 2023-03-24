#pragma once
#include "Utils/Definitions.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    enum TypeCode
    {
        RootTag,
        ClassTag,
        ConstructorTag,
        CvQualifiedTypeTag,
        DestructorTag,
        FieldTag,
        FundamentalTypeTag,
        LocationTag,
        MethodTag,
        NamespaceTag,
        OperatorMethodTag,
        ReferenceTypeTag,
        PointerTypeTag,
        FileTagsMax,
    };

    class Type
    {
    private:
        const String          _id{};
        const String          _name{};
        const TypeCode _code{FileTagsMax};

        Type() = default;

        Type(const Type& rhs) = default;

    public:
        explicit Type(String id, String name, TypeCode code);

        const TypeCode& hash() const;

        const String& id() const;
    };

    inline const TypeCode& Type::hash() const
    {
        return _code;
    }

    inline const String& Type::id() const
    {
        return _id;
    }
}  // namespace Rt2::MetaData
