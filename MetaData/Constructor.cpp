#include "MetaData/Constructor.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    Constructor::Constructor(const String& sId, const String& name, const TypeCode code) :
        Type(sId, name, code)
    {
    }

    Constructor::~Constructor() = default;

    const Location* Constructor::location() const
    {
        return &_location;
    }

    const ArgumentListType* Constructor::arguments() const
    { 
        return &_arguments;
    }

    bool Constructor::hasArguments() const
    {
        return !_arguments.empty();
    }

    uint32_t Constructor::argumentCount() const
    {
        return _arguments.size();
    }

    Argument* Constructor::argument(const uint32_t idx)
    {
        return _arguments.at(idx);
    }
}  // namespace Rt2::MetaData
