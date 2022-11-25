// dz_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <cmath>

int main()
/*
Користувач вводить координати центра кола (х та у), а також його радіус. 
Програма визначає чи перетинає дане коло вісі координат. 
Приклад роботи (ілюстрація кіл - на рисунку)
Enter center and radius: 2 2 1
No intersections
Enter center and radius: -3 0 1
Intersection with X axis
Enter center and radius:  0 -2 1
Intersection with Y axis
*/
{
    float circle_x_center;  // veriable for circle center on x axis, input by user
    float circle_y_center;  // veriable for circle center on y axis, input by user
    float radius;           // veriable for circle radius, input by user

    std::cout << "Enter center and radius: ";
    std::cin >> circle_x_center >> circle_y_center >> radius;

    if ((circle_y_center - radius) <= 0          // condition for intersection with x axis
        && ((circle_x_center - radius) > 0))
    {
        std::cout << "Intersection with X axis";
    }
    else if ((circle_x_center - radius) <= 0     // condition for intersection with y axis
        && ((circle_y_center - radius) > 0))
    {
        std::cout << "Intersection with Y axis";  
    }
    else if ((circle_y_center - radius) <= 0     // condition for intersection with x and y axis
        && (circle_x_center - radius) <= 0)
    {
        std::cout << "Intersection with X and Y axis";
    }
    else
    {
        std::cout << "No intersections";
    }

    return 0;
}

int main4()
/*
Користувач вводить довжини трьох відрізків. 
Програма має визначити, чи можна з даних відрізків скласти трикутник. 
Якщо введена довжина будь-якого з відрізків є нульовою чи від'ємною, 
то програма має видавати повідомлення про некоректні дані.
Приклад роботи
Enter length for 3 fragments:   2 3 4
Triangle is possible
Enter length for 3 fragments:   2 3 40
Triangle is impossible
Enter length for 3 fragments:   2 3 -4
Invalid length: -4
*/
{
    float length_1, length_2, length_3;             // variable for lengths - input by user

    std::cout << "Enter length for 3 fragments: ";
    std::cin >> length_1 >> length_2 >> length_3;

    if (length_1 == 0 || length_1 < 0)              // condition - if length 1 <= 0 - error
    {
        std::cout << "Invalid length: " << length_1;
        return -1;
    }
    else if (length_2 == 0 || length_2 < 0)         // condition - if length 2 <= 0 - error
    {
        std::cout << "Invalid length: " << length_2;
        return -1;
    }
    else if (length_3 == 0 || length_3 < 0)         // condition - if length 3 <= 0 - error
    {
        std::cout << "Invalid length: " << length_3;
        return -1;
    }
    else if (length_1 < (length_2 + length_3)       // conditions - if triangle is possible 
            && length_2 < (length_1 + length_3)
            && length_3 < (length_1 + length_2))
    {
        std::cout << "Triangle is possible";
    }
    else 
    {
        std::cout << "Triangle is NOT possible";
    }

    return 0;
}

int main3()
/*
Користувач вводить координати точки на площині (х та у). Програма визначає чи належить дана точка (див. рис.)
  А) квадрату “1”
  Б) колу “2”
  В) прямокутнику “3”

Приклад роботи:
Enter point (x,y):  1.5  2.5
Point (1.5; 2.5) is:
 Outside square 1
 Inside circle 2
 Outside rectangle 3
*/
{
    short x, y;           // x, y - operands inputed by user; short - since numbers will be between -10...+10
    std::string message;  // variable string - to input repeating string
    
    enum figures                                                      // set of named integer constants (так правильно?)
    {
        SQUARE_X_LEFT = -4, SQUARE_X_RIGHT = -1,                      // extreme points of the square on the x-axis
        SQUARE_Y_TOP = 4, SQUARE_Y_BOTTOM = 1,                        // extreme points of the square on the y-axis
        RECTANGLE_X_LEFT = -3, RECTANGLE_X_RIGHT = 3,                 // extreme points of the rectangle on the x-axis
        RECTANGLE_Y_TOP = -2, RECTANGLE_Y_BOTTOM = -4,                // extreme points of the rectangle on the y-axis
        CIRCLE_X_CENTER = 2, CIRCLE_Y_CENTER = 2, CIRCLE_RADIUS = 2   // circle center on the x-axis, y-axis, circle radius
    };

    std::cout << "Enter a point on the x-axis --> ";
    std::cin >> x;
    std::cout << "Enter a point on the y-axis --> ";
    std::cin >> y;
    
    message = " The point (" + std::to_string(x) + ", " + std::to_string(y) + ") " + "is ";  // message for repeating strings
    
    // использую тернарный оператор - подходит для простых условий

    (x > SQUARE_X_LEFT&& x < SQUARE_X_RIGHT                         // condition - if point (x, y) belong to square
     && y < SQUARE_Y_TOP&& y > SQUARE_Y_BOTTOM) ?
        (std::cout << message + "inside square 1." << std::endl) :
        (std::cout << message + "outside square 1." << std::endl);
    
    int point_to_center;                                            // veriable for distance from point (x,y) to circle center
    point_to_center = sqrt(pow((CIRCLE_X_CENTER - x), 2) + pow((CIRCLE_Y_CENTER - y), 2));
    
    (point_to_center < CIRCLE_RADIUS) ?                             // condition - if point (x, y) belong to circle
        (std::cout << message + "inside circle 2." << std::endl) :
        ( std::cout << message + "outside circle 2." << std::endl);
    
    (x > RECTANGLE_X_LEFT&& x < RECTANGLE_X_RIGHT                   // condition - if point (x, y) belong to rectangle
        && y < RECTANGLE_Y_TOP&& y > RECTANGLE_Y_BOTTOM) ?
        (std::cout << message + "inside rectangle 3." << std::endl) :
        (std::cout << message + "outside rectangle 3." << std::endl);
    
    return 0;
}



int main2()
/*
Скласти програму яка округлює число вгору - 
знаходить найбільше ціле число, що не є меншим за введене. 
Передбачається введення як додатних, так і від'ємних чисел. 
*/
{
    float number;           // число, вводимое пользователем

    std::cout << "Enter your number: ";
    std::cin >> number;

    int x = (int)number;    // преобразование числа в int (отбрасывает дробную часть)

    if (number > x) x +=1;  // если вводимое число больше, чем преобразованное - добавляем 1
    std::cout << "Rounded up = " << x;
   
    return 0;
}


int main1()
/*
 Скласти програму яка встановлює знак введеного числа: 
 користувач вводить число, програма виводить одне з повідомлень: 
 “positive” (для додатних чисел), 
 “negative” (для від'ємних чисел), 
 “zero” (якщо введено нуль).
*/
{
    float number;  // число, вводимое пользователем

    std::cout << "Enter number: ";
    std::cin >> number;

    std::string type =                             // тернарный оператор
        (number == 0)                              // if number = 0 --> type zero
        ? "zero" :                                 //
        ((number > 0) ? "positive" : "negative");  // if number != 0 --> (if number > 0 --> type positive, if no --> negative)

    std::cout << "Your number " << number << " is " << type;
    
    return 0;
}


