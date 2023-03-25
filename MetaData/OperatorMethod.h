#pragma once
#include "MetaData/Argument.h"
#include "MetaData/Location.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class OperatorMethod final : public Type
    {
    public:
        static constexpr TypeCode id = OperatorMethodTag;

    private:
        friend class MetaFile;  // To define an access only API.

        Type* _returns{nullptr};

        uint8_t _flags{NoFlags};

        AccessType _access{UnknownTag};

        Location _location;

        ArgumentListType _arguments;

    public:
        OperatorMethod(const String& sId, const String& name, TypeCode code);
        ~OperatorMethod() override = default;

        AccessType access() const;

        Type* returns() const;

        uint8_t flags() const;

        Location* location();

        ArgumentListType* arguments();
    };

    inline AccessType OperatorMethod::access() const
    {
        return _access;
    }

    inline Type* OperatorMethod::returns() const
    {
        return _returns;
    }

    inline uint8_t OperatorMethod::flags() const
    {
        return _flags;
    }

}  // namespace Rt2::MetaData
