//
// Created by Berezka on 21.05.2019.
//

#ifndef CALENDAR_EVENT_H
#define CALENDAR_EVENT_H
#include <string>
#include <iostream>
#include "date.h"


using namespace std;

class Event{
public:
    Date date;
    string info;
    string CreateRecord();
};

#endif //CALENDAR_EVENT_H
