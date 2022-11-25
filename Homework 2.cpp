// Homework 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>






int main14()
/*
Користувач вводить з клавіатури час у секундах. 
Необхідно написати програму, яка переведе введені користувачем секунди в години, хвилини, секунди і виводить їх на екран.
*/
{
    int time;

    std::cout << "Enter the time (in seconds):\n";
    std::cin >> time;
    int h = time / 3600;
    int minsec = time % 3600;
    int min = minsec / 60;
    int sec = minsec % 60;

    std::cout << h << " hours " << min << " minutes " << sec << " seconds\n";

    return 0;
}

int main13()
/*
Задані три опори R1, R2, R3. Обчислити
значення опору R0 за формулою: 1/R0 = 1/R1+1/R2+1/R3.
Контрольний приклад: R1=2, R2=4, R3=8 R0 = 1.142857.
*/
{
    float R1;
    float R2;
    float R3;
    float R0;

    std::cout << "Enter R1\n" << "Enter R2\n" << "Enter R3\n";
    std::cin >> R1 >> R2 >> R3;
    R0 = 1 / (1 / R1 + 1 / R2 + 1 / R3);
    std::cout << "R0 = " << R0;

    return 0;
}

int main()

// Напишите программу, которая вычисляем объём шара.

{
    setlocale(LC_ALL, "Russian");
    float r;
    float v;

    
    std::cout << "Вычисление объёма шара.\n" << "Введите радиус\n";
    std::cin >> r;
    v = 4/3 * M_PI * pow (r,3);      // не получается формула, не работает
    std::cout << "Объем шара = " << v << " .";

    return 0;
}


int main11()
/*
Написать программу вычисления расстояния между населенными пунктами, изображенными на карте. 
Ниже приведен рекомендуемый вид экрана во время выполнения программы.
Вычисление расстояния между населенными пунктами
Введите исходные данные:
Масштаб карты (количество километров в одном сантиметре) -> 120.
Расстояние между точками, изображающими населенные пункты (см) -> 3.5.
Расстояние между населенными пунктами 420 км.
*/
{ 
    setlocale(LC_ALL, "Russian");

    float x;
    float y;
    float z;

    std::cout << "Вычисление расстояния между населенными пунктами\n"
        << "Введите исходные данные:\n"
        << "Масштаб карты (количество километров в одном сантиметре) -> ";
    std::cin >> x;
    std::cout << "Расстояние между точками, изображающими населенные пункты (см) -> ";
    std::cin >> y;
    z = x * y;
    std::cout << "Расстояние между населенными пунктами " << z << " км.\n";

    return 0;
}

int main10()
/*
 Написать программу вычисления объема параллелепипеда. Ниже приведен рекомендуемый вид экрана
во время выполнения программы.
Вычисление объема параллелепипеда.
Введите исходные данные:

Длина (см) -> 9;
Ширина (см) -> 7.5;
Высота (см) -> 5;
Объем: 337.50 куб. см.
*/
{
    setlocale(LC_ALL, "Russian");

    float l;
    float w;
    float h;
    float v;

        std::cout << "Объём параллелепипеда\n" << "Введите длину в см\n";
        std::cin >> l;
        std::cout << "Введите ширину в см\n";
        std::cin >> w;
        std::cout << "Введите высоту в см\n";
        std::cin >> h;
        v = l * w * h;
        std::cout << "Объем: " << v << " куб.см.\n";

    return 0;
}

int main9()
/*
Пользователь вводит с клавиатуры денежную
сумму в гривнах и копейках (гривны и копейки вводятся
в разные переменные). Сумма может быть введена как
правильно (например 19 грн. 90 коп), так и неправильно
(например 22 грн. 978 коп). Написать программу, которая,
используя только линейный алгоритм, осуществит корректировку введенной денежной суммы в правильную форму.
Например, если пользователь ввел 11 грн. 150 коп,
программа должна вывести на экран сумму 12 грн. 50 коп.
*/
{
    int hrn;
    int kop;
    int h;
    int k;

    std::cout << "Enter hryvnia\n";
    std::cin >> hrn;
    std::cout << "Enter kop.\n";
    std::cin >> kop;

    h = hrn + (kop / 100);
    k = kop % 100;

    std::cout << h << " hrn. " << k << " kop. ";

    return 0;
}



