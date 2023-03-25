#pragma once
#include "MetaData/Type.h"

namespace Rt2::MetaData
{
    class ContextType
    {
    private:
        friend class MetaFile;

        TypeArray _members;

        Type* _context{nullptr};

    public:
        TypeCode type() const;
    };

}  // namespace Rt2::MetaData
