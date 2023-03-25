#pragma once
#include "Utils/Array.h"

namespace Rt2::MetaData
{
    enum TypeCode
    {
        MinTypeCode,
        ClassTag,
        FunctionTag,
        StructTag,
        ConstructorTag,
        CvQualifiedTypeTag,
        DestructorTag,
        FieldTag,
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
    class Class;
    class Struct;
    class Function;
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

    using TypeArray      = SimpleArray<Type*>;
    using FileArray      = SimpleArray<File*>;
    using NamespaceArray = SimpleArray<Namespace*>;
    using ArgumentList   = SimpleArray<Argument*>;

}  // namespace Rt2::MetaData
