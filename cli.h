#pragma once

#include <iostream>
#include <vector>
#include "Student.h"
#include <fstream>
#include <string>

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

void ShowStudent(Student student)
{
    cout << "--- Студент ---" << endl;
    cout << "Имя: " << student.firstName << endl;
    cout << "Фамилия: " << student.lastName << endl;
    cout << "Дата рождения: ";
    cout << student.birthDay.ToString() << endl;
    cout << "Пол: " << SexToString(student.sex) << endl;
    cout << "Факультет: " << FacultyToString(student.faculty) << endl;
    cout << "Группа: " << student.group << endl;
    cout << "Учится? - " << student.IsStudyToString() << endl;
    //TODO переработать вывод на экран
}

void ShowStudents(vector<Student> students)
{
    for (auto student : students) {
        ShowStudents(student);
    }
}





void ExportStudent(Student student)
{


    ofstream file_export("export.csv", ios_base::app);
    if (file_export.is_open()) {
        file_export << student.firstName << ";" << student.lastName << ";" << student.birthDay.year << ";"
                    << student.birthDay.month << ";" << student.birthDay.day << ";" << student.sex << ";"
                    << student.faculty << ";" << student.group << endl;
    }
    file_export.close();

}

void ExportStudents(vector<Student> students)
{
    for (auto student : students) {
        ExportStudent(student);
    }
}




void InsertStudent(vector<Student>& students)
{
    Student temp;
    char sexTemp;
    char facultyTemp;

    cout << "+++ Ввод данных студента +++" << endl;
    cout << "Введите имя - "; cin >> temp.firstName;
    cout << "Введите фамилию - "; cin >> temp.lastName;
    cout << "Введите дату рождения:" << endl;
    cout << "год - "; cin >> temp.birthDay.year;
    cout << "месяц - "; cin >> temp.birthDay.month;
    cout << "день - "; cin >> temp.birthDay.day;
    cout << "Введите пол (1 - мужской, 2 - женский) - ";
    cin >> sexTemp;
    if (sexTemp == '1') {
        temp.sex = Sex::Male;
    } else if (sexTemp == '2') {
        temp.sex = Sex::Female;
    } else {
        temp.sex = Sex::Other;
    }
    cout << "Введите факультет (1 - РПО, 2 - Дизайн) - ";
    cin >> facultyTemp;
    if (facultyTemp == '1') {
        temp.faculty = Faculty::SoftDev;
    } else if (facultyTemp == '2') {
        temp.faculty = Faculty::Design;
    }
    cout << "Введите номер группы - "; cin >> temp.group;
    temp.isStudy = true;

    students.push_back(temp);
}


void ImportStudents(vector<Student>& students)
{
    Student temp;
    ifstream file_import("import.csv");
    if (file_import.is_open()) {
        getline(file_import, temp.firstName, ';');
        getline(file_import, temp.lastName, ';');
        getline(file_import, temp.birthDay.year, ';');
        getline(file_import, temp.birthDay.month, ';');
        getline(file_import, temp.birthDay.day, ';');
        getline(file_import, temp.sex, ';');
        getline(file_import, temp.faculty, ';');
        getline(file_import, temp.group);
    }

    file_import.close();
    students.push_back(temp);
}

