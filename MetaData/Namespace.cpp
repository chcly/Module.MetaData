#include "MetaData/Namespace.h"

namespace Rt2::MetaData
{
    Namespace::Namespace(const String&  sId,
                         const String&  name,
                         const TypeCode code) :
        Type(sId, name, code)
    {
    }

    ContextType* Namespace::context()
    {
        return &_context;
    }
}  // namespace Rt2::MetaData
