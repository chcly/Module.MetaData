#include "MetaData/Union.h"

namespace Rt2::MetaData
{
    Union::Union(const String&  sId,
                         const String&  name,
                         const TypeCode code) :
        Type(sId, name, code)
    {
    }

    const Location& Union::location() const
    {
        return _location;
    }

    const ContextType& Union::context() const
    {
        return _context;
    }

}  // namespace Rt2::MetaData
