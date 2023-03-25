#include "MetaData/Class.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    Class::Class(const String& sId, const String& name, const TypeCode code) :
        Type(sId, name, code)
    {
    }

    Class::~Class()
    {
        _members.clear();
    }

    Location* Class::location()
    {
        return  &_location;
    }
}  // namespace Rt2::MetaData
