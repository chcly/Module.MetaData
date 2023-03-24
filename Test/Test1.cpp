#include <cstdio>
#include "Internal/Utils/Utils/String.h"
#include "MetaData/MetaFile.h"
#include "ThisDir.h"
#include "gtest/gtest.h"

GTEST_TEST(MetaData, File_001)
{
    Rt2::MetaData::MetaFile  fp;
    Rt2::InputFileStream ifs;
    ifs.open(TestFile("Transformer/File1.xml"));
    EXPECT_TRUE(ifs.is_open());
    EXPECT_NO_THROW({ fp.load(ifs); });

    EXPECT_FALSE(fp.format().empty());
    EXPECT_EQ(fp.format(), "1.3.1");

    Rt2::MetaData::Type *tc = fp.find("_1");
    EXPECT_NE(tc, nullptr);
    if (tc)
    {
        EXPECT_EQ(tc->type(), Rt2::MetaData::NamespaceTag);

        Rt2::MetaData::Namespace* ns = tc->cast<Rt2::MetaData::Namespace>();
        EXPECT_NE(ns, nullptr);
        EXPECT_FALSE(ns->members().empty());
    }
}
