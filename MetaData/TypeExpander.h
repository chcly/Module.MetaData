#pragma once
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    // setting an upper bound, the xml structure
    // has the potential to be circularly linked.
    constexpr size_t MaxExpansion = 10;

    class TypeExpander
    {
    private:
        Type* _type{nullptr};

    protected:
        using Visitor = std::function<bool(Type*)>;

        void expandImpl(const Visitor& method, size_t max = MaxExpansion) const;

        void expand(const Visitor& method, size_t max = MaxExpansion) const;

        Type* search(int code) const;

        Type* search(const String& id) const;

        template <typename T>
        T* find()
        {
            if (Type* type = search(T::id))
                return type->cast<T>();
            return nullptr;
        }

    public:
        explicit TypeExpander(Type* type);
        virtual ~TypeExpander() = default;

        void expand(TypeArray& dest, size_t max = MaxExpansion) const;

        bool find(int code) const;

        bool isTypeOf(const String& id) const;

        const Type* find(const String& id) const;

        FundamentalType* fundamentalType();

        const Class* classType(const String& id) const;

        const Class* classType();
    };

}  // namespace Rt2::MetaData
