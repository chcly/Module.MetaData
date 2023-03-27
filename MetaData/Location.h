#pragma once
#include "MetaData/Type.h"

namespace Rt2::MetaData
{
    class Location
    {
    private:
        friend class MetaFile;

        File* _file{nullptr};

        size_t _line{0};

    public:
        Location() = default;

        ~Location() = default;

        size_t line() const;

        int lineI() const;

        String readLine() const;

        void readLines(StringArray& lines) const;

        String filename() const;

        bool exists() const;
    };

    inline size_t Location::line() const
    {
        return _line;
    }

}  // namespace Rt2::MetaData
