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
            return _file->line(Max<int>(lineI() - 1, 0));
        return {};
    }

    void Location::readLines(StringArray& lines) const
    {
        if (_file)
            _file->readLines(lines);
    }

    String Location::filename(const bool native) const
    {
        if (_file)
        {
            if (native)
                return Directory::Path(_file->name()).fullPlatform();
            return Directory::Path(_file->name()).full();
        }
        return {};
    }

    String Location::basename() const
    {
        if (_file)
            return Directory::Path(filename()).base();
        return {};
    }

    bool Location::exists() const
    {
        if (_file)
            return _file->exists();
        return false;
    }
}  // namespace Rt2::MetaData
