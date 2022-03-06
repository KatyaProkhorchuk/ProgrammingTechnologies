#include "gtest/gtest.h"
#include "main.h"
TEST(test_foo, test_lib)
{
    ASSERT_EQ(foo(), 0);
}
TEST(check_index,test_A){
    ASSERT_EQ(testFun(10),1);
}