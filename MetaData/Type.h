#pragma once
#include "MetaData/Declarations.h"


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

        Type() = default;

        Type(const Type& rhs) = default;

    public:
        explicit Type(String hash, String name, TypeCode code);
        virtual ~Type() = default;

        const TypeCode& code() const;

        const String& id() const;

        const String& name() const;

        template <typename T>
        T* cast();

        template <typename T>
        const T* cast() const;

        template <typename T>
        T* assert_cast();

        bool isTypeOf(TypeCode code) const;
    };

    template <typename T>
    T* Type::cast()
    {
        if (code() == T::id)
            return static_cast<T*>(this);
        return nullptr;
    }

    template <typename T>
    const T* Type::cast() const
    {
        if (code() == T::id)
            return static_cast<const T*>(this);
        return nullptr;
    }

    template <typename T>
    T* Type::assert_cast()
    {
        if (code() == T::id)
            return static_cast<T*>(this);
        throw Exception("bad cast");
    }

    inline bool Type::isTypeOf(const TypeCode code) const
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

    inline const String& Type::name() const
    {
        return _name;
    }

}  // namespace Rt2::MetaData
