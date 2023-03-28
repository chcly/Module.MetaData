#include "MetaData/ReturnContext.h"
#include "MetaData/Type.h"

namespace Rt2::MetaData
{
    ReturnContext::ReturnContext(Type* type) :
        TypeExpander(type)
    {
    }

    bool ReturnContext::isTypeOf(const String& id) const
    {
        bool result = false;
        expand(
            [&result, id](const Type* type)
            {
                if (type->name() == id)
                {
                    result = true;
                    return true;
                }
                return false;
            });
        return result;
    }

}  // namespace Rt2::MetaData
