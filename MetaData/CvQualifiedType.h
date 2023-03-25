#pragma once
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class CvQualifiedType final : public Type
    {
    public:
        static constexpr TypeCode id = CvQualifiedTypeTag;

    private:
        friend class MetaFile;  // To define an access only API.

        Type* _type{nullptr};

        uint8_t _flags{NoFlags};

    public:
        CvQualifiedType(const String& sId, const String& name, TypeCode code);

        uint8_t flags() const;

        Type* type() const;

        bool isConst() const;
    };

    inline uint8_t CvQualifiedType::flags() const
    {
        return _flags;
    }

    inline Type* CvQualifiedType::type() const
    {
        return _type;
    }


}  // namespace Rt2::MetaData
