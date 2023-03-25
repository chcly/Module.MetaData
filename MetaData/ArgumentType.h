#pragma once
#include "MetaData/Argument.h"
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class ArgumentType : public Type
    {
    private:
        friend class MetaFile;  // To define an access only API.

        ArgumentListType _arguments;

    public:
        ArgumentType(const String& sId, const String& name, TypeCode code);

        const ArgumentListType* arguments() const;

        bool hasArguments() const;

        uint32_t argumentCount() const;

        Argument* argument(uint32_t idx);
    };

}  // namespace Rt2::MetaData
