#pragma once
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class Namespace final : public Type
    {
    public:
        static constexpr TypeCode id = NamespaceTag;

    private:
        friend class MetaFile;  // To define an access only API.

        TypeArray _members;

    public:
        Namespace(const String& sId, const String& name, TypeCode code);
        ~Namespace() override = default;

        const TypeArray& members() const;
    };

    inline const TypeArray& Namespace::members() const
    {
        return _members;
    }

}  // namespace Rt2::MetaData
