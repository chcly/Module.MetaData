#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/ArgumentList.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class OperatorMethod final : public Type
    {
    public:
        static constexpr TypeCode id = OperatorMethodTag;

    private:
        friend class MetaFile;  

        Type* _returns{nullptr};

        uint8_t _flags{NoFlags};

        AccessType _access{UnknownAccessTag};

        Location _location;

        ArgumentListType _arguments;

        ContextType      _context;

    public:
        OperatorMethod(const String& sId, const String& name, TypeCode code);
        ~OperatorMethod() override = default;

        AccessType access() const;

        Type* returns() const;

        uint8_t flags() const;

        Location* location();

        ArgumentListType* arguments();

        const ContextType& context() const;
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
