#pragma once
#include "MetaData/Location.h"

namespace Rt2::MetaData
{

    using ArgumentQueue = std::deque<Type*>;

    class Argument
    {
    private:
        friend class MetaFile;

        Type*    _type{nullptr};
        String   _name;
        Location _location;

        Type* search(const int code) const;

    public:
        Argument();
        ~Argument() = default;

        Type* type() const;

        Location* location();

        const String& name() const;

        bool isReference() const;

        bool isConst() const;

        bool isPointer() const;

        bool isFunctionPointer() const;

        void expand(ArgumentQueue& dest) const;
    };

    inline Type* Argument::type() const
    {
        return _type;
    }

    inline const String& Argument::name() const
    {
        return _name;
    }

}  // namespace Rt2::MetaData
