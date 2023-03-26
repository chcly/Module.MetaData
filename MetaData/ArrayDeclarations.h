#pragma once
#include "MetaData/Declarations.h"

namespace Rt2::MetaData
{

    using TypeArray           = SimpleArray<Type*>;
    using TypedefArray        = SimpleArray<Typedef*>;
    using ClassArray          = SimpleArray<Class*>;
    using StructArray         = SimpleArray<Struct*>;
    using FunctionArray       = SimpleArray<Function*>;
    using ConstructorArray    = SimpleArray<Constructor*>;
    using DestructorArray     = SimpleArray<Destructor*>;
    using FieldArray          = SimpleArray<Field*>;
    using FileArray           = SimpleArray<File*>;
    using MethodArray         = SimpleArray<Method*>;
    using NamespaceArray      = SimpleArray<Namespace*>;
    using OperatorMethodArray = SimpleArray<OperatorMethod*>;

}  // namespace Rt2::MetaData
