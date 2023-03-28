#pragma once
#include "MetaData/Declarations.h"

namespace Rt2::MetaData
{
    using ClassArray          = SimpleArray<Class*>;
    using ConstructorArray    = SimpleArray<Constructor*>;
    using ConverterArray      = SimpleArray<Converter*>;
    using DestructorArray     = SimpleArray<Destructor*>;
    using FieldArray          = SimpleArray<Field*>;
    using FileArray           = SimpleArray<File*>;
    using FunctionArray       = SimpleArray<Function*>;
    using MethodArray         = SimpleArray<Method*>;
    using NamespaceArray      = SimpleArray<Namespace*>;
    using OperatorMethodArray = SimpleArray<OperatorMethod*>;
    using StructArray         = SimpleArray<Struct*>;
    using TypeArray           = SimpleArray<Type*>;
    using TypedefArray        = SimpleArray<Typedef*>;

    template <typename T>
    struct CacheLock
    {
        SimpleArray<T*> items;
        bool            state{false};
    };

}  // namespace Rt2::MetaData
