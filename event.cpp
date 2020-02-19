//
// Created by Berezka on 21.05.2019.
//
#include "event.h"
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string Event::CreateRecord(){
    return (date.GetDate()+"  "+this->info);
}

