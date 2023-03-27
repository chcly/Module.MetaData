#include "MetaData/ContextType.h"
#include "MetaData/Field.h"
#include "MetaData/Typedef.h"

namespace Rt2::MetaData
{
    template <typename T>
    void extract(const TypeArray& all, SimpleArray<T*>& dest)
    {
        for (const auto& val : all)
        {
            if (val->isTypeOf(T::id))
                dest.push_back(static_cast<T*>(val));
        }
    }

    TypeCode ContextType::parentType() const
    {
        if (_context)
            return _context->code();
        return NullCode;
    }

    Type* ContextType::parent() const
    {
        return _context;
    }

    const FieldArray& ContextType::fields() const
    {
        if (!_fields.state)
        {
            _fields.state = true;
            extract<Field>(_members, _fields.items);
        }
        return _fields.items;
    }

    const TypedefArray& ContextType::typedefs() const
    {
        if (!_typedefs.state)
        {
            _typedefs.state = true;
            extract<Typedef>(_members, _typedefs.items);
        }
        return _typedefs.items;
    }

    String ContextType::name(const String& err) const
    {
        if (_context)
            return _context->name();
        return err;
    }
}  // namespace Rt2::MetaData
