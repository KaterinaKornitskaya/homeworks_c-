﻿// dz_function1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <iomanip>

/*
 Написати функцію, яка приймає два параметри: 
 основа степеня і показник степеня, 
 та обчислює степінь числа на основі отриманих даних.
*/

int Function_MyPow(int number1, int pow1) {  // функция для возведения числа в степень

    long long res;  // long long для больших чисел
    res = pow(number1, pow1);
    return res;     // функция возврашает результат - число в степени
}

/*
 Написати функцію, яка отримує в якості параметрів 2 цілих числа
 та повертає суму чисел із діапазону між ними.
*/

int Function_Diapason(int number1, int number2) {  // функция для суммы чисел в промежутке чисел

    int sum = 0;  // переменная для суммы, накопительная, присваиваем 0
    for (int i = number1 + 1; i < number2; ++i) {
        sum += i;
    }
    return sum;   // функция возвращает сумму между числами
}

/*
  Число називається досконалим, якщо сума 
 всіх його дільників дорівнює йому самому. Напишіть 
 функцію пошуку таких чисел у введеному інтервалі.
*/
bool is_perfect(int number) {  // функция для поиска "идеального" числа

    int sum = 1;  // переменная для суммы, накопитальная, присаиваем 1, т.к. 1 делитель для всех чисел
    int d;        // переменная для производного
    for (d = 2; d * d < number; d++) {  // цикл до середины числа, т.к. дальше делителей не будет
        if (number % d == 0) {
            sum += d + number / d;      // суммируем все делители
        }
    }
    if (d * d == number) {
        sum += d + number/d;
    }
    return sum == number;  // функция возвращает сумму
}

void print_perfect(int from, int to) {  // функция для вывода идеального числа

    for (int n = from; n <= to; ++n) {  // в промежутке между указанными числами
        if (is_perfect(n)) {      // выводим числа из функции is_perfect
            std::cout << n << ' ';
        }
    }
}

/*
 Написати функцію, що визначає, 
 чи є «щасливим» шестизначне число.
*/
void Function_Lucky(int number) {  // функция для счастливого числа
    
    int div = 1;                              // переменная для делителя
    int sum1 = 0, sum2 = 0;                   // переменная для сумм 1ой и 2ой частей числа
    int number1 = number / 1000;              // число из первых трех цифр
    int number2 = number - (number1 * 1000);  // число из последний трех цифр

    while (div <= number1) {
        div *= 10;
    }
    while (div > 1) {  
        div /= 10;
        short n = number1 / div;
        sum1 += n;  // сумма цифр для первой части числа
        number1 -= n * div;
    }
    while (div <= number2) {
        div *= 10;
    }
    while (div > 1) {
        div /= 10;
        short n = number2 / div;
        sum2 += n;  // сумма цифр для второй части числа
        number2 -= n * div;
    }
    if (number < 100000 || number > 999999) {  // условие некорректного ввода
        std::cout << "Error: Incorrect number\n\n";
    }
    else if (sum1 == sum2) {     
        std::cout << "Yes, your number is lucky!\n\n";       
    }
    else {       
        std::cout << "No, it isn`t lucky number.\n\n";
    }     
}

/*
 Написати функцію, що виводить на екран передану їй гральну карту.
*/
void showCard(int _suit, int _num) {  // функция для вывода карты

    int filler = 6;                   // заполнение пробелами в функции setw()
    char                              // символьные переменные для 
        up_lc = 218, up_rc = 191,     // up_lc - верхний левый угол, up_rc - верхний правый угол    
        hl = 196, vl = 179,           // hl - горизонтальная линия, vl  -вертикальная линия
        down_lc = 192, down_rc = 217; // down_lc - нижний левый угол, down_rc - нижний правый угол 

    char charCard[13] =  // массив символов для карт
    { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' };
    _suit += 2;  // масти начинаются с тройки 

   system("cls");  
    std::cout << up_lc << std::setfill(hl) << std::setw(8) << up_rc << std::endl;  
    if (_num == 10) {  // если карта 10
        filler--;      // уменьшаяем величину автозаполнения
        std::cout << vl << "1" << charCard[_num - 1] << (char)_suit << std::setfill(' ') 
            << std::setw(filler) << vl << std::endl;  // дополнительно выводим "1"
    }
    else {
        std::cout << vl << charCard[_num - 1] << (char)_suit << std::setfill(' ') 
            << std   ::setw(filler) << vl << std::endl;  // ести карта не 10, то выводим ее название из массива
    }  
    std::cout << vl << std::setw(8) << vl << std::endl;
    std::cout << vl << std::setw(8) << vl << std::endl;
    std::cout << vl << std::setw(8) << vl << std::endl;
    std::cout << vl << std::setw(8) << vl << std::endl;
    std::cout << vl << std::setw(8) << vl << std::endl;
    std::cout << vl << std::setw(8) << vl << std::endl;
        
    if (_num == 10) {  // опять проверяем, если карта 10
        std::cout << vl << std::setfill(' ') << std::setw(filler) 
            << "1" << charCard[_num - 1] << (char)_suit << vl << std::endl;
    }
    else {
        std::cout << vl << std::setfill(' ') << std::setw(filler) 
            << charCard[_num - 1] << (char)_suit << vl << std::endl;
    }
    std::cout << down_lc << std::setfill(hl) << std::setw(8) << down_rc << std::endl;
 
}
                // переменные, которые вводит пользователь:
int n1, npow;   // для функции числа и степени
int n2, n3;     // для функции суммы чисел между двумя числами
int n4, n5;     // для функции "идеальных" чисел между двумя числами
int n6;         // для функции "счастливого" числа
int suit, num;  // для масти и карты
int main()
{
    system("cls");
    std::cout << "Enter suit\n1 - Hearts\n2 - Diamonds\n3 - Clubs\n4 - Spades" << std::endl;
    std::cin >> suit;
    if (suit < 1 || suit >4) {  // проверка некорректного ввода масти
        std::cout << "Error: Incorrect suit\n";
        system("pause");
        return -1;
    }
    system("cls");
    std::cout << "Enter card\n1 - Ace \n2 - 2\n3 - 3\n4 - 4\n5 - 5\n6 - 6\n7 - 7\n8 - 8\n9 - 9\n10 - 10\n11 - J\n12 - Q\n13 -K" 
        << std::endl;
    std::cin >> num;
    if (num < 1 || num > 13) {  // проверка некорректного ввода карты
        std::cout << "Error: Incorrect card\n";
        system("pause");
        return -2;
    }
    showCard(suit, num);

    system("pause");
 
    std::cout << "\nPower of number\n";
    std::cout << "Enter number and power: ";
    std::cin >> n1 >> npow;
    std::cout << "Result: " << Function_MyPow(n1, npow) << "\n";
    system("pause");
    
    std::cout << "\nSum between two numbers\n";
    std::cout << "Enter two numbers: ";
    std::cin >> n2 >> n3;
    std::cout << "Sum of numbers between your numbers is: " 
        << Function_Diapason(n2, n3) << "\n";
    system("pause");

    std::cout << "\nPerfect numbers\n";
    std::cout << "Enter two numbers: ";
    std::cin >> n4 >> n5;
    std::cout << "Perfect numbers between your numbers is: ";
    print_perfect(n4, n5); std::cout << std::endl;
    system("pause");

    std::cout << "\n\nLucky number\n";
    std::cout << "Enter 6-digit number: ";
    std::cin >> n6;
    Function_Lucky(n6); std::cout << std::endl;

    return 0;
}




