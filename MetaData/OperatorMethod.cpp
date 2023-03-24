#include "MetaData/OperatorMethod.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    OperatorMethod::OperatorMethod(const String& id, const String& name, const TypeCode code) :
        Type(id, name, code)
    {
    }
}  // namespace Rt2::MetaData
