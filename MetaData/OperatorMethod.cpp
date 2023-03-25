#include "MetaData/OperatorMethod.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    OperatorMethod::OperatorMethod(const String& sId, const String& name, const TypeCode code) :
        Type(sId, name, code)
    {
    }

    Location* OperatorMethod::location()
    {
        return &_location;
    }

    ArgumentListType* OperatorMethod::arguments()
    {
        return &_arguments;
    }
}  // namespace Rt2::MetaData
