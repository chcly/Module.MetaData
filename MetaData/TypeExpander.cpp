#include "MetaData/TypeExpander.h"
#include "MetaData/Class.h"
#include "MetaData/CvQualifiedType.h"
#include "MetaData/Field.h"
#include "MetaData/Function.h"
#include "MetaData/FunctionType.h"
#include "MetaData/Method.h"
#include "MetaData/PointerType.h"
#include "MetaData/ReferenceType.h"
#include "MetaData/Struct.h"
#include "MetaData/Typedef.h"

namespace Rt2::MetaData
{

    TypeExpander::TypeExpander(Type* type) :
        _type(type)
    {
    }

    void TypeExpander::expand(const Visitor& method, const size_t max) const
    {
        size_t depth = 0;
        Type*  cur   = _type;
        while (cur != nullptr && ++depth < max)
        {
            switch ((int)cur->code())
            {
            case ReferenceTypeTag:
                if (method(cur))
                    return;
                cur = cur->assert_cast<ReferenceType>()->type();
                break;
            case PointerTypeTag:
                if (method(cur))
                    return;
                cur = cur->assert_cast<PointerType>()->type();
                break;
            case CvQualifiedTypeTag:
                if (method(cur))
                    return;
                cur = cur->assert_cast<CvQualifiedType>()->type();
                break;
            case FunctionTypeTag:
                if (method(cur))
                    return;
                cur = cur->assert_cast<FunctionType>()->returns();
                break;
            case FunctionTag:
                if (method(cur))
                    return;
                cur = cur->assert_cast<Function>()->returns();
                break;
            case TypedefTag:
                if (method(cur))
                    return;
                cur = cur->assert_cast<Typedef>()->type();
                break;
            case FieldTag:
                if (method(cur))
                    return;
                cur = cur->assert_cast<Field>()->type();
                break;
            case FundamentalTypeTag:
            case ClassTag:
            case StructTag:
                if (method(cur))
                    return;
                cur = nullptr;
                break;
            default:
                cur = nullptr;
                break;
            }
        }

        if (depth >= max)
            throw Exception("max link limit reached");
    }

    void TypeExpander::expand(TypeArray& dest, const size_t max) const
    {
        expand(
            [&dest](Type* type)
            {
                dest.push_back(type);
                return false;
            },
            max);
    }

    Type* TypeExpander::search(const int code) const
    {
        Type* found = nullptr;
        expand(
            [code, &found](Type* type)
            {
                if (type->code() == code)
                {
                    found = type;
                    return true;
                }
                return false;
            });
        return found;
    }

}  // namespace Rt2::MetaData
