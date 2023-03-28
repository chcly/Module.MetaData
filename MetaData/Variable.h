#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class Variable final : public Type
    {
    public:
        static constexpr TypeCode id = VariableTag;

    private:
        friend class MetaFile;

        Type* _type{nullptr};

        AccessType _access{UnknownAccessTag};

        bool _static{false};

        Location _location;

        ContextType _context;

    public:
        Variable(const String& sId, const String& name, TypeCode code);

        ~Variable() override = default;

        AccessType access() const;

        bool isStatic() const { return _static; }

        const Location& location() const;

        const ContextType& context() const;
    };

    inline AccessType Variable::access() const
    {
        return _access;
    }

}  // namespace Rt2::MetaData
