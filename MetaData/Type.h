#pragma once
#include "MetaData/Declarations.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    template <typename T>
    bool isTypeOf(TypeCode code)
    {
        return code == T::id;
    }

    class Type
    {
    private:
        friend class MetaFile;

        const String   _id{};
        const String   _name{};
        const TypeCode _code{MaxTypeCode};
        TypeArray      _children;
        Type*          _parent{nullptr};

        Type() = default;

        Type(const Type& rhs) = default;

        void addChild(Type* type);

    public:
        explicit Type(String hash, String name, TypeCode code);
        virtual ~Type();

        const TypeCode& code() const;

        const String& id() const;

        const String& name() const;

        const Type* parent() const;

        const TypeArray& children() const;

        bool hasChild(Type* type) const;

        template <typename T>
        T* cast();

        bool isTypeOf(TypeCode code) const;
    };

    template <typename T>
    T* Type::cast()
    {
        if (code() == T::id)
            return static_cast<T*>(this);
        return nullptr;
    }

    inline bool Type::isTypeOf(TypeCode code) const
    {
        return this->code() == code;
    }

    inline const TypeCode& Type::code() const
    {
        return _code;
    }

    inline const String& Type::id() const
    {
        return _id;
    }

    inline const Type* Type::parent() const
    {
        return _parent;
    }

    inline const TypeArray& Type::children() const
    {
        return _children;
    }

    inline const String& Type::name() const
    {
        return _name;
    }

}  // namespace Rt2::MetaData
