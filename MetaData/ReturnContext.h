#pragma once
#include "MetaData/TypeExpander.h"
#include "MetaData/Type.h"

namespace Rt2::MetaData
{
    class ReturnContext final : public TypeExpander
    {
    public:
        explicit ReturnContext(Type *type);

        ~ReturnContext() override = default;

        bool isTypeOf(const String& id) const;
    };

}  // namespace Rt2::MetaData
