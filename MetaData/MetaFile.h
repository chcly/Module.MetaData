#pragma once
#include "MetaData/Type.h"
#include "Utils/HashMap.h"

namespace Rt2::Xml
{
    class Node;
}

namespace Rt2::MetaData
{

    class MetaFile
    {
    public:
        using Types = HashTable<String, Type*>;

    private:
        friend class TypeListBuilder;

        Types  _types{};
        String _format{};
        
    template<typename T>
    static ContextType* context(Type *type);

    public:
        MetaFile() = default;
        ~MetaFile();

        void load(IStream& stream);

        String format() const;

        Type* find(const String& id);

        Type* find(const String& id, TypeCode type);

        template <typename T>
        T* find(const String& id);

        TypeListBuilder list();

    private:
        Type* assert_find(const String& id);

        ContextType* context_find(const String& id);

        void clear();

        void createType(const Xml::Node* node);

        void mergeMembers(ContextType* dest, const Xml::Node* node);

        void linkArgument(ArgumentListType* obj, const Xml::Node* node);

        void linkArgumentList(ArgumentListType* obj, const Xml::Node* node);

        void linkLocation(Location* obj, const Xml::Node* node);

        void link(const Type* obj, const Xml::Node* node);

        void link(Typedef* obj, const Xml::Node* node);

        void link(Namespace* obj, const Xml::Node* node);

        void link(Class* obj, const Xml::Node* node);

        void link(Function* obj, const Xml::Node* node);

        void link(FunctionType* obj, const Xml::Node* node);

        void link(Struct* obj, const Xml::Node* node);

        void link(Field* obj, const Xml::Node* node);

        void link(Union* obj, const Xml::Node* node);

        void link(Constructor* obj, const Xml::Node* node);

        void link(Converter* obj, const Xml::Node* node);

        void link(Destructor* obj, const Xml::Node* node);

        void link(Method* obj, const Xml::Node* node);

        void link(OperatorMethod* obj, const Xml::Node* node);

        void link(FundamentalType* obj, const Xml::Node* node);

        void link(ReferenceType* obj, const Xml::Node* node);

        void link(PointerType* obj, const Xml::Node* node);

        void link(CvQualifiedType* obj, const Xml::Node* node);
        
        void linkType(const Xml::Node* node);

        void loadImpl(const Xml::Node* node);

        static Type* create(const String& strId, const String& name, TypeCode id);
    };

    template <typename T>
    ContextType* MetaFile::context(Type* type)
    {
        return &type->assert_cast<T>()->_context;
    }

    template <typename T>
    T* MetaFile::find(const String& id)
    {
        return (T*)find(id, T::id);
    }

    inline String MetaFile::format() const
    {
        return _format;
    }

}  // namespace Rt2::MetaData
