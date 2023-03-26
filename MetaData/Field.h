#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class Field final : public Type
    {
    public:
        static constexpr TypeCode id = FieldTag;

    private:
        friend class MetaFile;  

        AccessType _access{PrivateTag};

        size_t _offset{0};

        Type* _type{nullptr};

        Location _location;

        ContextType _context;

    public:
        Field(const String& sId, const String& name, TypeCode code);
        ~Field() override = default;

        AccessType access() const;

        AtomicType atomic() const;

        size_t offset() const;

        Type* type() const;

        Location* location();

        const ContextType &context() const;
    };

    inline AccessType Field::access() const
    {
        return _access;
    }

    inline size_t Field::offset() const
    {
        return _offset;
    }

    inline Type* Field::type() const
    {
        return _type;
    }

}  // namespace Rt2::MetaData
