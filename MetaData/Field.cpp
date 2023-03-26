#include "MetaData/Field.h"
#include "MetaData/FundamentalType.h"

namespace Rt2::MetaData
{
    Field::Field(const String&  sId,
                 const String&  name,
                 const TypeCode code) :
        Type(sId, name, code)
    {
    }

    AtomicType Field::atomic() const
    {
        if (_type && _type->isTypeOf(FundamentalTypeTag))
            return _type->cast<FundamentalType>()->type();
        return AtomicUnknown;
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
