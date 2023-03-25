#pragma once
#include "MetaData/Type.h"
#include "Utils/HashMap.h"
#include "Utils/String.h"

namespace Rt2::Xml
{
    class Node;
}

namespace Rt2::MetaData
{

    class MetaFile
    {
    public:
        using Types = std::unordered_map<String, Type*>;

    private:
        Types          _types{};
        FileArray      _files;
        String         _format{};
        NamespaceArray _namespaces;

    public:
        MetaFile() = default;
        ~MetaFile();

        void load(IStream& stream);

        String format() const;

        Type* find(const String& id);

        Type* find(const String& id, TypeCode type);

        template<typename  T>
        T* find(const String& id);

        const FileArray& files() const;

        const NamespaceArray& namespaces() const;

    private:
        void clear();

        void createType(const Xml::Node* node);

        void mergeMembers(TypeArray& dest, const Xml::Node* node);

        void linkArgument(ArgumentListType* obj, const Xml::Node* node);

        void linkArgumentList(ArgumentListType* obj, const Xml::Node* node);

        void linkLocation(Location* obj, const Xml::Node* node);

        void link(Type* obj, const Xml::Node* node);

        void link(Namespace* obj, const Xml::Node* node);

        void link(Class* obj, const Xml::Node* node);

        void link(Function* obj, const Xml::Node* node);

        void link(Struct* obj, const Xml::Node* node);

        void link(Field* obj, const Xml::Node* node);

        void link(Constructor* obj, const Xml::Node* node);

        void link(Destructor* obj, const Xml::Node* node);

        void link(Method* obj, const Xml::Node* node);

        void link(OperatorMethod* obj, const Xml::Node* node);

        void link(FundamentalType* obj, const Xml::Node* node);

        void link(ReferenceType* obj, const Xml::Node* node);

        void link(PointerType* obj, const Xml::Node* node);

        void link(CvQualifiedType* obj, const Xml::Node* node);

        void link(File* obj, const Xml::Node* node);

        void linkType(const Xml::Node* node);

        void loadImpl(const Xml::Node* node);

        static Type* create(const String& strId, const String& name, TypeCode id);
    };

    template <typename T>
    T* MetaFile::find(const String& id)
    {
        return (T*)find(id, T::id);
    }

    inline String MetaFile::format() const
    {
        return _format;
    }

    inline const FileArray& MetaFile::files() const
    {
        return _files;
    }

    inline const NamespaceArray& MetaFile::namespaces() const
    {
        return _namespaces;
    }

}  // namespace Rt2::MetaData
