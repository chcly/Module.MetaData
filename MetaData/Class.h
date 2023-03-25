#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class Class final : public Type
    {
    public:
        static constexpr TypeCode id = ClassTag;

    private:
        friend class MetaFile;

        size_t _sizeInBytes{0};

        size_t _align{0};

        Location _location;

        ContextType _context;

    public:
        Class(const String& sId, const String& name, TypeCode code);
        ~Class() override = default;

        size_t sizeInBytes() const;

        size_t alignment() const;

        Location* location();

        const ContextType& context() const;
    };

    inline size_t Class::sizeInBytes() const
    {
        return _sizeInBytes;
    }

    inline size_t Class::alignment() const
    {
        return _align;
    }

}  // namespace Rt2::MetaData
