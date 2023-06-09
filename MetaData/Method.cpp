#include "MetaData/Method.h"

namespace Rt2::MetaData
{
    Method::Method(const String& sId, const String& name, const TypeCode code) :
        Type(sId, name, code)
    {
    }

    Location* Method::location()
    {
        return &_location;
    }

    ArgumentListType* Method::arguments()
    {
        return &_arguments;
    }

    const ContextType& Method::context() const
    {
        return _context;
    }
}  // namespace Rt2::MetaData
