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

        void expand(const Visitor& method, size_t max = MaxExpansion) const;

        Type* search(int code) const;

    public:
        explicit TypeExpander(Type* type);
        virtual ~TypeExpander() = default;

        void expand(TypeArray& dest, size_t max = MaxExpansion) const;
    };

}  // namespace Rt2::MetaData
