//
// Created by Berezka on 02.06.2019.
//

#ifndef CALENDAR_DATE_H
#define CALENDAR_DATE_H

#include <iostream>
#include <string>

class Date{
    int day, month, year;
public:
    Date()= default;
    int tabNumberDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int currentYear();
    int currentMonth();
    int currentDay();

    int dayNumber( int month, int year);


    std::string getMonthName(int monthNumber);
    int numberOfDays (int monthNumber, int year);
    int CheckDate(int d, int m, int y);
    void SetMonth(int m);
    void SetYear(int y);
    std::string GetDate();
    std::string GetMonth();
    void GetDateFromUser();

};

#endif //CALENDAR_DATE_H
