#pragma once

#include <iostream>
#include "Student.h"

using namespace std;

void Welcome()
{
    cout << "====================" << endl;
    cout << "=== БД студентов ===" << endl;
    cout << "=== ------------ ===" << endl;
    cout << "= (c) IT Step ======" << endl;
    cout << "====================" << endl;
}

void ShowMenu()
{
    cout << "Пункты меню:" << endl;
    cout << "1. Добавить нового студента" << endl;
    cout << "2. Поиск студента" << endl;
    cout << "3. Показ данных всех студентов" << endl;
    cout << "4. Редактирование данных студента" << endl;
    cout << "5. Удаление данных студента" << endl;
    cout << "6. Экспорт в файл" << endl;
    cout << "7. Импорт из файла" << endl;
    cout << endl;
    cout << "0. Выход" << endl;
}

string ShowStudy(bool isStudy)
{
    if (isStudy) {
        return "учится";
    } else {
        return "не учится";
    }
}

string ShowSex(Sex sex)
{
    switch (sex) {
        case Male:
            return "мужской";
        case Female:
            return "женский";
        case Other:
            return "неопределённый";
    }
}

string ShowFaculty(Faculty faculty)
{
    switch (faculty) {
        case SoftDev:
            return "Разработка ПО";
        case Design:
            return "Дизайн";
    }
}

string ShowDate(Date date) {
    string result;
    result = to_string(date.day) + "." + to_string(date.month) + "." + to_string(date.year);
    return result;
}

void ShowStudent(Student student)
{
    cout << "--- Студент ---" << endl;
    cout << "Имя: " << student.firstName << endl;
    cout << "Фамилия: " << student.lastName << endl;
    cout << "Дата рождения: ";
    cout << ShowDate(student.birthDay) << endl;
    cout << "Пол: " << ShowSex(student.sex) << endl;
    cout << "Факультет: " << ShowFaculty(student.faculty) << endl;
    cout << "Группа: " << student.group << endl;
    cout << "Учится? - " << ShowStudy(student.isStudy) << endl;
}