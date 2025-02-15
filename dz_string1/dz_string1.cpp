﻿// dz_string1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>

// forward declaration
void replace_sym(char* str);   // ф-ия замены пробела на табуляцию
void num_of_sym(char* str);    // ф-ия для подсчета символов в строке
void num_of_words(char* str);  // ф-ия для вывода кол-ва слов
bool palindrom(char* str);     // ф-ия для определения, является ли 
                               // слово палиндромом

int main() {
    const size_t BUF_SIZE = 50;              // задаем макс размер строки
    char* str1 = new char[BUF_SIZE];         // указатель на строку1, выделение памяти
    strcpy(str1, "It is the 1-st string.");  // копирование строки1
    std::cout << str1 << std::endl;
    std::cout << std::endl;

    //Підрахувати кількість слів у введеному реченні.
    num_of_words(str1);
    std::cout << std::endl;

    // Дан рядок символів. Замінити в ньому всі пробіли на табуляцію.
    std::cout << "\nRepllacing spaces with tabs: \n";
    replace_sym(str1);
    std::cout << std::endl;

    // Дан рядок символів. Визначити кількість літер, цифр та інших 
    //  символів, присутніх у рядку.
    std::cout << "Amount of symbols: \n";
    num_of_sym(str1);
    std::cout << std::endl;

    // Дан рядок символів. Перевірити, чи є цей рядок паліндромом.
    char* str2 = new char[BUF_SIZE];   // указатель на строку2 и выделение памяти
    std::cout << "Is this word a palindrome?: ";
    std::cin.getline(str2, BUF_SIZE);  // строку2 вводит пользователь
    if (palindrom(str2)) {             // если ф-ия палиндром вернула true
        std::cout << "Yes.";           // выводим "Да"
    }
    else {                             // если ф-ия палиндром вернула false
        std::cout << "No.";            // выводим "Нет"
    }
    std::cout << std::endl;

    return 0;

}

void replace_sym(char* str) {              // ф-ия замены пробела на табуляцию
    size_t length = strlen(str);           // длина строки
    for (size_t i = 0; i < length; i++) {  // цикл до длины строки
        if (str[i] == ' ') {               // заменяем все пробелы
            str[i] = '\t';                 //  на табуляцию
        }
    }
    std::cout << str << std::endl;         // вывод итоговой строки  
}

void num_of_sym(char* str) {      // ф-ия для подсчета символов в строке   
    size_t length = strlen(str);  // определяем размер строки
    int letter = 0;               // накопительная переменная для букв
    int num = 0;                  // накопительная переменная для цифр
    int sym = 0;                  // накопительная переменная для символов пробел, точка, запятая
    int other = 0;                // накопительная переменная для других символов
    
    for (size_t i = 0; i < length; i++) {          // цикл - проходим до конца строки   
        if (str[i] >= 48 && str[i] <= 57) {        // условие, если элемент - цифра
            num += 1;
        } 
        else if (str[i] >= 65 && str[i] <= 90      // условие, если элемент - заглавная
              || str[i] >= 97 && str[i] <= 122) {  //  или строчная буква
                letter += 1;
        }
        else if (str[i] == 32                      // условие, если элемент - пробел,
              || str[i] == 44                      //  точка,
              || str[i] == 46) {                   //  запятая
                sym += 1;
        }
        else {                                     // другие элементы
                other +=1;
        }   
    }
    std::cout << "Letters: " << letter << std::endl;
    std::cout << "Numbers: " << num << std::endl;
    std::cout << "Symbols (space, dot, comma): " << sym << std::endl;
    std::cout << "Other symbols: " << other << std::endl;
}

void num_of_words(char* str) {    // ф-ия для вывода кол-ва слов
    size_t length = strlen(str);  // длина строки
    int spaces = 0;               // накопительная переменная для кол-ва пробелов
   
    for (size_t i = 0; i < length; i++) {
        if (str[i] == 32) {       // если элемент - пробел
            spaces += 1;          //  плюсуем пробелы
        }       
    }     
    std::cout << "Number of word: " 
        << spaces + 1;            // для вывода слова к кол-ву пробелов добавить 1   
}

bool palindrom(char* str) {                // ф-ия для определения, является ли слово палиндромом
    size_t length = strlen(str);           // определяем длину строки
    
    for (size_t i = 0; i < length; i++) {  // цикл до конца строки       
        if (str[i] != str[length -i-1]) {  // сравниваем 1ый и последний элементы
            return false;                  // если не равны - ф-ия возвращает false
        }
    }
    return true;                           // если равны - ф-ия возвращает true   
}
