#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class OperatorFunction final : public Type
    {
    public:
        static constexpr TypeCode id = OperatorFunctionTag;

    private:
        friend class MetaFile;

        ContextType _context;

    public:
        OperatorFunction(const String& sId, const String& name, TypeCode code);

        ~OperatorFunction() override = default;

        const ContextType& context() const;
    };

}  // namespace Rt2::MetaData
