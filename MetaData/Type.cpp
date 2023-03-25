#include "MetaData/Type.h"

namespace Rt2::MetaData
{
    Type::Type(String hash, String name, const TypeCode code) :
        _id(std::move(hash)),
        _name(std::move(name)),
        _code(code)
    {
    }

}  // namespace Rt2::MetaData
