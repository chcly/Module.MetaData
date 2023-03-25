#pragma once
#include "MetaData/Type.h"
#include "MetaFile.h"

namespace Rt2::MetaData
{
    using NamespaceArray = SimpleArray<Namespace*>;
    using ClassArray     = SimpleArray<Class*>;
    using StructArray    = SimpleArray<Struct*>;
    using FunctionArray  = SimpleArray<Function*>;
    using TypedefArray   = SimpleArray<Typedef*>;
    using FileArray      = SimpleArray<File*>;

    class TypeListBuilder
    {
    private:
        MetaFile* _fp{nullptr};

    public:
        explicit TypeListBuilder(MetaFile* file);

        void namespaces(NamespaceArray& dest) const;

        void classes(ClassArray& dest) const;

        void structures(StructArray& dest) const;

        void functions(FunctionArray& dest) const;

        void typedefs(TypedefArray& dest) const;

        void files(FileArray& dest) const;
    };

}  // namespace Rt2::MetaData
