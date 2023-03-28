#include "MetaData/ArrayType.h"

namespace Rt2::MetaData
{
    ArrayType::ArrayType(const String&  sId,
                                 const String&  name,
                                 const TypeCode code) :
        Type(sId, name, code)
    {
    }

}  // namespace Rt2::MetaData
