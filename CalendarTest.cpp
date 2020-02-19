//
// Created by Марина Лукачик on 2019-06-02.
//

#include <gtest/gtest.h>
#include "calendar.h"
#include "date.h"

using TestParam = std:: pair<int, std:: pair<int, int>>;
Date DateTest;


class CalendarTests: public ::testing::TestWithParam<TestParam>{

};



TEST_P(CalendarTests, CalendarShouldReturnExpectedRezult ){
    const TestParam &p = GetParam();

    EXPECT_FALSE(DateTest.CheckDate(p.first,p.second.first,p.second.second))<<"Expected false for year "<<p.second.second<<std::endl;
    EXPECT_FALSE(DateTest.CheckDate(p.first,p.second.first,p.second.second))<<"Expected false for month "<<p.second.first<<std::endl;
    EXPECT_FALSE(DateTest.CheckDate(p.first,p.second.first,p.second.second))<<"Expected false for day "<<p.first<<std::endl;

}

std::vector<TestParam> wrong_years {{1,{3,200}},{3,{3,5000}}};

INSTANTIATE_TEST_CASE_P(PositiveResultyear, CalendarTests,::testing::ValuesIn(wrong_years));


std::vector<TestParam> wrong_months {{1, {56,2000}},{3,{0,2019}}};
INSTANTIATE_TEST_CASE_P(PositiveResultmonth, CalendarTests,::testing::ValuesIn(wrong_months));

std::vector<TestParam> wrong_days {{33, {3, 2019}},{100,{7,2009}}};
INSTANTIATE_TEST_CASE_P(PositiveResultday, CalendarTests, ::testing::ValuesIn(wrong_days));



class DayTest: public ::testing::TestWithParam<TestParam>{

};


TEST_P(DayTest, CalendarShouldReturnExpectedRezult ){
    const TestParam &p = GetParam();

    EXPECT_EQ(DateTest.dayNumber(p.second.first,p.second.second),p.first)<<"Expected day for year and month "<<p.second.second<<" "<<p.second.first<<std::endl;
}


std::vector<TestParam> rightdate{{5,{6,2019}},{0,{7,2019}}};

INSTANTIATE_TEST_CASE_P(PositiveResult, DayTest,::testing::ValuesIn(rightdate));





//class NameofMonth: public ::testing::TestWithParam<TestParam>{
//
//};
//
//TEST_P(NameofMonth, CalendarShouldReturnExpectedRezult){
//    const TestParam &p = GetParam();
//
//    EXPECT_EQ(DateTest.getMonthName(p.second.first))<<"Expected month  for number "<<p.second.second<<std::endl;
//
//
//}
//
//std::vector<TestParam> month_num{{1,{1,2019}},{3,{3,2019}};
//
//INSTANTIATE_TEST_CASE_P(Result, DayTest,::testing::ValuesIn(month_num));