#include "MetaData/ContextType.h"
#include "MetaData/Field.h"
#include "MetaData/Typedef.h"
#include "MetaData/Class.h"
#include "MetaData/Converter.h"

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

    template <typename T>
    const SimpleArray<T*>& tryGet(CacheLock<T> & cache, const TypeArray& all)
    {
        if (!cache.state)
        {
            cache.state = true;
            extract<T>(all, cache.items);
        }
        return cache.items;
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
        return tryGet<Field>(_fields, _members);
    }

    const TypedefArray& ContextType::typedefs() const
    {
        return tryGet<Typedef>(_typedefs, _members);
    }

    const ClassArray& ContextType::classes() const
    {
        return tryGet<Class>(_classes, _members);
    }

    const ConverterArray& ContextType::converters() const
    {
        return tryGet<Converter>(_converters, _members);
    }

    String ContextType::name(const String& err) const
    {
        if (_context)
            return _context->name();
        return err;
    }
}  // namespace Rt2::MetaData
