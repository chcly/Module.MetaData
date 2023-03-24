#pragma once
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class Constructor : public Type
    {
    public:
        Constructor(const String& id, const String& name, TypeCode code);
    };
}  // namespace Rt2::MetaData
