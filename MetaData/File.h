#pragma once
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class File : public Type
    {
    public:
        File(const String& id, const String& name, TypeCode code);
    };
}  // namespace Rt2::MetaData
