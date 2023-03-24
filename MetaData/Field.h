#pragma once
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class Field : public Type
    {
    public:
        Field(const String& id, const String& name, TypeCode code);
    };
}  // namespace Rt2::MetaData
