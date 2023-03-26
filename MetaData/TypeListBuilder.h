#pragma once
#include "MetaData/Type.h"
#include "MetaData/ArrayDeclarations.h"
#include "MetaFile.h"

namespace Rt2::MetaData
{

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
