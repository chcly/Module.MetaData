#pragma once
#include "MetaData/ArgumentList.h"
#include "MetaData/ContextType.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class Constructor final : public Type
    {
    public:
        static constexpr TypeCode id = ConstructorTag;

    private:
        friend class MetaFile;  

        AccessType _access{UnknownAccessTag};

        uint8_t _flags{NoFlags};

        Location _location;

        ArgumentListType _arguments;

        ContextType _context;

    public:
        Constructor(const String& sId, const String& name, TypeCode code);

        ~Constructor() override = default;

        AccessType access() const;

        uint8_t flags() const;

        const Location* location() const;

        ArgumentListType* arguments();

        const ContextType& context() const;
    };

    inline AccessType Constructor::access() const
    {
        return _access;
    }

    inline uint8_t Constructor::flags() const
    {
        return _flags;
    }

}  // namespace Rt2::MetaData
