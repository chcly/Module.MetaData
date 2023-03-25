#include "MetaData/Field.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    Field::Field(const String& sId, const String& name, const TypeCode code) :
        Type(sId, name, code)
    {
    }

    Location* Field::location()
    {
        return &_location;
    }
}  // namespace Rt2::MetaData
