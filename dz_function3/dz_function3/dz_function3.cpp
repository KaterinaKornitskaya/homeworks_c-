﻿// dz_function3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <conio.h>

/*
 Завдання 1. Написати перевантажені функції (int, double, char)
 для виконання таких завдань:
 ■ Ініціалізація квадратної матриці;
 ■ Вивід матриці на екран;
 ■ Визначення максимального й мінімального елемента 
   на головній діагоналі матриці;
 ■ Сортування елементів за зростанням окремо для 
   кожного рядка матриці.
*/

// прототипы всех используемых функций 
void init_array(int arr_int[][5], int N1, int N2);  
void init_array(double arr_dbl[][5], int N1, int N2);
void print_array(char arr_ch[][5], int N1, int N2);
void print_array(int arr_int[][5], int N1, int N2);
void print_array(double arr_dbl[][5], int N1, int N2);
double print_maxmin_diag(double arr_dbl[][5], int N1, int N2);
int print_maxmin_diag(int arr_int[][5], int N1, int N2);
void sort_array(double arr_dbl[][5], int N1, int N2);
void sort_array(int arr_int[][5], int N1, int N2);


void init_array(int arr_int[][5], int N1, int N2) {  // функция, инициализация квадратной матрицы, тип int
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            arr_int[i][j] = rand() % 50;
        }
    }
}

void init_array(double arr_dbl[][5], int N1, int N2) {  // функция, инициализация квадратной матрицы, тип double
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            arr_dbl[i][j] = rand() % 1000 / 10.0;
            // arr_dbl[i][j] = rand()/static_cast<double>(2);
        }
    }
}

void print_array(char arr_ch[][5], int N1, int N2) {  // функция, инициализация и вывод на экран массива типа char
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            arr_ch[i][j] = _putch('*');
        }
        std::cout << std::endl;
    }
}

void print_array(int arr_int[][5], int N1, int N2) {  // функция, вывод на экран массива, тип int
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            std::cout << arr_int[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void print_array(double arr_dbl[][5], int N1, int N2) {  // функция, вывод на экран массива, тип double
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            std::cout << arr_dbl[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

double print_maxmin_diag(double arr_dbl[][5], int N1, int N2) {  // функция, вывод макс и мин числа главной диагонали double массива
    double max = 0;
    double min = arr_dbl[0][0];
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            if (i == j) {               
                if (max < arr_dbl[i][j]) {
                    max = arr_dbl[i][j];
                }
                if (min > arr_dbl[i][j]) {
                    min = arr_dbl[i][j];
                }               
            }           
        }        
    }
    std::cout << "Max: " << max << std::endl;
    std::cout << "Min: " << min << std::endl;
    return min, max;
}

int print_maxmin_diag(int arr_int[][5], int N1, int N2) {  // функция, вывод макс и мин числа главной диагонали int массива
    int max = 0;
    int min = arr_int[0][0];
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            if (i == j) {
                if (max < arr_int[i][j]) {
                    max = arr_int[i][j];
                }
                if (min > arr_int[i][j]) {
                    min = arr_int[i][j];
                }
            }
        }
    }
    std::cout << "Max: " << max << std::endl;
    std::cout << "Min: " << min << std::endl;
    return min, max;
}

