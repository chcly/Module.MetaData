#pragma once
#include "MetaData/ArrayDeclarations.h"
#include "MetaData/Type.h"

namespace Rt2::MetaData
{
    class ContextType
    {
    private:
        friend class MetaFile;

        TypeArray _members;

        Type* _context{nullptr};

        template <typename T>
        struct CacheLock
        {
            SimpleArray<T*> items;
            bool            state{false};
        };

        mutable CacheLock<Field> _fields;

        mutable CacheLock<Typedef> _typedefs;

    public:
        TypeCode parentType() const;

        Type* parent() const;

        const FieldArray& fields() const;

        const TypedefArray& typedefs() const;

        String name(const String& err = "<undefined>") const;
    };

}  // namespace Rt2::MetaData
