#pragma once
#include "MetaData/ContextType.h"

namespace Rt2::MetaData
{
    class Namespace final : public Type
    {
    public:
        static constexpr TypeCode id = NamespaceTag;

    private:
        friend class MetaFile;  

        ContextType _context;

    public:
        Namespace(const String& sId, const String& name, TypeCode code);
        ~Namespace() override = default;

        const ContextType& context() const;

        bool isGlobalScope() const;
    };

}  // namespace Rt2::MetaData
