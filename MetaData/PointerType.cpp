#include "MetaData/PointerType.h"
#include "MetaData/CvQualifiedType.h"

namespace Rt2::MetaData
{
    PointerType::PointerType(const String& sId, const String& name, const TypeCode code) :
        Type(sId, name, code)
    {
    }

    bool PointerType::isConst() const
    {
        if (_type)
        {
            if (_type->isTypeOf(CvQualifiedTypeTag))
            {
                const CvQualifiedType* qt = _type->cast<CvQualifiedType>();
                return qt && qt->isConst();
            }
        }
        return false;
    }
}  // namespace Rt2::MetaData
