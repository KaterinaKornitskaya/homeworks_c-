﻿// 03.11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>

// прототипы функций, задача 2
void func_arr1(int* arr1, size_t length);
void func_arr2(int* arr2, size_t length);
void func_arr3(int* arr1, int* arr2, int* arr3, size_t length);

// прототипы функций, задача 1
double func_addition(double x, double y);
double func_subtraction(double x, double y);
double func_multiplication(double x, double y);
double func_dividing(double x, double y);

// псевдоним типа - указатель на функцию с двумя параметрами 
typedef double (*action_t)(double, double);  

size_t N = 4; // кол-во функций в массиве указателей - действия +, -, *, /

action_t* actions = new action_t[N]  // массив указателей на ф-ии +, -, *, /
{ func_addition, func_subtraction, func_multiplication, func_dividing };

/*
Завдання 1. Створіть додаток Калькулятор. Потрібно
підтримувати операції +, -, *, /.
Реалізувати меню без використання операторів if та
switch за допомогою масиву покажчиків на функції.
*/
int main()
{
    short input_key;  // клавиша, которую нажимает пользователь
    do {              // общий цикл для повторения действия
        system("cls");
        std::cout << "Please, enter the action: "
            << "\n if \" + \" - enter 1 "
            << "\n if \" - \" - enter 2 "
            << "\n if \" * \" - enter 3 "
            << "\n if \" / \" - enter 4 "
            << std::endl;

        std::cin >> input_key;
        if            // проверка, если пользователь ввел НЕ 1,2,3 или 4
            (input_key != 1 && input_key != 2 &&
            input_key != 3 && input_key != 4) {
            std::cout << "Error key. Please, use only '1', '2', '3' or '4' keys.\n";
            return -1;
        }

        double x, y;
        std::cout << "Please, input your numbers using space key: \n";
        std::cin >> x >> y;
        std::cout << " = " 
            << actions[input_key - 1](x, y)  // вывод нужной ф-ии из массива указателей
            << std::endl;
        std::cout << "\nTO CONTUNUE - please, enter any key on the keyboard."
            << "\nTO EXIT - enter ESC." << std::endl;

        input_key = _getch();   // считываем нажатую кнопку перед окончанием цикла
    } while (input_key != 27);  // ESC - условие для выхода

    return 0;
}

double func_addition(double x, double y) {        // функция "+"   
    std::cout << x << " + " << y;
    return x + y;
}

double func_subtraction(double x, double y) {     // функция "-"  
    std::cout << x << " - " << y;
    return x - y;
}

double func_multiplication(double x, double y) {  // функция "*"  
    std::cout << x << " * " << y;
    return x * y;
}

double func_dividing(double x, double y) {        // функция "/"  
    std::cout << x << " / " << y;
    return x / y;
}


/*
Завдання 2. Написати програму, яка містить функцію, що
приймає як аргумент покажчики на три масиви та розмір
масивів, заносить у масив C суми елементів масивів А і В.
Розмір масивів однаковий.
*/
int main1() {
    size_t N = 10;           // размер массивов
    int* arr1 = new int[N];  // создание указателя и выделение памяти, массив1
    int* arr2 = new int[N];  // создание указателя и выделение памяти, массив2
    int* arr3 = new int[N];  // создание указателя и выделение памяти, массив3

    srand(time(NULL));       // сидирование для случайных чисел
    std::cout << "Array 1: \n";
    func_arr1(arr1, N);
    std::cout << "Array 2: \n";
    func_arr2(arr2, N);
    std::cout << "Array 3 (sum of elements from arrays 1 and 2: \n";
    func_arr3(arr1, arr2, arr3, N);

    delete[] arr1;  // освобождение памяти
    delete[] arr2;  // освобождение памяти
    delete[] arr3;  // освобождение памяти


    return 0;
}

void func_arr1(int* arr1, size_t length) {  // ф-ия создания и вывода массива1
    if (!arr1) {
        std::cout << "NULL pointer error";
        return;
    }
    for (size_t i = 0; i < length; i++) {
        arr1[i] = rand() % 20;
        std::cout << arr1[i] << ' ';
    }
    std::cout << std::endl;
}

void func_arr2(int* arr2, size_t length) {  // ф-ия создания и вввода массива2
    if (!arr2) {
        std::cout << "NULL pointer error";
        return;
    }
    for (size_t i = 0; i < length; i++) {
        arr2[i] = rand() % 20;
        std::cout << arr2[i] << ' ';
    }
    std::cout << std::endl;
}

void func_arr3                              // ф-ия создания и вывода итогового массива
(int* arr1, int* arr2, int* arr3, size_t length) {
    if (!arr3) {
        std::cout << "NULL pointer error";
        return;
    }
    for (size_t i = 0; i < length; i++) {
        arr3[i] = arr1[i] + arr2[i];
        std::cout << arr3[i] << ' ';
    }
    std::cout << std::endl;
}

