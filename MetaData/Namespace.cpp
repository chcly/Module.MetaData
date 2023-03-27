#include "MetaData/Namespace.h"
#include "Utils/Char.h"

namespace Rt2::MetaData
{
    Namespace::Namespace(const String&  sId,
                         const String&  name,
                         const TypeCode code) :
        Type(sId, name, code)
    {
    }

    const ContextType& Namespace::context() const
    {
        return _context;
    }

    bool Namespace::isGlobalScope() const
    {
        return Char::equals(name().c_str(), name().size(), "::", 2);
    }
}  // namespace Rt2::MetaData
