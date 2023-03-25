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
        Type* type() const;
    };

    inline Type* ContextType::type() const
    {
        return _context;
    }

}  // namespace Rt2::MetaData
