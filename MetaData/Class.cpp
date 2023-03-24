#include "MetaData/Class.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    Class::Class(const String& sId, const String& name, const TypeCode code) :
        Location(sId, name, code)
    {
    }

}  // namespace Rt2::MetaData
