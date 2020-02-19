//#include<bits/stdc++.h>
#include <iostream>
#include <ctime>
#include "calendar.h"
#include "calendar.cpp"
#include "event.h"
#include "event.cpp"
#include <gtest/gtest.h>
using namespace std;


bool flag = true;

int main(){
    Calendar calendar;
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
    calendar.PrintMonth(0, 0);


    while (flag){
        calendar.options();
    }

    return 0;
}