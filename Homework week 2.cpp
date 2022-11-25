
#include <iostream>

int main()
/*
Завдання 2. Написати програму, яка перетворює введене
з клавіатури дробове число на грошовий формат. 
Наприклад, число 12,5 має бути перетворено так: 12 грн 50 коп.
*/
{
    {
        double number, hrn, kop;

        std::cout << "Enter your number in hrn,kop\n";
        std::cin >> number;

        kop = number * 10.0;
        hrn = (kop / 10.0); // не получается, выдает 0 копеек постоянно

        std::cout << hrn << " hrn " << kop << " kop.";


    return 0;

}



int main3()
{
    /*
    Завдання 3. Обчислити пройдену відстань при прямолінійному рівноприскореному русі 
    за формулою S = v*t + (a*t2) / 2, де v — швидкість, t — час, а — прискорення.
    */

    float v;
    float t;
    float a;
    float S;

    std::cout << "Enter v \n";
    std::cin >> v; 
    std::cout << "Enter t \n"; 
    std::cin >> t;
    std::cout << "Enter a \n";
    std::cin >> a;
  
    S = v * t + (a * (t*t)) / 2;

    std::cout << "S = " << S;

    return 0;

}

int main2()
{

/*
Завдання 2. За заданою довжиною окружності знайти
площу кола за формулою S = pi* R2, радіус обчислити
з формули довжини кола: L = 2*pi*R.
Примітка: pi = 3.14.
*/

    float pi = 3.14;
    float S;
    float R; 
    float L;

    std::cout << "Enter L = ";
    std::cin >> L;

    R = L / (2 * pi);
    S = pi * (R * R);
    
    std::cout << "S = " << S;

    return 0;

}


int main1()

 /*
 Завдання 1. Задані три опори R1, R2, R3. Обчислити 
значення опору R0 за формулою: 1/R0 = 1/R1+1/R2+1/R3.
Контрольний приклад: R1=2, R2=4, R3=8 R0 = 1.142857.
 */

{
   
    float R1 = 2;
    float R2 = 4;
    float R3 = 8;
    float R0;
    R0 = 1/(1 / R1 + 1 / R2 + 1 / R3);
    std::cout << "Ro = " << R0;

    return 0;
    
}
