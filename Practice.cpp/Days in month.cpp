#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, ".UTF8");
    int month, year;
    cout << "Введите номер месяца: ";
    cin >> month;
    cout << "Введите год: ";
    cin >> year;

    if (month < 1 || month >12)
    {
        cout << "Ошибка: неверный номер месяца!" << endl;
        return 1;
    }
    bool isLeapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    int daysInMonth = 0;

    switch (month)
    {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                daysInMonth = 31;
            break;
            case 4:
            case 6:
            case 9:
            case 11:
                daysInMonth = 30;
            break;
            case 2:
                daysInMonth = isLeapYear ?
            29:28;
            break;
                default:
                return 1;

    }
    cout << "Bо " << month << " Месяце " << year << " года " << daysInMonth << " дней " << endl;

    return 0;
}