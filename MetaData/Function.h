#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/ArgumentList.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class Function final : public Type
    {
    public:
        static constexpr TypeCode id = FunctionTag;

    private:
        friend class MetaFile;  

        Type* _returns{nullptr};

        uint8_t _flags{NoFlags};

        Location _location;

        ArgumentListType _arguments;

        ContextType _context;

    public:
        Function(const String& sId, const String& name, TypeCode code);
        ~Function() override = default;

        Type* returns() const;

        uint8_t flags() const;

        Location* location();

        ArgumentListType* arguments();

        ContextType* context();
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
