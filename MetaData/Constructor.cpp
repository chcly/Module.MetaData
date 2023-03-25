#include "MetaData/Constructor.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    Constructor::Constructor(const String&  sId,
                             const String&  name,
                             const TypeCode code) :
        ArgumentType(sId, name, code)
    {
    }

    Constructor::~Constructor() = default;

    const Location* Constructor::location() const
    {
        return &_location;
    }
    
}  // namespace Rt2::MetaData
