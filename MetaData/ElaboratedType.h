#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class ElaboratedType final : public Type
    {
    public:
        static constexpr TypeCode id = ElaboratedTypeTag;

    private:
        friend class MetaFile;

    public:
        ElaboratedType(const String& sId, const String& name, TypeCode code);

        ~ElaboratedType() override = default;
    };


}  // namespace Rt2::MetaData
