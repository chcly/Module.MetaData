#include "MetaData/Namespace.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    Namespace::Namespace(const String& sId, const String& name, const TypeCode code) :
        Type(sId, name, code)
    {
    }

}  // namespace Rt2::MetaData
