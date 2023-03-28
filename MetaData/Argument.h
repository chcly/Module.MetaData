#pragma once
#include "MetaData/Location.h"
#include "MetaData/TypeExpander.h"

namespace Rt2::MetaData
{
    class Argument final
    {
    private:
        friend class MetaFile;

        Type* _type{nullptr};

        String _name;

        Location _location;

    public:
        Argument();
        ~Argument() = default;

        TypeExpander type() const;

        const Location& location() const;

        const String& name() const;

        bool isReference() const;

        bool isConst() const;

        bool isPointer() const;

        bool isFunctionPointer() const;
    };

    inline const String& Argument::name() const
    {
        return _name;
    }

}  // namespace Rt2::MetaData
