#pragma once
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class Argument
    {
    private:
        friend class MetaFile;  // To define an access only API.

        Type*  _type{nullptr};


        String _name;

        Location _location;

    public:
        Argument();
        ~Argument() = default;

        Type* type() const;

        Location* location();

        const String& name() const;

        bool isReference() const;

        bool isConst() const;

        bool isPointer() const;
    };

    inline Type* Argument::type() const
    {
        return _type;
    }

    inline const String& Argument::name() const
    {
        return _name;
    }

    class ArgumentListType
    {
    private:
        friend class MetaFile;  // To define an access only API.

        ArgumentList _arguments;

        Argument* create();

    public:
        ArgumentListType() = default;
        ~ArgumentListType();

        const ArgumentList& list() const;

        uint32_t size() const;

        Argument *at(uint32_t idx);

        bool empty() const;
    };

}  // namespace Rt2::MetaData
