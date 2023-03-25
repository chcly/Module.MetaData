#pragma once
#include "MetaData/Location.h"
#include "MetaData/ArgumentType.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class Function final : public ArgumentType
    {
    public:
        static constexpr TypeCode id = FunctionTag;

    private:
        friend class MetaFile;  // To define an access only API.

        Type* _returns{nullptr};

        uint8_t _flags{NoFlags};

        Location _location;

    public:
        Function(const String& sId, const String& name, TypeCode code);
        ~Function() override = default;

        Type* returns() const;

        uint8_t flags() const;

        Location* location();
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
