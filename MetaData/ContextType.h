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

        mutable CacheLock<Field> _fields;

        mutable CacheLock<Typedef> _typedefs;

        mutable CacheLock<Class> _classes;

        mutable CacheLock<Converter> _converters;

        mutable CacheLock<Constructor> _constructors;

    public:
        TypeCode parentType() const;

        Type* parent() const;

        const FieldArray& fields() const;

        const TypedefArray& typedefs() const;

        const ClassArray& classes() const;

        const ConverterArray& converters() const;

        const ConstructorArray& constructors() const;

        String name(const String& err = "<undefined>") const;
    };

}  // namespace Rt2::MetaData
