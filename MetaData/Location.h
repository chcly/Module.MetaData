#pragma once
#include "MetaData/Type.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class Location
    {
    private:
        friend class MetaFile;  // To define an access only API.

        File* _file{nullptr};

        size_t _line{0};

    public:
        Location() = default;
        ~Location() = default;

        File* file() const;

        size_t line() const;

        String readLine() const;
    };

    inline File* Location::file() const
    {
        return _file;
    }

    inline size_t Location::line() const
    {
        return _line;
    }

}  // namespace Rt2::MetaData
