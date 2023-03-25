#include "MetaData/Argument.h"

#include "ReferenceType.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    Argument::Argument() = default;

    Location* Argument::location()
    {
        return &_location;
    }

    bool Argument::isReference() const
    {
        return _type != nullptr && _type->code() == ReferenceTypeTag;
    }

    bool Argument::isConst() const
    {
        if (_type)
        {
            if (_type->code() == ReferenceTypeTag)
            {
                ReferenceType *ref = _type->cast<ReferenceType>();
                return ref && ref->isConst();
            }
        }

        return _type != nullptr && _type->code() == CvQualifiedTypeTag;
    }

    bool Argument::isPointer() const
    {
        return _type != nullptr && _type->code() == PointerTypeTag;
    }

    ArgumentListType::~ArgumentListType()
    {
        for (const auto arg : _arguments)
            delete arg;
        _arguments.clear();
    }

    Argument* ArgumentListType::create()
    {
        Argument* arg = new Argument();
        _arguments.push_back(arg);
        return arg;
    }

    const ArgumentList& ArgumentListType::list() const
    {
        return _arguments;
    }

    uint32_t ArgumentListType::size() const
    {
        return _arguments.size();
    }

    Argument* ArgumentListType::at(const uint32_t idx)
    {
        if (idx <size())
            return _arguments.at(idx);
        return nullptr;
    }

    bool ArgumentListType::empty() const
    {
        return _arguments.empty();
    }
}  // namespace Rt2::MetaData
