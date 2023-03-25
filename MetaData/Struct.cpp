#include "MetaData/Struct.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    Struct::Struct(const String& sId, const String& name, const TypeCode code) :
        Type(sId, name, code)
    {
    }

    Location* Struct::location()
    {
        return &_location;
    }
}  // namespace Rt2::MetaData
