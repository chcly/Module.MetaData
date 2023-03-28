#include "MetaData/ElaboratedType.h"

namespace Rt2::MetaData
{
    ElaboratedType::ElaboratedType(const String&  sId,
                                 const String&  name,
                                 const TypeCode code) :
        Type(sId, name, code)
    {
    }

}  // namespace Rt2::MetaData
