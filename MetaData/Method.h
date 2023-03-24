#pragma once
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class Method : public Type
    {
    public:
        static constexpr TypeCode id = MethodTag;

    private:
        friend class MetaFile;  // To define an access only API.

        Type* _returns{nullptr};

        uint8_t _flags{NoFlags};

        AccessType _access{UnknownTag};

    public:
        Method(const String& id, const String& name, TypeCode code);

        AccessType access() const;

        Type* returns() const;

        uint8_t flags() const;
    };

    inline AccessType Method::access() const
    {
        return _access;
    }

    inline Type* Method::returns() const
    {
        return _returns;
    }

    inline uint8_t Method::flags() const
    {
        return _flags;
    }

}  // namespace Rt2::MetaData
