#include "MetaData/FundamentalType.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    FundamentalType::FundamentalType(const String& sId, const String& name, const TypeCode code) :
        Type(sId, name, code)
    {
    }
}  // namespace Rt2::MetaData
