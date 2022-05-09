//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

TEST(LeapTestCase,LeapTestErr){
    ASSERT_THROW(IsLeap(0),std::invalid_argument);
    ASSERT_THROW(IsLeap(-1),std::invalid_argument);   
}
TEST(LeapTestCase,LeapTest){
    ASSERT_TRUE(IsLeap(1600));
    ASSERT_FALSE(IsLeap(1000));
    ASSERT_TRUE(IsLeap(16));
    ASSERT_FALSE(IsLeap(1));
}
