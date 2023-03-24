#pragma once
#include "Utils/Array.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    enum TypeCode
    {
        MinTypeCode,
        ClassTag,
        ConstructorTag,
        CvQualifiedTypeTag,
        DestructorTag,
        FieldTag,
        FundamentalTypeTag,
        FileTag,
        MethodTag,
        NamespaceTag,
        OperatorMethodTag,
        ReferenceTypeTag,
        PointerTypeTag,
        MaxTypeCode,
    };
    using TypeArray = SimpleArray<class Type*>;

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
        explicit Type(String id, String name, TypeCode code);

        const TypeCode& type() const;

        const String& id() const;

        const Type* parent() const;

        const TypeArray& children() const;

        template <typename T>
        T* cast();
    };

    template <typename T>
    bool isTypeOf(TypeCode code)
    {
        return code == T::id;
    }

    template <typename T>
    T* Type::cast()
    {
        if (type() == T::id)
            return static_cast<T*>(this);
        return nullptr;
    }

    inline const TypeCode& Type::type() const
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

}  // namespace Rt2::MetaData
