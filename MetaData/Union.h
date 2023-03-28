#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class Union final : public Type
    {
    public:
        static constexpr TypeCode id = UnionTag;

    private:
        friend class MetaFile;

        AccessType _access{UnknownAccessTag};

        Location _location;

        ContextType _context;

    public:
        Union(const String& sId, const String& name, TypeCode code);

        ~Union() override = default;

        
        AccessType access() const;

        const Location& location() const;

        const ContextType& context() const;
    };

    inline AccessType Union::access() const
    {
        return _access;
    }

}  // namespace Rt2::MetaData
