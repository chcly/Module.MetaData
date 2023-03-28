#include "MetaData/Converter.h"

namespace Rt2::MetaData
{
    Converter::Converter(const String&  sId,
                         const String&  name,
                         const TypeCode code) :
        Type(sId, name, code)
    {
    }

    ReturnContext Converter::returns() const
    {
        return ReturnContext(_returns);
    }

    const Location& Converter::location() const
    {
        return _location;
    }

    const ContextType& Converter::context() const
    {
        return _context;
    }

}  // namespace Rt2::MetaData
