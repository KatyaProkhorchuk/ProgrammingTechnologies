//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <iostream>
#include <fstream>

TEST(FileNodeTest,FileNodeExist){
    ASSERT_THROW(GetTree("filedoesnotexist",true),std::invalid_argument);
}

TEST(FileNodeTest,FileNodeErr){
    std::filesystem::create_directory("dir");
    std::ofstream("dir/file.txt");
    std::string dir="dir/file.txt";
    ASSERT_THROW(GetTree(dir,true),std::invalid_argument);
}

TEST(FileNodeTest,FileNodePushBack){
    std::filesystem::create_directory("dir/dir1");
    std::filesystem::create_directory("dir/dir2");
    std::filesystem::create_directory("dir/dir3");
    std::ofstream("dir/dir1/file.txt");
    std::string dir="dir";
    ASSERT_NO_THROW(GetTree(dir,false));

}

TEST(FilterEmptyNodes,FilterReturn){
    std::vector<FileNode> vec;
    FileNode file;
    file.name = "file.txt";
    file.is_dir=false;
    file.children=vec;
    ASSERT_NO_THROW(FilterEmptyNodes(file,"dir"));
}

TEST(FilterEmptyNodes,FilterEmpty){
    std::vector<FileNode> vec;
    FileNode dir_3={"dir/dir3",true,};
    vec.push_back(FileNode(dir_3));
    FileNode file;
    file.name = "dir";
    file.is_dir=true;
    file.children=vec;
    ASSERT_NO_THROW(FilterEmptyNodes(file,"dir/dir1"));
}

TEST(FileNodeTest,OperatorEqual){
    ASSERT_TRUE(GetTree("dir",true)==GetTree("dir",true));
}