#include "MetaData/OperatorFunction.h"

namespace Rt2::MetaData
{
    OperatorFunction::OperatorFunction(const String&  sId,
                                       const String&  name,
                                       const TypeCode code) :
        Type(sId, name, code)
    {
    }

    const ContextType& OperatorFunction::context() const
    {
        return _context;
    }
}  // namespace Rt2::MetaData
