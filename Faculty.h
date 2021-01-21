#pragma once

#include <string>

using namespace std;

enum Faculty {
    SoftDev, Design
};

string FacultyToString(Faculty faculty)
{
    switch (faculty) {
        case SoftDev:
            return "Разработка ПО";
        case Design:
            return "Дизайн";
    }
}