#include "MetaData/Enumeration.h"

namespace Rt2::MetaData
{
    Enumeration::Enumeration(const String&  sId,
                             const String&  name,
                             const TypeCode code) :
        Type(sId, name, code)
    {
    }

    const ContextType& Enumeration::context() const
    {
        return _context;
    }
}  // namespace Rt2::MetaData
