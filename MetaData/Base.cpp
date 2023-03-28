#include "MetaData/Base.h"

namespace Rt2::MetaData
{
    Base::Base(const String&  sId,
                                 const String&  name,
                                 const TypeCode code) :
        Type(sId, name, code)
    {
    }

    const ContextType& Base::context() const
    {
        return _context;
    }
}  // namespace Rt2::MetaData
