#pragma once
#include "MetaData/Type.h"

namespace Rt2::MetaData
{
    class FundamentalType final : public Type
    {
    public:
        static constexpr TypeCode id = FundamentalTypeTag;

    private:
        friend class MetaFile;

        AtomicType _atomic{AtomicUnknown};
        size_t     _sizeInBytes{0};
        size_t     _align{0};

    public:
        FundamentalType(const String& sId, const String& name, TypeCode code);
        ~FundamentalType() override = default;

        size_t sizeInBytes() const;

        size_t alignment() const;

        AtomicType type() const;
    };

    inline size_t FundamentalType::sizeInBytes() const
    {
        return _sizeInBytes;
    }

    inline size_t FundamentalType::alignment() const
    {
        return _align;
    }

}  // namespace Rt2::MetaData
