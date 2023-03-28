#include "MetaData/Argument.h"
#include "MetaData/Typedef.h"

namespace Rt2::MetaData
{
    Argument::Argument() = default;

    TypeExpander Argument::type() const
    {
        return TypeExpander(_type);
    }

    const Location& Argument::location() const
    {
        return _location;
    }

    bool Argument::isReference() const
    {
        return type().find(ReferenceTypeTag);
    }

    bool Argument::isConst() const
    {
        return type().find(CvQualifiedTypeTag);
    }

    bool Argument::isPointer() const
    {
        return type().find(PointerTypeTag);
    }

    bool Argument::isFunctionPointer() const
    {
        return isPointer() && type().find(FunctionTypeTag);
    }
}  // namespace Rt2::MetaData
