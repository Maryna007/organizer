//
// Created by Berezka on 02.06.2019.
//

#include "calendar.h"
#include "event.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void Calendar::printYear(int year)
{
    if(year==0){
        year = date.currentYear();
        date.SetYear(year);
    }
    printf ("         Calendar - %d\n\n", year);
    int days;


    // Index of the day from 0 to 6
    int current = date.dayNumber ( 1, year);

    // i --> Iterate through all the months

    // j --> Iterate through all the days of the
    //       month - i
    for (int i = 0; i < 12; i++) {
        days = date.numberOfDays(i, year);

        // Print the current month name
        printf("\n  ------------%s------------- \n",
               date.getMonthName(i).c_str());

        // Print the columns
        printf("  Mon  Tue  Wed  Thu  Fri  Sat  Sun\n");

        // Print appropriate spaces
        int k;
        for (k = 0; k < current; k++)
            printf("     ");

        for (int j = 1; j <= days; j++) {
            printf("%5d", j);

            if (++k > 6) {
                k = 0;
                printf("\n");
            }

        }

        if (k)
            printf("\n");

        current = k;
    }
}

void Calendar::PrintMonth(int month, int year){
    if(month == 0 && year == 0){
        month = date.currentMonth();
        date.SetMonth(month);
        year = date.currentYear();
        date.SetYear(year);
    }
    printf ("         Calendar - %d\n\n", year);
    int days;
    days = date.numberOfDays(month, year);
    printf("\n  ------------%s------------- \n",
           date.getMonthName(month).c_str());
    printf("  Mon  Tue  Wed  Thu  Fri  Sat  Sun\n");

    int current = date.dayNumber( month+1, year);
    int k;

    for ( k = 0; k < current; k++)
        printf("     ");
    for (int j = 1; j <= days; j++) {
        printf("%5d", j);
        if (++k > 6) {
            k = 0;
            printf("\n");
        }
    }
    if (k)
        printf("\n");
    options();
};

void Calendar::options(){
    cout<<"E: Create an event\tS: Show recent events\tD: Show saved events\nF: Search for event\tU: Upcoming events\n"
          "P: Print calendar for specific month\tY: Print calendar for specific year\n";
    char chosen;
    cin>>chosen;
    int m, y;
    Event event;
    switch(chosen){
        case 'E':
            CreateEvent();
            break;
        case 'S':
            ShowRecentEvents();
            break;
        case 'D':
            ShowSavedEvents();
            break;
        case 'U':
            UpcomingEvents();
            break;
        case 'F':
            SearchForEvent();
            break;
        case 'P':
            cout<<"Enter month and year mm yyyy\n";
            cin >>m>>y;
            date.SetMonth(m);
            date.SetYear(y);
            PrintMonth(m-1, y);
            break;
        case 'Y':
            cout<<"Enter year\n";
            cin>>y;
            date.SetYear(y);
            printYear(y);
            break;
        default:
            cout<<"No such option\n";
            break;
    }
}

void Calendar::CreateEvent() {
    Event event;
    event.date.GetDateFromUser();
    cout<<"information about event\n";
    cin>>event.info;
    cout<<endl;
    string data;
    data=event.CreateRecord();
    events.push_back(data);
//    for (auto & i: events)
//        cout<<i<<endl;
};

void Calendar::SaveEvent(){
    ofstream file;
    file.open("/Users/marinalukacik/Desktop/org/event", ios::app);
    if (file.is_open())
        for (auto & i: events) {
            file<<i<< endl;
        }
    else{
        cout<<"file not opened\n";
    }
    file.close();
    cout << "Save to file success." << endl;
    events.clear();
};

void Calendar::DeleteEvents(){
    bool flag = true;
    int num;
    char choise;
    while (flag && events.size()!=0){
        cout<<"Enter number of event you want to delete\n";
        cin>>num;
        if (num <0 || num > events.size())
            flag = true;
        else{
            events.erase(events.begin()+num-1);
            cout<<"Y: delete one more event\tN: return to my events\n";
            cin>>choise;
            switch(choise){
                case 'Y':{
                    flag=true;
                    break;
                }
                case 'N':
                    flag= false;
                    break;
                default:
                    cout<<"No such option\n";
                    break;
            }
        }

    }
    ShowRecentEvents();


}

void Calendar::ShowRecentEvents(){
    int count = 0;
    if (events.size() == 0){
        cout<<"No recently created events\n";
    }else{
        cout<<"Recently created events\n";
        for (auto & i : events){
            cout<<to_string(++count)+" "+i<<endl;
        }
        cout<<"R: return to calendar\tD: delete some events\tS: save events\n";
        char choise;
        cin >> choise;
        switch(choise) {
            case 'S': {
                SaveEvent();
                break;
            }
            case 'R':{
                break;
            }
            case 'D':{
                DeleteEvents();
                break;
            }
            default:{
                cout<<"No such option\n";
                break;
            }
        }
    }
}

void Calendar::ShowSavedEvents() {
    ifstream file;
    string line;
    file.open("/Users/marinalukacik/Desktop/org/event");
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            cout << line << '\n';
        }
        file.close();
    }
    else{
        cout<<"file not opened\n";
    }
}

void Calendar::SearchForEvent() {
    cout << "A: searching by specific date\tS: searching by month\tD: searching by year\n";
    char choice;
    cin >> choice;
    switch (choice) {
        case 'A':
            SearchBySpecificDate();
            break;
        case 'S':
            SearchByMonth();
            break;
        case 'D':
            SearchByYear();
            break;
        default:
            cout << "There's no such option. Check your input.";
            SearchForEvent();
    }
}

void Calendar::SearchBySpecificDate() {
    date.GetDateFromUser();
    ifstream file;
    string line;
    file.open("/Users/marinalukacik/Desktop/org/eventt");
    string data;
    data = date.GetDate();
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find(data) == 0) {
                cout << line << endl;
            }
        }
        file.close();
    } else {
        cout << "file not opened\n";
    }
};

void Calendar::SearchByMonth() {
    cout<<"What month do you want to look through?\n";
    int m;
    cin>>m;
    date.SetMonth(m);
    ifstream file;
    string line;
    file.open("/Users/marinalukacik/Desktop/org/eventt");
    string data;
    data = date.GetMonth();
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find(data) == 3) {
                cout << line << endl;
            }
        }
        file.close();
    } else {
        cout << "file not opened\n";
    }
};

void Calendar::SearchByYear() {
    cout<<"What year do you want to look through?\n";
    int y;
    cin>>y;
    date.SetYear(y);
    ifstream file;
    string line;
    file.open("/Users/marinalukacik/Desktop/org/event");
    string data;
    data = to_string(y);
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find(data) == 5) {
                cout << line << endl;
            }
        }
        file.close();
    } else {
        cout << "file not opened\n";
    }
};

void Calendar::UpcomingEvents(){
    ifstream file;
    string line;
    file.open("/Users/marinalukacik/Desktop/org/event");
    string data, days, dayline="";
    date.SetMonth(date.currentMonth()+1);
    data=date.GetMonth();
    days=to_string(date.currentDay());
    cout<<"Upcoming events\n";
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find(data) == 2) {
                dayline+="0";
                dayline+=line[0];
                if(stoi(dayline)>=stoi(days))
                    cout<<line<<endl;
            }else if(line.find(data)==3){
                dayline+=line[0];
                dayline+=line[1];
                if(stoi(dayline)>=stoi(days))
                    cout<<line<<endl;
            }else
                cout<<"There're no upcoming events\n";

        }
        file.close();
    } else {
        cout << "file not opened\n";
    }
}

