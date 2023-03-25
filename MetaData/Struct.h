#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class Struct final : public Type
    {
    public:
        static constexpr TypeCode id = StructTag;

    private:
        friend class MetaFile;  

        size_t _sizeInBytes{0};
        size_t _align{0};

        TypeArray _members;

        Location _location;

        ContextType _context;

    public:
        Struct(const String& sId, const String& name, TypeCode code);
        ~Struct() override = default;

        size_t sizeInBytes() const;

        size_t alignment() const;

        const TypeArray& members() const;

        Location* location();

        ContextType* context();
    };

    inline size_t Struct::sizeInBytes() const
    {
        return _sizeInBytes;
    }

    inline size_t Struct::alignment() const
    {
        return _align;
    }

    inline const TypeArray& Struct::members() const
    {
        return _members;
    }

}  // namespace Rt2::MetaData
