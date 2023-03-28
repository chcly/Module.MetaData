#include "MetaData/Variable.h"

namespace Rt2::MetaData
{
    Variable::Variable(const String&  sId,
                       const String&  name,
                       const TypeCode code) :
        Type(sId, name, code)
    {
    }

    const Location& Variable::location() const
    {
        return _location;
    }

    const ContextType& Variable::context() const
    {
        return _context;
    }

}  // namespace Rt2::MetaData
