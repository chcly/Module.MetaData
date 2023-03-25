#include <cstdio>
#include "Internal/Utils/Utils/String.h"
#include "MetaData/Class.h"
#include "MetaData/Field.h"
#include "MetaData/File.h"
#include "MetaData/MetaFile.h"
#include "MetaData/Namespace.h"
#include "ThisDir.h"
#include "Utils/Directory/Path.h"
#include "gtest/gtest.h"
#include "MetaData/Constructor.h"

GTEST_TEST(MetaData, File_001)
{
    Rt2::MetaData::MetaFile fp;
    Rt2::InputFileStream    ifs;
    ifs.open(TestFile("File1.xml"));
    EXPECT_TRUE(ifs.is_open());
    EXPECT_NO_THROW({ fp.load(ifs); });

    EXPECT_FALSE(fp.format().empty());
    EXPECT_EQ(fp.format(), "1.3.1");

    Rt2::MetaData::Type* tc0 = fp.find("_1");
    EXPECT_NE(tc0, nullptr);
    if (tc0)
    {
        EXPECT_EQ(tc0->code(), Rt2::MetaData::NamespaceTag);

        Rt2::MetaData::Namespace* ns = tc0->cast<Rt2::MetaData::Namespace>();

        EXPECT_NE(ns, nullptr);
        EXPECT_FALSE(ns->members().empty());
    }

    Rt2::MetaData::Type* tc1 = fp.find("_3");
    EXPECT_NE(tc1, nullptr);
    if (tc1)
    {
        EXPECT_EQ(tc1->code(), Rt2::MetaData::ClassTag);

        Rt2::MetaData::Class* st0 = tc1->cast<Rt2::MetaData::Class>();
        Rt2::Console::println(st0->location()->readLine());

        EXPECT_NE(st0, nullptr);
        EXPECT_FALSE(st0->members().empty());
        EXPECT_EQ(st0->members().size(), 9);

        EXPECT_EQ(st0->sizeInBytes(), 32);
        EXPECT_EQ(st0->alignment(), 32);
        EXPECT_EQ(st0->parent(), tc0);
        EXPECT_TRUE(tc0->hasChild(st0));
    }

    Rt2::MetaData::Type* tc2 = fp.find("_6");
    EXPECT_NE(tc2, nullptr);
    if (tc2)
    {
        EXPECT_EQ(tc2->code(), Rt2::MetaData::FieldTag);

        Rt2::MetaData::Field* st0 = tc2->cast<Rt2::MetaData::Field>();
        Rt2::Console::println(st0->location()->readLine());
        EXPECT_NE(st0, nullptr);
        EXPECT_EQ(st0->access(), Rt2::MetaData::PrivateTag);
        EXPECT_EQ(st0->offset(), 0);
        EXPECT_NE(st0->type(), nullptr);

        EXPECT_EQ(st0->parent(), tc1);
        EXPECT_TRUE(tc1->hasChild(st0));
    }
}

GTEST_TEST(MetaData, File_002)
{
    Rt2::MetaData::MetaFile fp;
    Rt2::InputFileStream    ifs;
    ifs.open(TestFile("File1.xml"));
    EXPECT_TRUE(ifs.is_open());
    EXPECT_NO_THROW({ fp.load(ifs); });

    for (const auto* file : fp.files())
    {
        Rt2::Directory::Path path(file->name());
        Rt2::Console::println(path.base());

        Rt2::StringArray lines;
        file->readLines(lines);

        for (const auto& ln : lines)
            Rt2::Console::println(ln);
    }
}

GTEST_TEST(MetaData, File_003)
{
    Rt2::MetaData::MetaFile fp;
    Rt2::InputFileStream    ifs;
    ifs.open(TestFile("File1.xml"));
    EXPECT_TRUE(ifs.is_open());
    EXPECT_NO_THROW({ fp.load(ifs); });

    Rt2::MetaData::Constructor* c9 = fp.find<Rt2::MetaData::Constructor>("_9");
    EXPECT_NE(c9, nullptr);
    EXPECT_TRUE(c9->hasArguments());
    EXPECT_EQ(c9->argumentCount(), 1);


    Rt2::MetaData::Argument *arg0 = c9->argument(0);
    EXPECT_NE(arg0, nullptr);
    EXPECT_TRUE(arg0->isConst());
    EXPECT_TRUE(arg0->isReference());
    EXPECT_FALSE(arg0->isPointer());
}
