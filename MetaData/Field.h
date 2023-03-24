#pragma once
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class Field : public Type
    {
    public:
        static constexpr TypeCode id = FieldTag;

    private:
        friend class MetaFile;  // To define an access only API.

        AccessType _access{PrivateTag};

        size_t _offset{0};

        Type* _type{nullptr};

    public:
        Field(const String& id, const String& name, TypeCode code);

        AccessType access() const;

        size_t offset() const;

        inline Type* type() const;
    };

    inline AccessType Field::access() const
    {
        return _access;
    }

    inline size_t Field::offset() const
    {
        return _offset;
    }

    inline Type* Field::type() const
    {
        return _type;
    }

}  // namespace Rt2::MetaData