void sort_array(double arr_dbl[][5], int N1, int N2) {  // функция, сортировкаэлементов строк по возрастанию, массив типа double
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            for (int k = N2 - 1; k > j; k--) {
                if (arr_dbl[i][k-1] > arr_dbl[i][k]) {
                    double tmp = arr_dbl[i][k];
                    arr_dbl[i][k] = arr_dbl[i][k - 1];
                    arr_dbl[i][k - 1] = tmp;
                }
            }
            std::cout //<< i << ":" 
                << arr_dbl[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void sort_array(int arr_int[][5], int N1, int N2) {  // функция, сортировкаэлементов строк по возрастанию, массив типа int
    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < N2; ++j) {
            for (int k = N2 - 1; k > j; k--) {
                if (arr_int[i][k - 1] > arr_int[i][k]) {
                    int tmp = arr_int[i][k];
                    arr_int[i][k] = arr_int[i][k - 1];
                    arr_int[i][k - 1] = tmp;
                }               
            }
            std::cout << arr_int[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main1()
{
    const size_t N1 = 5;     // кол-во строк квадратной матрицы, константа
    const size_t N2 = 5;     // кол-во столбцов квадратной матрицы, константа
    int arr_int[N1][N2];     // двухмерный массив типа int
    double arr_dbl[N1][N2];  // двухмерный массив типа double
    char arr_ch[N1][N2];     // двухмерный массив типа char
    
    srand(time(NULL));  // сидирования для рандомных чисел

    std::cout << "Two-dimensional array, type \"int\": \n";
    init_array(arr_int, N1, N2);
    print_array(arr_int, N1, N2);

    std::cout << "\nMax & min elements on the main diagonal in the two-dimensional array, type \"int\": \n";
    print_maxmin_diag(arr_int, N1, N2);

    std::cout << "\nSort a two-dimensional array, type \"int\", from small to large element: \n";
    sort_array(arr_int, N1, N2);
    
    std::cout << "\nTwo-dimensional array, type \"double\": \n";
    init_array(arr_dbl, N1, N2);
    print_array(arr_dbl, N1, N2);

    std::cout << "\nMax & min elements on the main diagonal in the two-dimensional array, type \"double\": \n";
    print_maxmin_diag(arr_dbl, N1, N2);

    std::cout << "\nSort a two-dimensional array, type \"int\", from small to large element: \n";
    sort_array(arr_dbl, N1, N2);

    std::cout << "\nTwo-dimensional array, type \"char\": \n";
    print_array(arr_ch, N1, N2);

    
    return 0;
}

/*
 Завдання 2. Написати рекурсивну функцію знаходження 
 найбільшого спільного дільника двох цілих чисел.
*/

int MaxDiv(int n, int m) {
    if (n == m) {
        return n;
    }
    else {
        if (n > m)
            return MaxDiv(n - m, m);
        else
            return MaxDiv(n, m - n);
    }
}

int main2() {
    int n1, n2;
    std::cout << "Max divider of two numbers. Enter two numbers: \n";
    std::cin >> n1 >> n2;
    std::cout << "Max divider: " << MaxDiv(n1, n2);

    return 0;
}

/*
 Написати гру «Бики та корови». Програма 
 «загадує» чотиризначне число і гравець має вгадати його. 
 Після введення користувачем числа програма повідомляє, 
 скільки цифр числа вгадано (бики) і скільки цифр вгадано 
 і стоїть на потрібному місці (корови). Після відгадування 
 числа на екран необхідно вивести кількість зроблених 
 користувачем спроб. У програмі необхідно використовувати рекурсію.
*/


    int* m = new int[4];
    int* q = new int[4];
    static int sproba = 1;
    int* randNumber() {
        for (int i = 0; i < 4; i++) 
            *(m + i) = rand() % 10;
        return m;
    }
    int* digits(int n) {
        for (int i = 3; i >= 0; i--) {
            *(q + i) = n % 10;
            n /= 10;
        }
        return q;
    }
    void Count(int* x, int* y, int n, int* bull, int* cow) {
        *bull = *cow = 0;
        for (int i = 0; i < n; i++) {
            if (*(x + i) == *(y + i)) {
                (*bull)++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((*(x + i) == *(y + j)) && (i != j)) {
                    (*cow)++;
                }
            }
        }
    }
    void game(int* r, int* N) {
        *N = sproba;
        std::cout << "Enter yor number: ";
        int number;
        std::cin >> number;
        int* b = digits(number);
        int bull, cow;
        Count(r, b, 4, &bull, &cow);
        std::cout << "Bulls = " << bull << ", cows = " << cow << std::endl;
        sproba++;
        if (bull == 4) {
            std::cout << "Ok!\n";
        }
        else {
            game(r, N);
        }
    }
    void main() {
        int m = 0;
        srand(time(NULL));
        int* a = randNumber();
        game(a, &m);
        std::cout << "Win in " << m << " moves!\n";
    }


   // Задания про рекурсия я списала с Интернета, рекурсия мне пока не далась((

