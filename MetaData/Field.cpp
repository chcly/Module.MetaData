#include "MetaData/Field.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    Field::Field(const String& sId, const String& name, const TypeCode code) :
        Location(sId, name, code)
    {
    }

}  // namespace Rt2::MetaData
