#pragma once
#include "MetaData/Argument.h"

namespace Rt2::MetaData
{
    class ArgumentListType
    {
    public:
        using List = SimpleArray<Argument*>;

        using PointerType = List::ConstPointerType;

    private:
        friend class MetaFile;

        List _arguments{};

        Argument* create();

    public:
        ArgumentListType() = default;

        ~ArgumentListType();

        PointerType begin() const;

        PointerType end() const;

        uint32_t size() const;

        Argument* at(uint32_t idx) const;

        bool empty() const;
    };

}  // namespace Rt2::MetaData
