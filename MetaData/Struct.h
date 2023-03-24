#pragma once
#include "MetaData/Location.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class Struct : public Location
    {
    public:
        static constexpr TypeCode id = StructTag;

    private:
        friend class MetaFile;  // To define an access only API.

        size_t _sizeInBytes{0};
        size_t _align{0};

        TypeArray _members;

    public:
        Struct(const String& sId, const String& name, TypeCode code);

        size_t sizeInBytes() const;

        size_t alignment() const;

        const TypeArray& members() const;
    };

    inline size_t Struct::sizeInBytes() const
    {
        return _sizeInBytes;
    }

    inline size_t Struct::alignment() const
    {
        return _align;
    }

    inline const TypeArray& Struct::members() const
    {
        return _members;
    }

}  // namespace Rt2::MetaData
