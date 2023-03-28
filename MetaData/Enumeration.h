#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class Enumeration final : public Type
    {
    public:
        static constexpr TypeCode id = EnumerationTag;

    private:
        friend class MetaFile;

        ContextType _context;

    public:
        Enumeration(const String& sId, const String& name, TypeCode code);

        ~Enumeration() override = default;

        const ContextType& context() const;
    };

}  // namespace Rt2::MetaData
