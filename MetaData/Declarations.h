#pragma once
#include "Utils/Array.h"

namespace Rt2::MetaData
{
    enum TypeCode
    {
        NullCode = -1,
        MinTypeCode,
        ArgumentTag,
        ArrayTypeTag,
        BaseTag,
        ClassTag,
        ConstructorTag,
        ConverterTag,
        CvQualifiedTypeTag,
        DestructorTag,
        ElaboratedTypeTag,
        EnumerationTag,
        FieldTag,
        FileTag,
        FunctionTag,
        FunctionTypeTag,
        FundamentalTypeTag,
        MethodTag,
        NamespaceTag,
        OperatorFunctionTag,
        OperatorMethodTag,
        PointerTypeTag,
        ReferenceTypeTag,
        StructTag,
        TypedefTag,
        UnimplementedTag,
        UnionTag,
        VariableTag,
        MaxTypeCode,

        // non xml tags
        LocationTag,
    };

    enum AccessType
    {
        UnknownAccessTag = MinTypeCode,
        PublicTag,
        PrivateTag,
        ProtectedTag,
    };

    enum AtomicType
    {
        AtomicUnknown = NullCode,
        I8Tag,
        I16Tag,
        I32Tag,
        I64Tag,
        U8Tag,
        U16Tag,
        U32Tag,
        U64Tag,
        R32Tag,
        R64Tag,
        UserTypeTag,
        VoidTag,
        CharTag,
    };

    enum DeclFlag
    {
        RefDecl         = 0x01,
        PtrDecl         = 0x02,
        PtrPtrDecl      = 0x04,
        ConstDecl       = 0x08,
        FunctionPtrDecl = 0x10,
        MemberPtrDecl   = 0x20,
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

    class Argument;
    class ArgumentListType;
    class ArrayType;
    class Base;
    class Class;
    class Constructor;
    class ContextType;
    class Converter;
    class CvQualifiedType;
    class Destructor;
    class ElaboratedType;
    class Enumeration;
    class Field;
    class File;
    class Function;
    class FunctionType;
    class FundamentalType;
    class Location;
    class Method;
    class Namespace;
    class OperatorFunction;
    class OperatorMethod;
    class PointerType;
    class ReferenceType;
    class Struct;
    class Type;
    class Typedef;
    class TypeListBuilder;
    class Unimplemented;
    class Union;
    class Variable;

    using TypeArray = SimpleArray<Type*>;

}  // namespace Rt2::MetaData
