// Project3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>

int main1()
{
    char str1[] = "Hello";
    // задание: создать копию строки str1
    // неправильное решение (забыли про \0)
    // char* str2 = new char[5];
    // for (size_t i = 0; i < 5; i++)
    // {
    //     str2[i] = str1[i];
    // }
    // std::cout << str1 << std::endl;
    // std::cout << str2 << std::endl;

    return 0;
}
/*
    Строки
    Работу со строками делят на два вида:
    char*  -- старый тип, может работать в С
    std::string  -- специальный класс, создающий "безопасную" оболочку

    Часть 1 : char*
    Строка представляет собой обычный массив символов
    Главной особенностью строк является то, что они завершаются
    дополнительным символом '\0' (символ с кодом 0). Это позволяет
    Главной особенностью строк является то, что они завершаются
    дополнительным символом '\0' (символ с кодом 0). Это позволяет
    определять их размер (или признак конца)
    НО!! Создает опасность:
     - если этот символ "забыть", то строка становится бесконечной
     - про дополнительный размер (+1 символ) нужно помнить при
        расчете размера массива "Hello" -> "Hello\0"
  функции работы со строками #include <string.h>
   strcpy(str, "Hello World"); - копирование строк
   strcpy_s(str, 14, "Hello world"); - с улучшенной безопасностью, 
   ограничивает колличество копируемых символов - 14
   strlen(str) - длина строки
   strcat(str, str2); - конкатенация строк - str2 дописывается к str - 
   Важно - в str должен быть запас

    strcmp(str, "Hello, World"); - сравнение строк - caseSensitive
   _stricmp(str, "Hello, World"); - caseInsensitive

   !! if (strcmp() ) ... тест на неравенство
      if (strcmp() == 0 ) - на равенство

    
    !! нельзя сравнивать втроки обычным ==
      if(str == "Hello") - нельзя, не сработает, это сравнение адресов, очевидно, что адреса разные

    !! внимание на сравнение чисел в строках
      120 < 21 - 1ая единица и 2ка сравниваются, 1 меньше, результат неверный

*/

int main2()
{
    // функции работы со стороками
    char* str = new char[16];  // даем исходное место для символов в строке
    strcpy(str, "Hello, World");  // 1 вариант
    strcpy_s(str, 14, "Hello, world");  // 2 вариант

    int len = strlen(str);  // длина строки !! только символы
    
    // конкатенация строк - соединение
    char* str2 = new char[4];
    strcpy(str2, "!!!");  //    12      3  1
    strcat(str, str2);  // Hello, world!!!\0

    // прямой доступ к символам строки - разименование массива
    str[7] = 'w';

    // сравнение строк
    int res = strcmp(str, "Hello, World");  // res: -1 0 +1
    std::cout << res << std::endl;

    std::cout << str << " - " << len << std::endl;
    return 0;
}

void replace_spaces(char* str) {  // функция - заменить все пробелы на "-"
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        if (str[i] == ' ') {
            str[i] = '-';
        }
    }
    
}

int main3() {
    // пользователь вводит строку
    const size_t BUFFER_SIZE = 100;
    char* str = new char[BUFFER_SIZE];

    std::cout << "Enter string: ";
    // std::cin >> str;  // ввод первого слова
    std::cin.getline(str, BUFFER_SIZE);  // ввод всей строки
    
    // заменить все пробелы на "-"
    replace_spaces(str);

    std::cout << str << std::endl;  

    return 0;
}

int main() {
    // задание: пользователь вводит логин и пароль
    // если логин - admin, а пароль - qwerty, то выдается приветствие
    // иначе - ACCESS DENIED
    const size_t BUFFER_SIZE = 20;
    char* str1 = new char[BUFFER_SIZE];
    char* str2 = new char[BUFFER_SIZE];
   
    std::cout << "Enter login: ";    
    std::cin.getline(str1, BUFFER_SIZE); 

    std::cout << "Enter password: ";
    std::cin.getline(str2, BUFFER_SIZE);

    if (strcmp(str1, "admin") == 0 
        && strcmp(str2, "qwerty") == 0) {
        std::cout << "Hello, admin";
    }
    else {
        std::cout << "ACCESS DENIED";
    }

    return 0;
}
