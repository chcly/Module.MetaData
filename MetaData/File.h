#pragma once
#include "MetaData/Type.h"
#include "Utils/Directory/Path.h"

namespace Rt2::MetaData
{
    class File final : public Type
    {
    public:
        static constexpr TypeCode id = FileTag;

    private:
        friend class MetaFile;  

        mutable StringArray _lines;

    public:
        File(const String& sId, const String& name, TypeCode code);
        ~File() override;

        Directory::Path path() const;

        bool exists() const;

        void open(InputFileStream& dest) const;

        void readLines(StringArray& lines) const;

        void open() const;

        String line(size_t line) const;
        
        void close() const;
    };
}  // namespace Rt2::MetaData
