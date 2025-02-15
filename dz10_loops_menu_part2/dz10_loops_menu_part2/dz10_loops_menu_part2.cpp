﻿// dz10_loops_menu_part2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <stdlib.h>  // эта библеотека нужка, что бы работало system("cls"); правильно???
#define gotoxy(x,y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y })

int main()
{
    /*
    Користувач вводить число. Визначити кількість цифр у цьому числі,
    порахувати їхню суму та середнє арифметичне.
    Визначити кількість нулів у цьому числі.
    Спілкування з користувачем організувати через меню.
    */

    char button;       // символьная переменная для клавиш  
    long long number;  // число, вводимое пользователем
    
    std::cout << "Enter number: ";
    std::cin >> number;
    std::cout << std::endl;
                                                                                          
    short n;                      // переменная для цифр в числе                          | эти переменные были изначально
    long long divider;            // делитель                                             | в цикле while, который описывает divider
    short number_of_digits = 0;   // переменная для результата - количество цифр в числе  | но тогда у меня не работают фрмулы:
    short sum = 0;                // переменная для результата - сумма цифр в числе       | срабатывает только первая в case 1,
    short arithmetical_mean = 0;  // переменная для результата - количество цифр в числе  | остальные case выдают 0.
    short number_of_zeros = 0;    // переменная для результата - количество нулей         |
    divider = 1;                  // присваивание делителю значения 1                     |
        
    do {  // общий цикл, который позволяет не выходить из программы
        system("cls");
    
        std::cout
        << " -------------Menu--------------" << std::endl
        << " The number of digit in a number" << std::endl
        << " The sum of digit in a number" << std::endl
        << " Arithmetical mean of digits" << std::endl
        << " The number of zeros in a number" << std::endl;
   
        gotoxy(0, 1);
        std::cout << ">";
        short y = 1;
        do {
            button = _getch();
            if (button == 0 || button == -32) {
                button = _getch();
            }
            gotoxy(0, y);
            std::cout << ' ';

            if (button == 80) {  // условие для книпки "вниз"
                y += 1;
                if (y > 4) {
                    y = 1;
                }
            }

            if (button == 72) {  // условие для кнопки вверх
                y -= 1;
                if (y < 1) {
                    y = 4;
                }
            }

            gotoxy(0, y);
            std::cout << '>';
        } while (button != 27 && button != 13 && button != 32);

        gotoxy(0, 6);

        if (button == 27) {  // условие для кнопки "ESC"
            std::cout << "Bye!";
            return -1;
        }
   
        while (divider <= number) {  // цикл для делителя
            divider *= 10;
        }
        while (divider > 1) {        // цикл для вычисления цифр в числе и результатов
            divider /= 10;
            n = number / divider;
            sum += n;
            number_of_digits += 1;
            if (n == 0) {
                number_of_zeros += 1;
            }
            arithmetical_mean = sum / number_of_digits;
            number -= n * divider;
        }
        switch (y) {
            case 1:  // пункт меню 1 - количество цифр в числе
            std::cout << "The number of digits: " << number_of_digits;
            break;

            case 2:  // пункт меню 2 - сумма цифр
            std::cout << "Sum: " << sum;
            break;

            case 3:  // пункт меню 3 - среднее арифметическое цифр числа
            std::cout << "Arithmetical mean of digit: " << arithmetical_mean;
            break;

            case 4:  // пункт меню 4 - колличество 0 в числе
            std::cout << "The number of zeros in a number: " << number_of_zeros;
            break;
        }
        std::cout << std::endl;
        system("PAUSE");
    } while (true);
    
    // if (button == 32)  | в конце я хотела добавить кнопку для выхода
    // {                  | но оно не работает
    //    return 0;       |
    // }                  |
   
    return 0;

}



int main1()
/*
Написати програму, яка виводить на екран
шахову дошку із заданим розміром клітинки.

*/
{
    short n;                        // заданый размер клетки, вводит пользователь
    short standart_chess_size = 8;  // стандартное количество клеток на шахматной доске
    
    std::cout << "Enter cage size: ";
    std::cin >> n;

    for (int i = 0; i < standart_chess_size / 2; ++i)          // цикл для строк; standart_chess_size / 2 -->
                                                               // т.к. зацикливаю не все строки, а два вложенных (A1 и A2) цикла для двух рядов клеток
    { 
        for (int i = 0; i < n; ++i)                            // вложенный цикл А1 для первого ряда клеток - строки
        {
            for (int j = 0; j < standart_chess_size / 2; ++j)  // вложенный цикл B1 для первого ряда клеток для повторений "*-" в первом ряду клеток
                                                               // standart_chess_size / 2 --> т.к. "*-" - повторяется 4 раза
            {

                for (int k = 0; k < n; ++k)                    // вложенный цикл C1.1 для "*"
                {
                    std::cout << '*';
                }
                for (int k = 0; k < n; ++k)                    // вложенный цикл C1.2для "-"
                {
                    std::cout << '-';  
                }          
            }
            std::cout << std::endl;      
        }
        for (int i = 0; i < n; ++i)                            // вложенный цикл А2 для второго ряда клеток - строки
        {
            for (int j = 0; j < standart_chess_size / 2; ++j)  // вложенный цикл B2 для второго ряда клеток для повторений "*-" 
            {

                for (int k = 0; k < n; ++k)                    // вложенный цикл C2.1 для "-"
                {
                    std::cout << '-';
                }
                for (int k = 0; k < n; ++k)                    // вложенный цикл C2.2 для "*"
                {
                    std::cout << '*';
                }
            }
            std::cout << std::endl;
        }       
    }

    return 0;

}

