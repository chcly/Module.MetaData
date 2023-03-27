#include "MetaData/Location.h"
#include "MetaData/File.h"

namespace Rt2::MetaData
{
    int Location::lineI() const
    {
        return (int)line();
    }

    String Location::readLine() const
    {
        if (_file)
            return _file->line(Max<int>(lineI()-1, 0));
        return {};
    }

    void Location::readLines(StringArray& lines) const
    {
        if (_file)
            _file->readLines(lines);
    }

    String Location::filename() const
    {
        if (_file)
            return _file->name();
        return {};
    }

    bool Location::exists() const
    {
        if (_file)
            return _file->exists();
        return false;
    }
}  // namespace Rt2::MetaData
