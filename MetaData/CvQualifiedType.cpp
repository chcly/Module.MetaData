#include "MetaData/CvQualifiedType.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    CvQualifiedType::CvQualifiedType(const String&  sId,
                                     const String&  name,
                                     const TypeCode code) :
        Type(sId, name, code)
    {
    }

    bool CvQualifiedType::isConst() const
    {
        return (flags() & Const) != 0;
    }
}  // namespace Rt2::MetaData
