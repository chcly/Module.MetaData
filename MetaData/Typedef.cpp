#include "MetaData/Typedef.h"

namespace Rt2::MetaData
{
    Typedef::Typedef(const String&  sId,
                     const String&  name,
                     const TypeCode code) :
        Type(sId, name, code)
    {
    }

    ContextType* Typedef::context()
    {
        return &_context;
    }
}  // namespace Rt2::MetaData
