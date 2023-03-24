#pragma once
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class Constructor : public Type
    {
    public:
        static constexpr TypeCode id = ConstructorTag;

    private:
        friend class MetaFile;  // To define an access only API.

        AccessType _access{UnknownTag};

        uint8_t _flags{NoFlags};

    public:
        Constructor(const String& id, const String& name, TypeCode code);

        AccessType access() const;

        uint8_t flags() const;
    };

    inline AccessType Constructor::access() const
    {
        return _access;
    }

    inline uint8_t Constructor::flags() const
    {
        return _flags;
    }

}  // namespace Rt2::MetaData
