#pragma once
#include "MetaData/Location.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class Destructor : public Location
    {
    public:
        static constexpr TypeCode id = DestructorTag;

    private:
        friend class MetaFile;  // To define an access only API.

        AccessType _access{UnknownTag};

        uint8_t _flags{NoFlags};

    public:
        Destructor(const String& sId, const String& name, TypeCode code);

        AccessType access() const;

        uint8_t flags() const;
    };

    inline AccessType Destructor::access() const
    {
        return _access;
    }

    inline uint8_t Destructor::flags() const
    {
        return _flags;
    }

}  // namespace Rt2::MetaData
