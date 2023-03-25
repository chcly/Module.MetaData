#pragma once
#include "MetaData/Type.h"

namespace Rt2::MetaData
{
    class FunctionType final : public Type
    {
    public:
        static constexpr TypeCode id = FunctionTypeTag;

    private:
        friend class MetaFile;  

        Type* _returns{nullptr};

    public:
        FunctionType(const String& sId, const String& name, TypeCode code);
        ~FunctionType() override = default;

        Type* returns() const;
    };
    
    inline Type* FunctionType::returns() const
    {
        return _returns;
    }

}  // namespace Rt2::MetaData
