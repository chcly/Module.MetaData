#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/Location.h"
#include "ReturnContext.h"

namespace Rt2::MetaData
{
    class Converter final : public Type
    {
    public:
        static constexpr TypeCode id = ConverterTag;

    private:
        friend class MetaFile;

        Type* _returns{nullptr};

        AccessType _access{UnknownAccessTag};

        uint8_t _flags{NoFlags};

        Location _location;

        ContextType _context;

    public:
        Converter(const String& sId, const String& name, TypeCode code);

        ~Converter() override = default;

        Type* _returns_() const;

        ReturnContext returns() const;

        AccessType access() const;

        uint8_t flags() const;

        const Location& location() const;

        const ContextType& context() const;
    };

    inline Type* Converter::_returns_() const
    {
        return _returns;
    }

    inline AccessType Converter::access() const
    {
        return _access;
    }

    inline uint8_t Converter::flags() const
    {
        return _flags;
    }
}  // namespace Rt2::MetaData
