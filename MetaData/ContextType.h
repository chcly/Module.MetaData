#pragma once
#include "MetaData/Type.h"
#include "MetaData/ArrayDeclarations.h"

namespace Rt2::MetaData
{
    class ContextType
    {
    private:
        friend class MetaFile;

        TypeArray _members;

        Type* _context{nullptr};

        mutable FieldArray _fieldCache;
    public:

        TypeCode parentType() const;

        Type *parent() const;

        const FieldArray& fields() const;

        String name(const String& err = "<undefined>") const;
    };

}  // namespace Rt2::MetaData
