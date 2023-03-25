#include "MetaData/FunctionType.h"

namespace Rt2::MetaData
{
    FunctionType::FunctionType(const String&  sId,
                               const String&  name,
                               const TypeCode code) :
        Type(sId, name, code)
    {
    }

}  // namespace Rt2::MetaData