int main7()
{
/*
Пользователь вводит год. Необходимо написать программу, которая выведет количество дней в этом 
году. При написании программы использовать линейный 
алгоритм (конструкции условного выбора не использовать). Например, пользователь ввел год 2004, программа 
сообщает, что в этом году 366 дней в следующей форме:
In 2004 year = 366 days
*/
    int year = 2004;
    int day = 366;
    
    std::cout << "Enter current year, please.\n";
    std::cin >> year;
    std::cout << "In " << year << " = " << day << " days.\n";

    return 0;

}

int main8()
/*
предыдущая задача, только с условием. Без условия как еще указать, високосный год или нет????
*/
{
    int year;

    std::cout << "Enter current year, please.\n";
    std::cin >> year;
    if (year % 4 == 0 && year % 100 != 0
        || year % 400 == 0)
        std::cout << "In " << year << " = 366 days.\n";
    else 
        std::cout << "In " << year << " = 365 days.\n";

    return 0;
}

int main6()
/*
Создать приложение, которое выводит на экран следующую таблицу:

*/
{
    char hz = (char)205;   // horizontal line
    char vr = (char)186;   // vertical line
    char trc = (char)187;  // top right corner
    char tlc = (char)201;  // top left corner
    char brc = (char)188;  // bottom right corner
    char blc = (char)200;  // bottom left corner
    char hd = (char)203;   // horizontal and down
    char hu = (char)202;   // horizontal and up
    char hr = (char)204;   // horizontal and right
    char hl = (char)185;   // horizontal and left

    std::cout << tlc << hz << hz << hz << hz << hz << hz << hz << hz << hz
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << hz
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << hz
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << trc
        << std::endl
        << std::endl
        << vr
        << std::setw(20) << "Pory roku"
        << std::setw(19)
        << vr
        << std::endl
        << std::endl
        << hr << hz << hz << hz << hz << hz << hz << hz << hz << hd
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << hd
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << hd
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << hl
        << std::endl
        << std::endl
        << vr
        << std::setw(6) << "Zyma"
        << std::setw(3)
        << vr
        << std::setw(7) << "Vesna"
        << std::setw(3)
        << vr
        << std::setw(6) << "Lito"
        << std::setw(4)
        << vr
        << std::setw(7) << "Osin\'"
        << std::setw(3)
        << vr
        << std::endl
        << std::endl
        << blc << hz << hz << hz << hz << hz << hz << hz << hz << hu
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << hu
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << hu
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << brc
        << std::endl;

    return 0;

}

int main5()
/*
 Создать приложение, которое выводит на
консоль фразу:
“U lukomor’a dub zelenij,
 Zlataya zep na dupe tom,
 I dnem i nochju kot uchenij
 vse hodit po cepi krugom”
Сопроводить каждую новую строчку тройным звуковым сигналом.
*/
{
    std::cout << "\"U lukomor\'a dub zelenij,\n\a\a\a"
        << "Zlataya zep na dupe tom,\n\a\a\a"
        << "I dnem i nochju kot uchenij\n\a\a\a"
        << "vse hodit po cepi krugom.\"\n\a\a\a";

    return 0;

}

int main4()
/*
Создать приложение, которое выводит информацию о книге, в следующем формате:
Name        : “The war and the peace”
Avtor       : L.N. Tolstoj
Izdatelstvo : Piter
Pages       : 500.
*/
{
    std::cout << "Name \t\t: \"The war and the peace\"\n"
        << "Avtor \t\t: L.N. Tolstoj\n"
        << "Izdatelstvo\t: Piter\n"
        << "Pages \t\t: 500.\n";

    return 0;
}


int main3()
/*
Выведите следующий текст:
To be, or not to be: that is the question:
Whether 'tis nobler in the mind to suffer
The slings and arrows of outrageous fortune,
Or to take arms against a sea of troubles,
And by opposing end them?
William Shakespeare
*/
{
    std::cout << "To be, or not to be: that is the question:\n"
        << "Whether 'tis nobler in the mind to suffer\n"
        << "The slings and arrows of outrageous fortune,\n"
        << "Or to take arms against a sea of troubles,\n"
        << "And by opposing end them?\n"
        << "William Shakespeare\n";

    return 0;
}



int main2()
/*
Написать программу, которая выводит на
экран:
Hello, World!
\\Dennis Ritchi\\
*/
{
    std::cout << "Hello, World!\n"
        << "\\\\Dennis Ritchi\\\\\n";

    return 0;
}


int main1()
/*
Написать программу, которая выводит на
экран:
“Hello, World!”
/Bjarne Stroustrup/
*/
{
    std::cout << "\"Hello, World!\"\n" 
              << "/Bjarne Stroustrup/\n";

    return 0;
}


