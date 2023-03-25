#include "MetaData/Field.h"

namespace Rt2::MetaData
{
    Field::Field(const String&  sId,
                 const String&  name,
                 const TypeCode code) :
        Type(sId, name, code)
    {
    }

    Location* Field::location()
    {
        return &_location;
    }

    const ContextType& Field::context() const
    {
        return _context;
    }
}  // namespace Rt2::MetaData
