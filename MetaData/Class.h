#pragma once
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class Class : public Type
    {
    public:
        static constexpr TypeCode id = ClassTag;

    private:
        friend class MetaFile;  // To define an access only API.

        size_t _sizeInBytes{0};

        size_t _align{0};

        TypeArray _members;

    public:
        Class(const String& id, const String& name, TypeCode code);

        size_t sizeInBytes() const;

        size_t alignment() const;

        const TypeArray& members() const;
    };

    inline size_t Class::sizeInBytes() const
    {
        return _sizeInBytes;
    }

    inline size_t Class::alignment() const
    {
        return _align;
    }

    inline const TypeArray& Class::members() const
    {
        return _members;
    }

}  // namespace Rt2::MetaData
