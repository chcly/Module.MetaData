#include "MetaData/File.h"

namespace Rt2::MetaData
{
    File::File(const String&  sId,
               const String&  name,
               const TypeCode code) :
        Type(sId, name, code)
    {
    }

    File::~File()
    {
        close();
    }

    Directory::Path File::path() const
    {
        return Directory::Path(name()).absolute();
    }

    bool File::exists() const
    {
        return path().exists();
    }

    void File::open(InputFileStream& dest) const
    {
        if (const Directory::Path p = this->path(); p.exists())
            dest.open(p.full());
    }

    void File::readLines(StringArray& lines) const
    {
        if (!_lines.empty())
            lines = _lines;
        else
        {
            InputFileStream ifs;
            open(ifs);

            if (ifs.is_open())
            {
                OutputStringStream out;
                Su::copy(out, ifs, true);
                Su::scanSplitLine(lines, out.str());
            }
        }
    }

    void File::open() const
    {
        if (_lines.empty())
            readLines(_lines);
    }

    String File::line(const size_t line) const
    {
        if (_lines.empty())
            readLines(_lines);
        if (line < _lines.size())
            return _lines.at(line);
        return {};
    }

    void File::close() const
    {
        _lines.clear();
    }

}  // namespace Rt2::MetaData
