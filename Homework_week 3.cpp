// Homework_week 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>

int main()
/*
Користувач вводить з клавіатури час у секундах, що минув з початку робочого дня. 
Порахувати, скільки цілих годин йому залишилося сидіти на роботі, якщо робочий день — 8 годин.
*/
{
    setlocale(LC_ALL, "Russian");
    int time;

    std::cout << "Введите время, которое прошло с начала рабочего дня, в секундах\n";
    std::cin >> time;

    int h = time / 3600;
    int minsec = time % 3600;
    int min = minsec / 60;
    int sec = minsec % 60;

    int h_l = 7 - h;       // осталось часов до конца 8-часового раб. дня
    int min_l = 59 - min;  // осталось минут до конца 8-часового раб. дня
    int sec_l = 59 - sec;  // осталось секунд до конца 8-часового раб. дня

    std::cout << "До конца рабочего дня осталось " << h_l << " часов, " << min_l << " минут, " << sec_l << " секунд.";


    return 0;
}


int main4()
/*
Користувач вводить з клавіатури час у секундах, що минув з початку дня. 
Вивести на екран поточний час у годинах, хвилинах і секундах. 
Порахувати, скільки годин, хвилин і секунд залишилося до півночі.
*/
{
    setlocale(LC_ALL, "Russian");
    int time;

    std::cout << "Введите время, которое прошло с начала дня, в секундах\n";
    std::cin >> time;

    int h = time / 3600;
    int minsec = time % 3600;
    int min = minsec / 60;
    int sec = minsec % 60;

    int h_l = 23 - h;      // hours left to 00:00
    int min_l = 59 - min;  // minutes left to 00:00
    int sec_l = 59 - sec;  // secundes left to 00:00

    std::cout << "До полуночи осталось " << h_l << " часов, " << min_l << " минут, " << sec_l << " секунд.";


    return 0;
}

int main3()
/*
 Користувач вводить з клавіатури відстань, витрату бензину на 100 км і вартість трьох видів бензину.
Вивести на екран порівняльну таблицю з вартістю подорожі на різних видах палива.
*/
{
    setlocale(LC_ALL, "Russian");
    float distance;
    float cons; // consumption - расход
    float A92;
    float A95;
    float DP;

     

     std::cout << "Введите расстояние, расход бензина на 100 км, и стоимость\n"
         << "расстояние, км => ";
     std::cin >> distance;
     std::cout << "\nрасход бензина на 100 км, л => ";
     std::cin >> cons;
     std::cout << "\nстоимость А92, грн => ";
     std::cin >> A92;
     std::cout << "\nстоимость А95, грн => ";
     std::cin >> A95;
     std::cout << "\nстоимость ДП, грн => ";
     std::cin >> DP;

     float a = ((cons * 100) / distance) * A92;  // путешествие a на А92
     float b = ((cons * 100) / distance) * A95;  // путешествие b на А95
     float c = ((cons * 100) / distance) * DP;   // путешествие c на ДП

     std::cout << std::endl << "Стоимость поездки" << std::endl 
         << "A92 => " << a  << " грн." << std::endl << "A95 => " << b << " грн." << std::endl << "ДП => " << c << " грн." << std::endl;

    return 0;
}

int main2()
/*
Користувач вводить з клавіатури час початку і час завершення використання скутера 
(години, хвилини та секунди). 
Порахувати вартість подорожі, якщо вартість хвилини — 2 гривні.
*/
{
    setlocale(LC_ALL, "Russian");
    float h_s;      // hours at start
    float min_s;    // minutes at start
    float sec_s;    // seconds at start
    float h_end;    // hours on end
    float min_end;  // minutes on end
    float sec_end;  // seconds on end
    float ppm = 2;  // price per min
    float distance;
    float price;

    std::cout << "Введите время начала пользования в формате --> \n"
        << "часы\n"
        << "минуты\n"
        << "секунды\n";
    std::cin >> h_s >> min_s >> sec_s;
    std::cout << "Введите время окончания пользования в формате --> \n"
        << "часы\n"
        << "минуты\n"
        << "секунды\n";
    std::cin >> h_end >> min_end >> sec_end;
    distance = ((h_end - h_s) * 60) + (min_end - min_s) + ((sec_end - sec_s) / 60);
    price = distance * ppm;
    std::cout << "Стоимость путешествия = " << price << " грн.\n";

    return 0;
}

int main1()
/*
Користувач вводить з клавіатури відстань до аеропорту і час, за який потрібно доїхати. 
Обчислити швидкість, з якою йому потрібно їхати.
*/
{
    float dictance;
    float time;
    float speed;


    std::cout << "Enter distance, km\n";
        std::cin >> dictance;
        std::cout << "Enter time, hours\n";
        std::cin >> time;
    
    speed = dictance / time;
    std::cout << "Your speed should be " << speed << "km per hour.\n";

    return 0;
}

