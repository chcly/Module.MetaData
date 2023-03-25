#include "MetaData/Struct.h"

namespace Rt2::MetaData
{
    Struct::Struct(const String&  sId,
                   const String&  name,
                   const TypeCode code) :
        Type(sId, name, code)
    {
    }

    Location* Struct::location()
    {
        return &_location;
    }

    ContextType* Struct::context()
    {
        return &_context;
    }
}  // namespace Rt2::MetaData
