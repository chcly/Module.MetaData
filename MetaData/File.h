#pragma once
#include "MetaData/Type.h"
#include "Utils/Array.h"
#include "Utils/HashMap.h"
#include "Utils/String.h"
#include "Xml/Node.h"

namespace Rt2::MetaData
{
    class File
    {
    public:
        using Types = HashTable<String, Type*>;
        using TypeArray = SimpleArray<Type*>;

    private:
        Types _types{};
        String _format{};

    public:
        File() = default;
        ~File();

        void load(IStream& stream);

        String format() const;

    private:

        void clear();

        void createType(const Xml::Node* node);

        void linkType(const Xml::Node* node);

        void loadImpl(const Xml::Node* node);

        static Type* create(const String& strId, const String& name, TypeCode id);
    };

    inline String File::format() const
    {
        return _format;
    }
}  // namespace Rt2::MetaData
