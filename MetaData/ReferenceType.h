#pragma once
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class ReferenceType final : public Type
    {
    public:
        static constexpr TypeCode id = ReferenceTypeTag;

    private:
        friend class MetaFile;  // To define an access only API.

        Type* _type{nullptr};

        size_t _sizeInBytes{0};

        size_t _align{0};

    public:
        ReferenceType(const String& sId, const String& name, TypeCode code);
        ~ReferenceType() override = default;

        size_t sizeInBytes() const;

        size_t alignment() const;

        Type* type() const;

        bool isConst() const;

        bool  isPointer() const;
    };

    inline size_t ReferenceType::sizeInBytes() const
    {
        return _sizeInBytes;
    }

    inline size_t ReferenceType::alignment() const
    {
        return _align;
    }

    inline Type* ReferenceType::type() const
    {
        return _type;
    }

}  // namespace Rt2::MetaData
