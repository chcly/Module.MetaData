#pragma once
#include "Utils/Array.h"

namespace Rt2::MetaData
{
    enum TypeCode
    {
        MinTypeCode,
        ClassTag,
        FunctionTag,
        FunctionTypeTag,
        StructTag,
        ConstructorTag,
        CvQualifiedTypeTag,
        DestructorTag,
        FieldTag,
        TypedefTag,
        FundamentalTypeTag,
        FileTag,
        MethodTag,
        NamespaceTag,
        OperatorMethodTag,
        ReferenceTypeTag,
        PointerTypeTag,
        ArgumentTag,
        MaxTypeCode,

        // non xml tags
        LocationTag,

        NullCode
    };

    enum AccessType
    {
        UnknownTag,
        PublicTag,
        PrivateTag,
        ProtectedTag,
    };

    enum AtomicType
    {
        CharTag,
        IntTag,
        FloatTag,
        DoubleTag,
        VoidTag,
    };

    enum Flags
    {
        NoFlags    = 0x00,
        Inline     = 0x01,
        Extern     = 0x02,
        Artificial = 0x04,
        Explicit   = 0x08,
        Const      = 0x10,
    };

    class Type;
    class ContextType;
    class Typedef;
    class Class;
    class Struct;
    class Function;
    class FunctionType;
    class Argument;
    class Constructor;
    class CvQualifiedType;
    class Destructor;
    class Field;
    class FundamentalType;
    class File;
    class Method;
    class Namespace;
    class OperatorMethod;
    class ReferenceType;
    class PointerType;
    class Location;
    class ArgumentListType;
    class TypeListBuilder;

    using TypeArray      = SimpleArray<Type*>;

}  // namespace Rt2::MetaData
