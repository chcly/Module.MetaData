#include "MetaData/Function.h"

namespace Rt2::MetaData
{
    Function::Function(const String&  sId,
                       const String&  name,
                       const TypeCode code) :
        Type(sId, name, code)
    {
    }

    Location* Function::location()
    {
        return &_location;
    }

    ArgumentListType* Function::arguments()
    {
        return &_arguments;
    }

    ContextType* Function::context()
    {
        return &_context;
    }
}  // namespace Rt2::MetaData
