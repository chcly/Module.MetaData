#include "MetaData/ReferenceType.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    ReferenceType::ReferenceType(const String& sId, const String& name, const TypeCode code) :
        Type(sId, name, code)
    {
    }
}  // namespace Rt2::MetaData
