#pragma once
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class CvQualifiedType : public Type
    {
    public:
        CvQualifiedType(const String& id, const String& name, TypeCode code);
    };
}  // namespace Rt2::MetaData
