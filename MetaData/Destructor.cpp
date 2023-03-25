#include "MetaData/Destructor.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    Destructor::Destructor(const String& sId, const String& name, const TypeCode code) :
        Type(sId, name, code)
    {
    }

    Location* Destructor::location()
    {
        return  &_location;
    }
}  // namespace Rt2::MetaData
