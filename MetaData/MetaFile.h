#pragma once
#include "MetaData/Type.h"
#include "Namespace.h"
#include "Utils/Array.h"
#include "Utils/HashMap.h"
#include "Utils/String.h"
#include "Xml/Node.h"

namespace Rt2::MetaData
{
    class MetaFile
    {
    public:
        using Types     = HashTable<String, Type*>;
        using TypeArray = SimpleArray<Type*>;

    private:
        Types  _types{};
        String _format{};

    public:
        MetaFile() = default;
        ~MetaFile();

        void load(IStream& stream);

        String format() const;

        Type* find(const String& id);

    private:
        void clear();

        void createType(const Xml::Node* node);

        void linkContext(Type* obj, const Xml::Node* node);

        void linkNamespace(Namespace* obj, const Xml::Node* node);

        void linkClass(Namespace* obj, const Xml::Node* node);

        void linkType(const Xml::Node* node);

        void loadImpl(const Xml::Node* node);

        static Type* create(const String& strId, const String& name, TypeCode id);
    };

    inline String MetaFile::format() const
    {
        return _format;
    }
}  // namespace Rt2::MetaData
