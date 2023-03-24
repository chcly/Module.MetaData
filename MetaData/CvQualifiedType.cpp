#include "MetaData/CvQualifiedType.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    CvQualifiedType::CvQualifiedType(const String& sId, const String& name, const TypeCode code) :
        Type(sId, name, code)
    {
    }
}  // namespace Rt2::MetaData
