#include "MetaData/Class.h"

namespace Rt2::MetaData
{
    Class::Class(const String&  sId,
                 const String&  name,
                 const TypeCode code) :
        Type(sId, name, code)
    {
    }

    Location* Class::location()
    {
        return &_location;
    }

    const ContextType& Class::context() const
    {
        return _context;
    }

}  // namespace Rt2::MetaData
