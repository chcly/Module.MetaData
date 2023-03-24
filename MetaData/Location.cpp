#include "MetaData/Location.h"
#include "File.h"
#include "Utils/Directory/Path.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    Location::Location(const String& sId, const String& name, const TypeCode code) :
        Type(sId, name, code)
    {
    }

    String Location::readLine() const
    {
        if (_file)
            return _file->line(line());
        return {};
    }
}  // namespace Rt2::MetaData
