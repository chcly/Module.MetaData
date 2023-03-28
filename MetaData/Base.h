#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class Base final : public Type
    {
    public:
        static constexpr TypeCode id = BaseTag;

    private:
        friend class MetaFile;

        ContextType _context;

    public:
        Base(const String& sId, const String& name, TypeCode code);

        ~Base() override = default;

        const ContextType& context() const;
    };

}  // namespace Rt2::MetaData
