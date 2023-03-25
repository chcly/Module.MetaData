#include <cstdio>
#include "Internal/Utils/Utils/String.h"
#include "MetaData/ArgumentList.h"
#include "MetaData/Class.h"
#include "MetaData/Constructor.h"
#include "MetaData/Field.h"
#include "MetaData/File.h"
#include "MetaData/Function.h"
#include "MetaData/MetaFile.h"
#include "MetaData/Namespace.h"
#include "MetaData/TypeListBuilder.h"
#include "ThisDir.h"
#include "Utils/Directory/Path.h"
#include "gtest/gtest.h"
#include "MetaData/Struct.h"
#include "MetaData/Typedef.h"

using namespace Rt2;
using namespace MetaData;

GTEST_TEST(MetaData, File_001)
{
    MetaFile        fp;
    InputFileStream ifs;
    ifs.open(TestFile("File1.xml"));
    EXPECT_TRUE(ifs.is_open());
    EXPECT_NO_THROW({ fp.load(ifs); });

    EXPECT_FALSE(fp.format().empty());
    EXPECT_EQ(fp.format(), "1.3.1");

    Type* tc0 = fp.find("_1");
    EXPECT_NE(tc0, nullptr);
    if (tc0)
    {
        EXPECT_EQ(tc0->code(), Rt2::MetaData::NamespaceTag);

        Namespace* ns = tc0->cast<Namespace>();

        EXPECT_NE(ns, nullptr);
        // EXPECT_FALSE(ns->members().empty());
    }

    Type* tc1 = fp.find("_3");
    EXPECT_NE(tc1, nullptr);
    if (tc1)
    {
        EXPECT_EQ(tc1->code(), Rt2::MetaData::ClassTag);

        Class* st0 = tc1->cast<Class>();
        Console::println(st0->location()->readLine());

        EXPECT_NE(st0, nullptr);
        // EXPECT_FALSE(st0->members().empty());
        // EXPECT_EQ(st0->members().size(), 9);

        // EXPECT_EQ(st0->sizeInBytes(), 32);
        // EXPECT_EQ(st0->alignment(), 32);
        // EXPECT_EQ(st0->context(), tc0);
        // EXPECT_TRUE(st0->hasMember(st0));
    }

    Type* tc2 = fp.find("_6");
    EXPECT_NE(tc2, nullptr);
    if (tc2)
    {
        EXPECT_EQ(tc2->code(), Rt2::MetaData::FieldTag);

        Field* st0 = tc2->cast<Field>();
        Console::println(st0->location()->readLine());
        EXPECT_NE(st0, nullptr);
        EXPECT_EQ(st0->access(), Rt2::MetaData::PrivateTag);
        EXPECT_EQ(st0->offset(), 0);
        EXPECT_NE(st0->type(), nullptr);

        EXPECT_EQ(st0->context().type(), ClassTag);
    }
}

GTEST_TEST(MetaData, File_002)
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

GTEST_TEST(MetaData, File_003)
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

GTEST_TEST(MetaData, File_004)
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

GTEST_TEST(MetaData, File_005)
{
    MetaFile        fp;
    InputFileStream ifs;
    ifs.open(TestFile("File1.xml"));
    EXPECT_TRUE(ifs.is_open());
    EXPECT_NO_THROW({ fp.load(ifs); });

    ClassArray classes;
    fp.list().classes(classes);
    EXPECT_EQ(classes.size(), 1);
    for (auto obj : classes)
    {
        Console::println(obj->name());
        EXPECT_EQ(obj->context().type(), NamespaceTag);
    }

    NamespaceArray namespaces;
    fp.list().namespaces(namespaces);
    EXPECT_EQ(namespaces.size(), 2);
    for (auto obj : namespaces)
        Console::println(obj->name());

    StructArray structs;
    fp.list().structures(structs);
    EXPECT_EQ(structs.size(), 1);
    for (auto obj : structs)
        Console::println(obj->name());

    FunctionArray functions;
    fp.list().functions(functions);
    EXPECT_EQ(functions.size(), 1);
    for (auto obj : functions)
        Console::println(obj->name());

    TypedefArray typedefs;
    fp.list().typedefs(typedefs);
    EXPECT_EQ(typedefs.size(), 0);
    for (auto obj : typedefs)
        Console::println(obj->name());
}




