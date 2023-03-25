#include "MetaData/Destructor.h"

namespace Rt2::MetaData
{
    Destructor::Destructor(const String&  sId,
                           const String&  name,
                           const TypeCode code) :
        Type(sId, name, code)
    {
    }

    Location* Destructor::location()
    {
        return &_location;
    }

    ContextType* Destructor::context()
    {
        return &_context;
    }
}  // namespace Rt2::MetaData
