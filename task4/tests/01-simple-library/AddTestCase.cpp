//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST(AddTestCase, test_simple_library){
    ASSERT_EQ(Add(2,2),4);
    ASSERT_EQ(Add(-2,7),5);
    ASSERT_EQ(Add(0,0),0);
}
TEST(GetMonthDaysTest,GetMonthDaysCheck){
    ASSERT_EQ(GetMonthDays(1600,2),29);
    ASSERT_EQ(GetMonthDays(1601,2),28);
    ASSERT_EQ(GetMonthDays(1600,4),30);
    ASSERT_EQ(GetMonthDays(1600,6),30);
    ASSERT_EQ(GetMonthDays(1600,9),30);
    ASSERT_EQ(GetMonthDays(1600,11),30);
    ASSERT_EQ(GetMonthDays(1600,3),31);
}
TEST(GetMonthDaysTest,GetMonthDaysErr){
    ASSERT_THROW(GetMonthDays(1,13),std::invalid_argument);
    ASSERT_THROW(GetMonthDays(1,-13),std::invalid_argument);
}