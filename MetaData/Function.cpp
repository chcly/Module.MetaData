#include "MetaData/Function.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    Function::Function(const String&  sId,
                       const String&  name,
                       const TypeCode code) :
        ArgumentType(sId, name, code)
    {
    }

    Location* Function::location()
    {
        return &_location;
    }
}  // namespace Rt2::MetaData
