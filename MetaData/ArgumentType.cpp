#include "MetaData/ArgumentType.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    ArgumentType::ArgumentType(const String&  sId,
                               const String&  name,
                               const TypeCode code) :
        Type(sId, name, code)
    {
    }

    const ArgumentListType* ArgumentType::arguments() const
    {
        return &_arguments;
    }

    bool ArgumentType::hasArguments() const
    {
        return !_arguments.empty();
    }

    uint32_t ArgumentType::argumentCount() const
    {
        return _arguments.size();
    }

    Argument* ArgumentType::argument(const uint32_t idx)
    {
        return _arguments.at(idx);
    }
}  // namespace Rt2::MetaData
