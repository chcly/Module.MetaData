#include <cstdio>
#include "Internal/Utils/Utils/String.h"
#include "MetaData/File.h"
#include "ThisDir.h"
#include "gtest/gtest.h"

GTEST_TEST(MetaData, File_001)
{
    Rt2::MetaData::File  fp;
    Rt2::InputFileStream ifs;
    ifs.open(TestFile("Transformer/File1.xml"));
    EXPECT_TRUE(ifs.is_open());
    EXPECT_NO_THROW({ fp.load(ifs); });

    EXPECT_FALSE(fp.format().empty());
}
