#include "MetaData/Location.h"
#include "File.h"
#include "Utils/Directory/Path.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    
    String Location::readLine() const
    {
        if (_file)
            return _file->line(line());
        return {};
    }
}  // namespace Rt2::MetaData
