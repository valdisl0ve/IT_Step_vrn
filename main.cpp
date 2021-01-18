#include <iostream>
#include "Student.h"
#include "cli.h"

using namespace std;

int main()
{
    system("chcp 65001");

    Welcome();

    int choice;
    bool flagExit = false;
    do {
        ShowMenu();
        cout << endl << "Введите пункт меню: ";
        cin >> choice;

        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 0:
                flagExit = true;
                break;
            default:
                break;
        }
    } while (!flagExit);
    //TODO подумать о создании функции выхода из программы
    cout << "До свидания!" << endl;
}
