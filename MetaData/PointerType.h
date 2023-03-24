#pragma once
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class PointerType : public Type
    {
    public:
        static constexpr TypeCode id = PointerTypeTag;

    private:
        friend class MetaFile;  // To define an access only API.

        Type* _type{nullptr};

        size_t _sizeInBytes{0};

        size_t _align{0};

    public:
        PointerType(const String& sId, const String& name, TypeCode code);

        size_t sizeInBytes() const;

        size_t alignment() const;

        Type* type() const;
    };

    inline size_t PointerType::sizeInBytes() const
    {
        return _sizeInBytes;
    }

    inline size_t PointerType::alignment() const
    {
        return _align;
    }

    inline Type* PointerType::type() const
    {
        return _type;
    }

}  // namespace Rt2::MetaData
