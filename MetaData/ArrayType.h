#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class ArrayType final : public Type
    {
    public:
        static constexpr TypeCode id = ArrayTypeTag;

    private:
        friend class MetaFile;

    public:
        ArrayType(const String& sId, const String& name, TypeCode code);

        ~ArrayType() override = default;
    };


}  // namespace Rt2::MetaData
