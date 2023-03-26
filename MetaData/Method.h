#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/ArgumentList.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class Method final : public Type
    {
    public:
        static constexpr TypeCode id = MethodTag;

    private:
        friend class MetaFile;  

        Type* _returns{nullptr};

        uint8_t _flags{NoFlags};

        AccessType _access{UnknownAccessTag};

        Location _location;

        ArgumentListType _arguments;

        ContextType _context;

    public:
        Method(const String& sId, const String& name, TypeCode code);
        ~Method() override = default;

        AccessType access() const;

        Type* returns() const;

        uint8_t flags() const;

        Location* location();

        ArgumentListType* arguments();

        const ContextType& context() const;
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
