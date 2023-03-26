#include <cstdio>
#include "Utils/String.h"
#include "MetaData/ArgumentList.h"
#include "MetaData/Class.h"
#include "MetaData/Constructor.h"
#include "MetaData/Field.h"
#include "MetaData/File.h"
#include "MetaData/Function.h"
#include "MetaData/MetaFile.h"
#include "MetaData/Namespace.h"
#include "MetaData/Struct.h"
#include "MetaData/TypeListBuilder.h"
#include "MetaData/Typedef.h"
#include "ThisDir.h"
#include "Utils/Directory/Path.h"
#include "Utils/StreamConverters/Hex.h"
#include "gtest/gtest.h"

using namespace Rt2;
using namespace MetaData;

GTEST_TEST(MetaData, File_001)
{
    MetaFile        fp;
    InputFileStream ifs;
    ifs.open(TestFile("File1.xml"));
    EXPECT_TRUE(ifs.is_open());
    EXPECT_NO_THROW({ fp.load(ifs); });

    FileArray files;
    fp.list().files(files);

    for (const auto* file : files)
    {
        Directory::Path path(file->name());
        Console::println(path.base());

        StringArray lines;
        file->readLines(lines);

        for (const auto& ln : lines)
            Console::println(ln);
    }
}

GTEST_TEST(MetaData, File_002)
{
    MetaFile        fp;
    InputFileStream ifs;
    ifs.open(TestFile("File1.xml"));
    EXPECT_TRUE(ifs.is_open());
    EXPECT_NO_THROW({ fp.load(ifs); });

    Constructor* c9 = fp.find<Constructor>("_9");
    EXPECT_NE(c9, nullptr);

    ArgumentListType* al = c9->arguments();

    EXPECT_FALSE(al->empty());
    EXPECT_EQ(al->size(), 1);

    Argument* arg0 = al->at(0);
    EXPECT_NE(arg0, nullptr);
    EXPECT_TRUE(arg0->isConst());
    EXPECT_TRUE(arg0->isReference());
    EXPECT_FALSE(arg0->isPointer());

    Function* c5 = fp.find<Function>("_5");
    EXPECT_NE(c5, nullptr);

    ArgumentListType* a2 = c5->arguments();
    EXPECT_FALSE(a2->empty());
    EXPECT_EQ(a2->size(), 1);

    arg0 = a2->at(0);
    EXPECT_NE(arg0, nullptr);
    EXPECT_FALSE(arg0->isConst());
    EXPECT_TRUE(arg0->isReference());
    EXPECT_TRUE(arg0->isPointer());
}

GTEST_TEST(MetaData, File_003)
{
    MetaFile        fp;
    InputFileStream ifs;
    ifs.open(TestFile("File2.xml"));
    EXPECT_TRUE(ifs.is_open());
    EXPECT_NO_THROW({ fp.load(ifs); });

    Function* c5 = fp.find<Function>("_1");
    EXPECT_NE(c5, nullptr);
    EXPECT_NE(c5, nullptr);

    auto al = c5->arguments();
    EXPECT_FALSE(al->empty());
    EXPECT_EQ(al->size(), 1);

    auto arg0 = al->at(0);
    EXPECT_NE(arg0, nullptr);
    EXPECT_TRUE(arg0->isConst());
    EXPECT_TRUE(arg0->isReference());
    EXPECT_TRUE(arg0->isPointer());
}

GTEST_TEST(MetaData, File_004)
{
    MetaFile        fp;
    InputFileStream ifs;
    ifs.open(TestFile("Class.xml"));
    EXPECT_TRUE(ifs.is_open());
    EXPECT_NO_THROW({ fp.load(ifs); });

    ClassArray classes;
    fp.list().classes(classes);
    EXPECT_EQ(classes.size(), 1);
    for (auto obj : classes)
    {
        Console::println(obj->name());
        EXPECT_EQ(obj->context().parentType(), NamespaceTag);
        EXPECT_EQ(obj->context().parent()->name(), "Module");

        const FieldArray& fa = obj->context().fields();

        EXPECT_FALSE(fa.empty());
        EXPECT_EQ(fa.size(), 2);
        EXPECT_EQ(fa.at(0)->access(), PrivateTag);
        EXPECT_EQ(fa.at(0)->atomic(), I32Tag);
        EXPECT_EQ(fa.at(0)->name(), "_field1");

        EXPECT_EQ(fa.at(1)->access(), PrivateTag);
        EXPECT_EQ(fa.at(1)->atomic(), I32Tag);
        EXPECT_EQ(fa.at(1)->name(), "_field2");
    }
}
