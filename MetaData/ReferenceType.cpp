#include "MetaData/ReferenceType.h"
#include "CvQualifiedType.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    ReferenceType::ReferenceType(const String& sId, const String& name, const TypeCode code) :
        Type(sId, name, code)
    {
    }

    bool ReferenceType::isConst() const
    {
        if (_type)
        {
            if (_type->isTypeOf(CvQualifiedTypeTag))
            {
                const CvQualifiedType* qt = _type->cast<CvQualifiedType>();
                return qt && (qt->flags() & Const) != 0;
            }
        }
        return false;
    }
}  // namespace Rt2::MetaData
