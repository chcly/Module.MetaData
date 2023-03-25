#include "MetaData/Argument.h"
#include "MetaData/CvQualifiedType.h"
#include "MetaData/Function.h"
#include "MetaData/FunctionType.h"
#include "MetaData/PointerType.h"
#include "MetaData/ReferenceType.h"
#include "MetaData/Typedef.h"

namespace Rt2::MetaData
{
    Argument::Argument() = default;

    Location* Argument::location()
    {
        return &_location;
    }

    Type* Argument::search(const int code) const
    {
        Type* cur = _type;
        while (cur != nullptr)
        {
            const int cc = cur->code();
            if (cc == code)
                return cur;
            switch (cc)
            {
            case ReferenceTypeTag:
                cur = cur->assert_cast<ReferenceType>()->type();
                break;
            case PointerTypeTag:
                cur = cur->assert_cast<PointerType>()->type();
                break;
            case CvQualifiedTypeTag:
                cur = cur->assert_cast<CvQualifiedType>()->type();
                break;
            case FunctionTypeTag:
                cur = cur->assert_cast<FunctionType>()->returns();
                break;
            case FunctionTag:
                cur = cur->assert_cast<Function>()->returns();
                break;
            case TypedefTag:
                cur = cur->assert_cast<Typedef>()->type();
                break;
            case StructTag:
            case ClassTag:
            case FundamentalTypeTag:
            default:
                cur = nullptr;
                break;
            }
        }
        return nullptr;
    }

    bool Argument::isReference() const
    {
        return search(ReferenceTypeTag) != nullptr;
    }

    bool Argument::isConst() const
    {
        return search(CvQualifiedTypeTag) != nullptr;
    }

    bool Argument::isPointer() const
    {
        return search(PointerTypeTag) != nullptr;
    }

    bool Argument::isFunctionPointer() const
    {
        return isPointer() && search(FunctionTypeTag) != nullptr;
    }

    void enqueue(ArgumentQueue& dest, Type* key, bool& front)
    {
        if (front)
            dest.push_front(key);
        else
            dest.push_back(key);

        front = false;
    }

    void Argument::expand(ArgumentQueue& dest) const
    {
        Type* cur   = _type;
        bool  front = false;
        while (cur != nullptr)
        {
            switch ((int)cur->code())
            {
            case ReferenceTypeTag:
                enqueue(dest, cur, front);
                cur = cur->assert_cast<ReferenceType>()->type();
                break;
            case PointerTypeTag:
                enqueue(dest, cur, front);
                cur = cur->assert_cast<PointerType>()->type();
                break;
            case CvQualifiedTypeTag:
                enqueue(dest, cur, front);
                cur = cur->assert_cast<CvQualifiedType>()->type();
                break;
            case FunctionTypeTag:
                if (dest.back()->isTypeOf(PointerTypeTag))
                    dest.pop_back();
                enqueue(dest, cur, front);
                cur = cur->assert_cast<FunctionType>()->returns();
                break;
            case FunctionTag:
                enqueue(dest, cur, front);
                cur = cur->assert_cast<Function>()->returns();
                break;
            case TypedefTag:
                enqueue(dest, cur, front);
                cur = cur->assert_cast<Typedef>()->type();
                break;
            case StructTag:
            case ClassTag:
            case FundamentalTypeTag:
                enqueue(dest, cur, front);
                cur = nullptr;
                break;
            default:
                cur = nullptr;
                break;
            }
        }
    }
}  // namespace Rt2::MetaData
