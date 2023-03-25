#pragma once
#include "ArgumentType.h"
#include "MetaData/Location.h"
#include "Utils/String.h"
#include "MetaData/Argument.h"

namespace Rt2::MetaData
{
    class Constructor final : public ArgumentType
    {
    public:
        static constexpr TypeCode id = ConstructorTag;

    private:
        friend class MetaFile;  // To define an access only API.

        AccessType _access{UnknownTag};

        uint8_t _flags{NoFlags};

        Location _location;

    public:
        Constructor(const String& sId, const String& name, TypeCode code);

        ~Constructor() override;

        AccessType access() const;

        uint8_t flags() const;

        const Location* location() const;

        
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
