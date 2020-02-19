//
// Created by Berezka on 02.06.2019.
//

#ifndef CALENDAR_CALENDAR_H
#define CALENDAR_CALENDAR_H

#include <iostream>
#include <vector>
#include <string>
#include "date.h"
#include "event.h"

class Calendar {
    Date date;
    vector <std::string> events;
public:
    Calendar(){};
    void printYear(int year);
    void PrintMonth(int month, int year);
    void options();
    void CreateEvent();
    void SaveEvent();
    void ShowSavedEvents();
    void ShowRecentEvents();
    void DeleteEvents();
    void SearchForEvent();
    void SearchByMonth();
    void SearchBySpecificDate();
    void SearchByYear();
    void UpcomingEvents();
};


#endif //CALENDAR_CALENDAR_H
