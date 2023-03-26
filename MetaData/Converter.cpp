#include "MetaData/Converter.h"

namespace Rt2::MetaData
{
    Converter::Converter(const String&  sId,
                             const String&  name,
                             const TypeCode code) :
        Type(sId, name, code)
    {
    }

    const Location* Converter::location() const
    {
        return &_location;
    }

    const ContextType& Converter::context() const
    {
        return _context;
    }

}  // namespace Rt2::MetaData
