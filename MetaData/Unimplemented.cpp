#include "MetaData/Unimplemented.h"

namespace Rt2::MetaData
{
    Unimplemented::Unimplemented(const String&  sId,
                                 const String&  name,
                                 const TypeCode code) :
        Type(sId, name, code)
    {
    }

}  // namespace Rt2::MetaData
