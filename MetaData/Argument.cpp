#include "MetaData/Argument.h"
#include "CvQualifiedType.h"
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
            if (_type->isTypeOf(ReferenceTypeTag))
            {
                const ReferenceType* ref = _type->cast<ReferenceType>();
                return ref && ref->isConst();
            }

            if (_type->isTypeOf(CvQualifiedTypeTag))
            {
                const CvQualifiedType* ref = _type->cast<CvQualifiedType>();
                return ref && ref->isConst();
            }
        }
        return false;
    }

    bool Argument::isPointer() const
    {
        if (_type)
        {
            if (_type->isTypeOf(ReferenceTypeTag))
            {
                const ReferenceType* ref = _type->cast<ReferenceType>();
                return ref && ref->isPointer();
            }

            if (_type->isTypeOf(PointerTypeTag))
                return true;
        }
        return false;
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
        if (idx < size())
            return _arguments.at(idx);
        return nullptr;
    }

    bool ArgumentListType::empty() const
    {
        return _arguments.empty();
    }
}  // namespace Rt2::MetaData
