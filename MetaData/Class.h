#pragma once
#include "MetaData/Location.h"
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class Class final : public Type
    {
    public:
        static constexpr TypeCode id = ClassTag;

    private:
        friend class MetaFile;  // To define an access only API.

        size_t _sizeInBytes{0};

        size_t _align{0};

        TypeArray _members;

        Location  _location;

    public:
        Class(const String& sId, const String& name, TypeCode code);
        ~Class() override;

        size_t sizeInBytes() const;

        size_t alignment() const;

        const TypeArray& members() const;

        Location* location();


    };

    inline size_t Class::sizeInBytes() const
    {
        return _sizeInBytes;
    }

    inline size_t Class::alignment() const
    {
        return _align;
    }

    inline const TypeArray& Class::members() const
    {
        return _members;
    }

}  // namespace Rt2::MetaData
