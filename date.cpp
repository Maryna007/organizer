//
// Created by Berezka on 02.06.2019.
//
#include <iostream>
#include "time.h"
#include "date.h"

using namespace std;

int Date::currentYear(){
    time_t t = time(nullptr);
    tm* timePtr = localtime(&t);
    return timePtr->tm_year+1900;
};

int Date::currentMonth() {
    time_t t =time(nullptr);
    tm* timePtr = localtime(&t);
    return timePtr->tm_mon;
};

int Date::currentDay() {
    time_t t =time(nullptr);
    tm* timePtr = localtime(&t);
    return timePtr->tm_mday;
}

int Date::dayNumber( int month, int year){

    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    int startingDay;
    int d = 1;
//    if (month == 2) {
//        d = 0;
//    }
    startingDay = ((year + year / 4 - year / 100 + year / 400 + t[month - 1] + d) % 7);
    return ( startingDay-1);
};

string Date::getMonthName(int monthNumber)
{
    string months[] = {"January", "February", "March",
                       "April", "May", "June",
                       "July", "August", "September",
                       "October", "November", "December"
    };

    return (months[monthNumber]);
}

int Date::numberOfDays (int monthNumber, int year) {

    if (monthNumber == 1)
        if (year % 400 == 0 ||
            (year % 4 == 0 && year % 100 != 0))
            return 29;
        else
            return 28;
    else
        return tabNumberDays[monthNumber];
}

int Date::CheckDate(int d, int m, int y){
    if (m>0 && m<13 && d>0 && d <= tabNumberDays[m-1] && y>=1970 && y<2050)
        return 1;
    else{
        cout<<"Incorrect date\n";
        return 0;
    }
}

void Date::GetDateFromUser(){
    int flag = 0;
    while (!flag){
        cout<<"Write date in format dd mm yyyy: \n";
        cin>>day>>month>>year;
        flag = CheckDate(day, month, year);
    }
};

void Date::SetMonth(int m) {
    if (m>0 && m<13)
        month = m;
};

void Date::SetYear(int y) {
    if (y>=1970 && y<2050)
        year= y;
};

string Date::GetDate(){
    return (to_string(this->day)+"-"+to_string(this->month)+"-"+to_string(this->year));
};

string Date::GetMonth(){
    return (to_string(this->month));
};