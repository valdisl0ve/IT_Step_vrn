#pragma once

#include <string>
#include "Sex.h"
#include "Date.h"
#include "Faculty.h"

using namespace std;

struct Student {
    string firstName;
    string lastName;
    Sex sex;
    Date birthDay;
    Faculty faculty;
    string group;
    bool isStudy;
};
