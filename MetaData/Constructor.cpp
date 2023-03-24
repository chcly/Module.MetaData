#include "MetaData/Constructor.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    Constructor::Constructor(const String& sId, const String& name, const TypeCode code) :
        Location(sId, name, code)
    {
    }
}  // namespace Rt2::MetaData
