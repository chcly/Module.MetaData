#pragma once
#include "MetaData/ContextType.h"
#include "MetaData/Location.h"

namespace Rt2::MetaData
{
    class Unimplemented final : public Type
    {
    public:
        static constexpr TypeCode id = UnimplementedTag;

    private:
        friend class MetaFile;

    public:
        Unimplemented(const String& sId, const String& name, TypeCode code);

        ~Unimplemented() override = default;
    };


}  // namespace Rt2::MetaData
