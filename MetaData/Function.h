#pragma once
#include "MetaData/Location.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class Function : public Location
    {
    public:
        static constexpr TypeCode id = FunctionTag;

    private:
        friend class MetaFile;  // To define an access only API.

        Type* _returns{nullptr};

        uint8_t _flags{NoFlags};

    public:
        Function(const String& sId, const String& name, TypeCode code);

        Type* returns() const;

        uint8_t flags() const;
    };

    inline Type* Function::returns() const
    {
        return _returns;
    }

    inline uint8_t Function::flags() const
    {
        return _flags;
    }

}  // namespace Rt2::MetaData
