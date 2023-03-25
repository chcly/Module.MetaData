#pragma once
#include "MetaData/Location.h"
#include "MetaData/Type.h"
#include "Utils/Directory/Path.h"
#include "Utils/String.h"

namespace Rt2::MetaData
{
    class File final : public Type
    {
    public:
        static constexpr TypeCode id = FileTag;

    private:
        friend class MetaFile;  // To define an access only API.

        StringArray _lines;

    public:
        File(const String& sId, const String& name, TypeCode code);
        ~File() override;

        Directory::Path path() const;

        bool exists() const;

        void open(InputFileStream& dest) const;

        void readLines(StringArray& lines) const;

        void open();

        String line(size_t line) const;

        String line(size_t line);

        void close();
    };
}  // namespace Rt2::MetaData
