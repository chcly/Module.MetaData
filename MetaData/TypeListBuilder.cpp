#include "MetaData/TypeListBuilder.h"
#include "MetaData/Namespace.h"
#include "MetaData/Class.h"
#include "MetaData/Struct.h"
#include "MetaData/Function.h"
#include "MetaData/Typedef.h"
#include "MetaData/File.h"

namespace Rt2::MetaData
{
    template <typename T>
    void extract(const MetaFile::Types& all, SimpleArray<T*>& dest)
    {
        for (auto& val : all)
        {
            if (val.second->isTypeOf(T::id))
                dest.push_back(static_cast<T*>(val.second));
        }
    }

    TypeListBuilder::TypeListBuilder(MetaFile* file) :
        _fp(file)
    {
    }

    void TypeListBuilder::namespaces(NamespaceArray& dest) const
    {
        if (_fp)
            extract<Namespace>(_fp->_types, dest);
    }

    void TypeListBuilder::classes(ClassArray& dest) const
    {
        if (_fp)
            extract<Class>(_fp->_types, dest);
    }

    void TypeListBuilder::structures(StructArray& dest) const
    {
        if (_fp)
            extract<Struct>(_fp->_types, dest);
    }

    void TypeListBuilder::functions(FunctionArray& dest) const
    {
        if (_fp)
            extract<Function>(_fp->_types, dest);
    }

    void TypeListBuilder::typedefs(TypedefArray& dest) const
    {
        if (_fp)
            extract<Typedef>(_fp->_types, dest);
    }

    void TypeListBuilder::files(FileArray& dest) const
    {
        if (_fp)
            extract<File>(_fp->_types, dest);
    }
}  // namespace Rt2::MetaData
