#include "MetaData/ArgumentList.h"
#include "CvQualifiedType.h"

namespace Rt2::MetaData
{
    ArgumentListType::~ArgumentListType()
    {
        for (const auto arg : _arguments)
            delete arg;
    }

    Argument* ArgumentListType::create()
    {
        _arguments.push_back(new Argument());
        return _arguments.back();
    }

    ArgumentListType::List::ConstPointerType ArgumentListType::begin() const
    {
        return _arguments.begin();
    }

    ArgumentListType::List::ConstPointerType ArgumentListType::end() const
    {
        return _arguments.end();
    }

    uint32_t ArgumentListType::size() const
    {
        return _arguments.size();
    }

    Argument* ArgumentListType::at(const uint32_t idx) const
    {
        if (idx < size())
            return _arguments.at(idx);
        return nullptr;
    }

    bool ArgumentListType::empty() const
    {
        return _arguments.empty();
    }
}  // namespace Rt2::MetaData
