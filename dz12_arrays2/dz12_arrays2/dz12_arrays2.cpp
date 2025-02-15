﻿// dz12_arrays2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>
#include <conio.h>


int main1() {
    /*
     Напишіть програму, яка створює двовимірний 
     масив і заповнює його за таким принципом: користувач 
     вводить число (наприклад, 3) перший елемент масиву 
     приймає значення цього числа, наступний елемент масиву 
     приймає значення цього числа + 1 (тобто 4 для нашого 
     прикладу), третій елемент масиву — попередній елемент 
     + 1 (тобто 5 для нашого прикладу). Створений масив 
     вивести на екран.
    */
   
    const int S1 = 4;  // константное значения для размера массива
    const int S2 = 3;  // константное значения для размера массива
    size_t i, j;  // переменные для массива
    int num;
    std::cout << "Enter number";
    std::cin >> num;  // число, которое вводит пользователь
    int arr[S1][S2];
    for (i = 0; i < S1; i++) {  // цикл для выполнения "+1" для каждого след. элемента
        for (j = 0; j < S2; j++) {
            arr[i][j] = num;
            num += 1;
        }
    }
    for (i = 0; i < S1; i++) {  // цикл для вывода массива
        for (j = 0; j < S2; j++) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    
    return 0;
}


int main2() {
    /*
    Напишіть програму, яка створює двовимірний 
масив і заповнює його за таким принципом: користувач 
вводить число (наприклад, 3) перший елемент масиву 
приймає значення цього числа, наступний елемент масиву приймає 
значення цього числа помноженого на 2 
(тобто 6 для нашого прикладу), третій елемент масиву — 
попередній елемент помножений на 2 (тобто 6*2=12 для 
нашого прикладу). Створений масив вивести на екран.
    */

    const int S1 = 4;
    const int S2 = 3;
    int i, j;
    int num;
    
    std::cout << "Enter number";
    std::cin >> num;
    int arr[S1][S2];
    for (i = 0; i < S1; i++) {
        for (j = 0; j < S2; j++) {            
            arr[i][j] = num;
            num = (num * 2);
            arr[i][j] = num;
        }
    }
    for (i = 0; i < S1; i++) {
        for (j = 0; j < S2; j++) {          
                std::cout << arr[i][j] << ' ';          
        }
        std::cout << std::endl;
    }

    return 0;
}

int main() {
    /*
    Створіть двовимірний масив. Заповніть його 
випадковими числами і покажіть на екран. Користувач 
вибирає кількість зрушень і положення (вліво, вправо, 
вгору, вниз). Виконати зрушення масиву і показати на 
екран отриманий результат. Зрушення циклічне. 

Наприклад, якщо ми маємо такий масив. 
1 2 0 4 5 3
4 5 3 9 0 1
і користувач вибрав зрушення на 2 розряди вправо, то 
ми отримаємо:
5 3 1 2 0 4
0 1 4 5 3 9.
   */

    const int S1 = 5;
    const int S2 = 7;
    int arr[S1][S2];
    short shift;  // переменная дял кол-ва сдвигов, вводит пользователь
    char c;  // символьгая переменная для ввода символа с клавиатуры 
   

    srand(time(NULL));
    int x, y;
    for (x = 0; x < S1; ++x) {
        for (y = 0; y < S2; ++y) {
            arr[x][y] = rand() % 10;  // рандомное заполнение массива
            std::cout << arr[x][y] << ' ';  // вывод массива
        }
        std::cout << std::endl;
    }
   std::cout << "To move array: enter number of shift and direction:\n";
   std::cin >> shift;

    c = _getch();  // считывание клавиши, нажатой на клавиатуре
    if (c == -32 || c == 0) {
        c = _getch();  // повторное считывание
    }
   
    std::cout << std::endl;
 
    if (c == 77) {  // сдвиг вправо
        for (int k = 0; k < shift; k++) {
            for (x = 0; x < S1; ++x) {
                int tmp1 = arr[x][0];
                for (int y = 0; y < S2 - 1; y++) {
                    arr[x][y] = arr[x][y + 1];
                }
                arr[x][S2 - 1] = tmp1;
            }
        }
    }
     
    else if (c == 75) {  // сдвиг влево
        for (int k = 0; k < shift; k++) {
            for (x = 0; x < S1; ++x) {
                int tmp2 = arr[x][S2 - 1];
                for (int y = S2 - 1; y > 0; y--) {
                    arr[x][y] = arr[x][y - 1];
                }
                arr[x][0] = tmp2;
            }
        }
    }
  
    for (x = 0; x < S1; ++x) {  // вывод результата сдвига 
        for (y = 0; y < S2; ++y) {
            std::cout << arr[x][y] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
      
}



