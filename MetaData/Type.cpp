#include "MetaData/Type.h"

namespace Rt2::MetaData
{

    Type::Type(String hash, String name, const TypeCode code) :
        _id(std::move(hash)),
        _name(std::move(name)),
        _code(code)
    {
    }


    bool Type::hasChild(Type* type) const
    {
        // is linear..
        return _children.find(type) != Npos32;
    }

    void Type::addChild(Type* type)
    {
        if (!type)
            throw Exception("invalid type");

        if (type->_parent)
            throw Exception("type already has a parent");

        type->_parent = this;

        _children.push_back(type);
    }

}  // namespace Rt2::MetaData
