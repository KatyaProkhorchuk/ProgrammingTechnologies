//
// Created by akhtyamovpavel on 5/1/20.
//

#include <boost/filesystem/path.hpp>
#include "TreeTestCase.h"
#include "Tree.h"
#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
TEST(FileNodeTest, FileNodeExist)
{
    ASSERT_THROW(GetTree("filedoesnotexist", true), std::invalid_argument);
}

TEST(FileNodeTest, FileNodeErr)
{
    auto temp_path = fs::temp_directory_path();
    std::filesystem::create_directory(temp_path / "dir");
    std::ofstream(temp_path / "dir/file.txt");
    std::string dir=temp_path /"dir/file.txt";
    ASSERT_THROW(GetTree(dir,true),std::invalid_argument);
}
TEST(FileNodeTest, FileNodePushBack)
{
    auto temp_path = std::filesystem::temp_directory_path();

    std::filesystem::remove_all(temp_path / "dir");
    std::filesystem::create_directory(temp_path / "dir");
    std::filesystem::create_directory(temp_path / "dir/dir1");
    std::filesystem::create_directory(temp_path / "dir/dir2");
    std::filesystem::create_directory(temp_path / "dir/task");
    auto filepath = (temp_path / "dir/dir1/file.txt").string();
    std::ofstream file(filepath);

    std::string dir = (temp_path / "dir").string();
    FileNode res = {"dir", true, {
                                          {"task", true, {}},
                                          {"dir1", true, {{"file.txt", false, {}}}},
                                          {"dir2", true, {}},
                                      }};
    ASSERT_EQ(res, GetTree(dir, false));
  
  
}

TEST(FilterEmptyNodes, FilterReturn)
{
    auto temp_path = fs::temp_directory_path();
    std::vector<FileNode> vec;
    FileNode file;
    file.name = temp_path / "file.txt";
    file.is_dir = false;
    file.children = vec;
    ASSERT_NO_THROW(FilterEmptyNodes(file, temp_path / "dir"));
}

TEST(FilterEmptyNodes, FilterEmpty)
{
    auto temp_path = fs::temp_directory_path();
    std::vector<FileNode> vec;
    FileNode dir_3 = {
        "dir/dir3",
        true,
    };
    vec.push_back(FileNode(dir_3));
    FileNode file;
    file.name = temp_path / "dir";
    file.is_dir = true;
    file.children = vec;
    ASSERT_NO_THROW(FilterEmptyNodes(file, temp_path / "dir/dir1"));
}

TEST(FileNodeTest, OperatorEqual)
{
    FileNode dir1 = {"dir1", true, {}};
    FileNode dir2 = {"dir2", true, {}};
    ASSERT_FALSE(dir1 == dir2);
    FileNode dir3 = {"dir1", false, {}};
    FileNode dir4 = {"dir2", true, {}};
    ASSERT_FALSE(dir3 == dir4);
}