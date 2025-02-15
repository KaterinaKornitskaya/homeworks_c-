﻿// dz_function2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

/*
 Тема: Функції. Передача масивів всередину функції
 Домашнє завдання 1

 
 Завдання 2. Написати функцію, що визначає середнє
 арифметичне елементів переданого їй масиву.

 Завдання 3. Написати функцію, що визначає кількість
 додатних, від'ємних і нульових елементів переданого їй
 масиву.
*/

void fill_arr1x(int arr1x[], size_t N) {  // функция заполнения 1-мерного массива
    for (size_t i = 0; i < N; ++i) {
        arr1x[i] = rand() % 50 - 10;
    }
}

void print_arr1x(int arr1x[], size_t N) {  // функция вывода на экран 1-мерного массива
    for (size_t i = 0; i < N; ++i) {
        std::cout << arr1x[i] << ' ';
    }
}

float arithm_arr1x(int arr1x[], int N) {  // функция для поиска среднего арифметического в 1-мерном массиве
    float ar = 0;
    float sum = 0;
    for (int i = 0; i < N; ++i) {
        sum +=arr1x[i];
        ar = sum / N;   
    }
    std::cout << ar;
    return ar;
}

void fill_arr2x(int arr2x[][5], int N1, int N2) {  // функция заполнения 2-мерного массива
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            arr2x[i][j] = rand() % 50 - 10;
        }
    }
}

void print_arr2x(int arr2x[][5], int N1, int N2) {  // функция вывода на экран 2-мерного массива
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            std::cout << arr2x[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

double arithm_arr2x(int arr2x[][5], int N1, int N2) {  // функция для поиска среднего арифметического в 2-мерном массиве
    double ar2 = 0;
    double sum = 0;
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            sum += (arr2x[i][j]);
            ar2 = sum / (N1 * N2);           
        }        
    }
    std::cout << ar2;
    return ar2;
}

int pos_neg_zero_arr1x(int arr1x[], int N) {  // функция для вывода кол-ва +/-/0 элементов в 1-мерном массиве
    short pos = 0;  // накопительная переменная для положительных элементов
    short neg = 0;  // накопительная переменная для отрицательных элементов
    short zero = 0;  // накопительная переменная для нулевых элементов
    for (int i = 0; i < N; ++i) {
        if (arr1x[i] > 0) {
            pos += 1;           
        }
        else if (arr1x[i] < 0) {
            neg += 1;           
        }
        else {
            zero += 1;           
        }       
    }
    (pos > 0) 
        ? std::cout << "\nPositive elements: " << pos 
        : std::cout << "\nPositive elements: No.";
    (neg > 0) 
        ? std::cout << "\nNegative elements: " << neg 
        : std::cout << "\nNegative elements: No.";
    (zero > 0) 
        ? std::cout << "\nZero elements: " << zero 
        : std::cout << "\nZeros elements: No.";
    return pos, neg, zero;
}

int pos_neg_zero_arr2x(int arr2x[][5], int N1, int N2) {  // функция для вывода кол-ва +/-/0 элементов в 2-мерном массиве
    int pos = 0, neg = 0, zero = 0;
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            if (arr2x[i][j] > 0) {
                pos += 1;
            }
            else if (arr2x[i][j] < 0) {
                neg += 1;
            }
            else {
                zero += 1;
            }
        }
    }
    (pos > 0)
        ? std::cout << "\nPositive elements: " << pos
        : std::cout << "\nPositive elements: No.";
    (neg > 0)
        ? std::cout << "\nNegative elements: " << neg
        : std::cout << "\nNegative elements: No.";
    (zero > 0)
        ? std::cout << "\nZero elements: " << zero
        : std::cout << "\nZeros elements: No.";
    return pos, neg, zero;
}


int main() {

    const size_t N = 10;  // размер 1-мерного массива
    int arr1x[N];  // 1-мерный массив
    const size_t N1 = 2;
    const size_t N2 = 5;  // размер 2-мерного массива
    int arr2x[N1][N2];  // 2-мерный массив

    srand(time(NULL));

    fill_arr1x(arr1x, N);
    print_arr1x(arr1x, N);
    std::cout << "\n\nArithmetical: ";
    arithm_arr1x(arr1x, N);   
    pos_neg_zero_arr1x(arr1x, N);
    std::cout << std::endl;
    std::cout << std::endl;
    fill_arr2x(arr2x, N1, N2);
    print_arr2x(arr2x, N1, N2);
    std::cout << "\nArithmetical 2x: ";
    arithm_arr2x(arr2x, N1, N2);   
    pos_neg_zero_arr2x(arr2x, N1, N2);
    std::cout << std::endl;
    return 0;
}


/*
 Написати функцію, яка приймає дві дати 
(тобто функція приймає шість параметрів) та обчислює 
різницю в днях між цими датами. Для виконання цього 
завдання необхідно також написати функцію, яка визначає, чи є рік високосним.
*/

int dates(int d1, int d2, int m1, int m2, int y1, int y2) {  // функция для разницы в днях между датами

    int days_in_years = 0;
    // кол-во дней в полных годах
    for (int i = y1+1; i < y2; ++i) {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
            days_in_years += 366;
        }
        else {
            days_in_years += 365;
        }
    }
    
    // кол-во дней в полных месяцах 
    int days_in_months_start;  // кол-во дней в полных месяцах начальной даты
    int days_in_months_end;    // кол-во дней в полных месяцах конечной даты
    int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };  // массив для дней в месяцах
   
    // кол-во дней в полных месяцах начальной даты
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
    
    // кол-во дней в полных месяцах конечной даты
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
    // кол-во дней (неполный месяц в дате начала и дате конца)
    // дата начала
    int days_in_days_start;
    (y1 % 4 == 0 && y1 % 100 != 0 && m1 == 2 || y1 % 400 == 0)
        ? days_in_days_start = arr[m1 - 1] - d1 + 1
        : days_in_days_start = arr[m1 - 1] - d1;
    // дата конца
    int days_in_days_end = d2;
    
    int difference;  // переменная для итогового результата
    difference = days_in_years + days_in_months_start + days_in_months_end
        + days_in_days_start + days_in_days_end;

    return difference;  // функция возвращает результат
}

int main1() {

    int d1, d2, m1, m2, y1, y2;

    std::cout << "Enter date 1: \n";
    std::cin >> d1 >> m1 >> y1;
    std::cout << "Enter date 2: \n";
    std::cin >> d2 >> m2 >> y2;
   
    std::cout << "Days between yor dates: " << dates(d1, d2, m1, m2, y1, y2);

    return 0;
}
