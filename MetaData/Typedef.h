#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class Typedef final : public Type
    {
    public:
        static constexpr TypeCode id = TypedefTag;

    private:
        friend class MetaFile;  

        Type* _type{nullptr};
        
        Location _location;

        ContextType _context;

    public:
        Typedef(const String& sId, const String& name, TypeCode code);
        ~Typedef() override = default;

        Type* type() const;

        const ContextType& context() const;
    };

    inline Type* Typedef::type() const
    {
        return _type;
    }

}  // namespace Rt2::MetaData
