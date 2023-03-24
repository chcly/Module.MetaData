#pragma once
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class Namespace : public Type
    {
    public:
        static constexpr TypeCode id = NamespaceTag;

    private:
        // To define an access only API.
        friend class MetaFile;

        TypeArray _members;

    public:
        Namespace(const String& id, const String& name, TypeCode code);

        const TypeArray& members() const;
    };

    inline const TypeArray& Namespace::members() const
    {
        return _members;
    }

}  // namespace Rt2::MetaData
