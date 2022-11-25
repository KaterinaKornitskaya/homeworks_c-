// Project1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int d1;
    int m1;
    int d2;
    int m2;
    int y1, y2;

   
    std::cout << "Enter d1: ";
    std::cin >> d1;
    std::cout << "Enter d2: ";
    std::cin >> d2;
    std::cout << "Enter m1: ";
    std::cin >> m1;
    std::cout << "Enter m2: ";
    std::cin >> m2;
    std::cout << "Enter y1: ";
    std::cin >> y1;
    std::cout << "Enter y2: ";
    std::cin >> y2;
    
    int difference;


    int days_in_years = 0;
    // кол-во дней в полных годах
    for (int i = y1; i < y2; ++i) {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
            days_in_years += 366;
        }
        else {
            days_in_years += 365;
        }
    }
    // кол-во дней в полных месяцах начальной даты
    int days_in_months_start;
    int days_in_months_end;
    int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };


    // start
    if (y1 % 4 == 0 && y1 % 100 != 0 && m1 < 2 || y1 % 400 == 0) {

        int days = 0;
        for (int i = m1; i <= 11; ++i) {
            days += arr[i];

        }
        days_in_months_start = days + 1;
    }
    else {
        int days = 0;
        for (int i = m1; i <= 11; ++i) {
            days += arr[i];

        }
        days_in_months_start = days;
    }
    //end
    if (y2 % 4 == 0 && y2 % 100 != 0 && m2 > 1 || y2 % 400 == 0) {

        int days = 0;
        for (int i = 0; i < m2 - 1; ++i) {
            days += arr[i];

        }
        days_in_months_end = days + 1;
    }
    else {
        int days = 0;
        for (int i = 0; i < m2 - 1; ++i) {
            days += arr[i];

        }
        days_in_months_end = days;
    }
    // кол-во дней отдельных
    // начало
    int days_in_days_start;
    (y1 % 4 == 0 && y1 % 100 != 0 && m1 == 2 || y1 % 400 == 0)
        ? days_in_days_start = arr[m1 - 1] - d1 + 1
        : days_in_days_start = arr[m1 - 1] - d1;
    // конец
    int days_in_days_end = d2;


    difference = days_in_years + days_in_months_start + days_in_months_end
        + days_in_days_start + days_in_days_end;


    std::cout << "Diference is: " << difference;

}


