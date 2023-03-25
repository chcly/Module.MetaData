#include "MetaData/Location.h"
#include "MetaData/File.h"

namespace Rt2::MetaData
{
    String Location::readLine() const
    {
        if (_file)
            return _file->line(line());
        return {};
    }
}  // namespace Rt2::MetaData
