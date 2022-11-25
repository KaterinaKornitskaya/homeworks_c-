// Project_files.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>



int main() {
    FILE* f3;
    FILE* f2;

    f3 = fopen("file_count.txt", "rt");  // открытие файла 
    f2 = fopen("file_two.txt", "wt");  // открытие файла 



    if (f3 == NULL) {                     // после попытки открытия проверить успешность
        std::cout << "File_count open error\n";
        return -1;
    }
    if (f2 == NULL) {                    // после поывтки открытия проверить успешность
        std::cout << "File_two open error\n";
        return -1;
    }
    //std::cout << "File was opened\n";


   /*
    fputs("Hello, world\n", f3);          // запись строки в файл
    fputs("Hello, people\n", f3);         // запись строки в файл
    fputs("Give me 2 apples", f3);            // запись строки в файл
    fflush(f3);                           // когда все отправлено в буфер -записать в файл
    */


    const size_t SIZE = 50;  // переменная для макс размера строки
    char str[SIZE];

    char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };  // массив для гласных букв

    int symbol = 0;  // накопительная переменная для символов
    int rows = 0;  // накопительная переменная для строк
    int vowel = 0;  // накопительная переменная для гласных
    int consonant = 0;  // накопительная переменная для согласных
    int digit = 0;  // накопительная переменная для цифр
    int letter = 0;  // накопительная переменная для букв



   
    while (!feof(f3)) {
        fgets(str, SIZE, f3);
        size_t length = strlen(str);

        for (size_t i = 0; i < length; i++) {
            if (int(str[i]) >= 32 && int(str[i]) <= 126) {
                symbol++;
            }

            if ((int(str[i]) >= 65 && int(str[i]) <= 90) ||         // если элемент массива входит в диапазон - это буква
                (int(str[i]) >= 97 && int(str[i]) <= 122))
            {
                letter++;
                for (size_t j = 0; j < 6; j++)                      // запускаем цикл для поиска гласных
                {
                    if ((int(str[i]) == int(vowels[j])) ||
                        (int(str[i]) == int(vowels[j] - 32))) {
                        vowel++;
                    }
                }
                                                          // увеличиваем переменную для счета букв
            }

            consonant = letter - vowel;

            if (int(str[i]) >= 48 && int(str[i]) <= 57) {
                digit++;
            }



        }
        ++rows;
        fgets(str, SIZE, f3);

    }

    fprintf(f2, "Characters = %d\n", symbol);                       // форматированный вывод в файл
    fprintf(f2, "Strings = %d\n", rows);
    fprintf(f2, "Vowels = %d\n", vowel);
    fprintf(f2, "Consonants = %d\n", consonant);
    fprintf(f2, "Digits = %d\n", digit);
    fflush(f2);

    fclose(f3);                                                     // закрываем файлы - освобождаем системный ресурс
    // когда все на запись отправлено, то сбрасываем буфер (на диск)
    fclose(f2);

    return 0;




}