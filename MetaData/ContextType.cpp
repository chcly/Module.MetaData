#include "MetaData/ContextType.h"

namespace Rt2::MetaData
{
    TypeCode ContextType::type() const
    {
        if (_context)
            return _context->code();
        return NullCode;
    }

}  // namespace Rt2::MetaData
