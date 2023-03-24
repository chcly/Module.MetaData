#pragma once
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class Method : public Type
    {
    public:
        Method(const String& id, const String& name, TypeCode code);
    };
}  // namespace Rt2::MetaData
