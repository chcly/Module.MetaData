#include "MetaData/Constructor.h"

namespace Rt2::MetaData
{
    Constructor::Constructor(const String&  sId,
                             const String&  name,
                             const TypeCode code) :
        Type(sId, name, code)
    {
    }

    const Location* Constructor::location() const
    {
        return &_location;
    }

    ArgumentListType* Constructor::arguments()
    {
        return &_arguments;
    }

    ContextType* Constructor::context()
    {
        return &_context;
    }

}  // namespace Rt2::MetaData
