// dz11_menu_part3_arrays_part1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <iomanip>
#include <stdlib.h>

#define gotoxy(x,y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x, y})



int main1() {
    /*
    Написати програму, яка виводить на екран лінію заданим символом, вертикальну або горизонтальну,
    причому лінія може виводитися швидко, нормально і повільно.
    Спілкування з користувачем організувати через меню.
    */
    do {  // общий "бесконечный" цикл, что бы был возврат в меню
        system("cls");
        std::cout
            << "    Choose the snake" << std::endl                         // меню в два столбца
            << " Vertical" << std::setw(15) << "Horizontal" << std::endl   // 
            << "  Fast" << std::setw(14) << "Fast" << std::endl            // 
            << "  Normal" << std::setw(14) << "Normal" << std::endl        // 
            << "  Slow" << std::setw(14) << "Slow" << std::endl;           // 

        char c;            // символьная переменная для клавиши
        gotoxy(0, 2);      // переход на позицию (0, 2)
        std::cout << '>';  // вывод курсора '>' на позицию (0, 2)
        short y = 2;       // обьявление стартовой переменной x
        short x = 0;       // обьявление стартовой переменной y

        do {  // цикл для движения указателя по пунктам меню
            c = _getch();              // считывание символа с клавиатуры
            if (c == 0 || c == -32) {  // условие для клавиш, которые посылают два значения
                c = _getch();
            }
            gotoxy(x, y);
            std::cout << ' ';          // стираем предыдущие значение курсора

            if (c == 80) {  // стрелка вниз
                y += 1;
                if (y > 4) {
                    y = 2;
                }
            }
            if (c == 72) {  // стрелка вверх
                y -= 1;
                if (y < 2) {
                    y = 4;
                }
            }
            if (c == 77) {  // стрелка вправо
                x += 14;
                if (x > 14) {
                    x = 0;
                }
            }
            if (c == 75) {  // стрелка влево
                x -= 14;
                if (x < 0) {
                    x = 14;
                }
            }
            gotoxy(x, y);
            std::cout << '>';
        } while (c != 27 && c != 13 && c != 32);

        gotoxy(0, 6);  // переход на позицию (0, 6)

        std::cout << "Choose the symbol: ";
        char i = char(_getch()) - '0';  // считывания символа, вводимого пользователем
        std::cout << i;

        gotoxy(0, 8);  // переход на позицию (0, 8)

        if (y == 2 && x == 0) {        // условиe для пункта меню Verticsl > Fast
            for (y = 0; y <= 10; ++y) {
                std::cout << i << std::endl;
                Sleep(30);
            }
        }
        else if (y == 3 && x == 0) {   // условиe для пункта меню Verticsl > Normal
            for (y = 0; y <= 10; ++y) {
                std::cout << i << std::endl;
                Sleep(100);
            }
        }
        else if (y == 4 && x == 0) {   // условиe для пункта меню Verticsl > Slow
            for (y = 0; y <= 10; ++y) {
                std::cout << i << std::endl;
                Sleep(200);
            }
        }
        else if (y == 2 && x == 14) {  // условиe для пункта меню Horizontal > Fast
            for (x = 0; x <= 10; ++x) {
                std::cout << i << ' ';
                Sleep(30);
            }
        }
        else if (y == 3 && x == 14) {  // условиe для пункта меню Horizontal > Normal
            for (x = 0; x <= 10; ++x) {
                std::cout << i << ' ';
                Sleep(100);
            }
        }
        else if (y == 4 && x == 14) {  // условиe для пункта меню Horizontal > Slow
            for (x = 0; x <= 10; ++x) {
                std::cout << i << ' ';
                Sleep(200);
            }
        }
        std::cout << std::endl;
        system("PAUSE");

    } while (true);

    return 0;
}

int main2() {
    /*
        Написати гру «Кубики».
        Користувач і комп'ютер по черзі кидають 2 кубики.
        Переможець той, у кого за результатами 3х кидків сума більше.
        Передбачити красивий інтерфейс гри.
    */

    const short TRIES_LIMIT = 3;         // константа для колличества попыток
    short num_user1, num_user2;          // переменные для чисел, выпадающих на кубике пользователя, два кубика  
    short num_computer1, num_computer2;  // переменные для чисел, выпадающих на кубике компьютера, два кубика                                                             
    short  tries_user, tries_computer;   // переменные счетчик попыток пользователя, компьтера
    short sum_user, sum_computer;        // переменная для суммы очков пользователя, компьютера   

    sum_user = 0;                        // присваивание сумме очков пользователя значения 0
    sum_computer = 0;                    // присваивание сумме очков компьютера значения 0
    tries_user = 0;                      // присваивание счетчику попыток пользователя значения 0
    tries_computer = 0;                  // присваивание счетчику попыток компьютера значения 0

    char vr = char(179);   // вертикальная линия    | символьные переменные
    char hr = char(196);   // горизонтальная линия  | для отрисовки кубиков
    char trc = char(191);  // верхний правый угол   |
    char brc = char(217);  // нижний правый угол    |
    char tlc = char(218);  // верхний левый угол    |
    char blc = char(192);  // нижний левый угол     |

    std::cout << "Lets play dice!" << std::endl;
    do {  // общий цикл - продолжать игру, пока не выполнится условие выхода
        srand(time(NULL));
        num_user1 = 1 + rand() % 6;  // случайное число от 1 до 6 включительно
        num_user2 = 1 + rand() % 6;
        num_computer1 = 1 + rand() % 6;
        num_computer2 = 1 + rand() % 6;

        ++tries_user;  // счетчик попыток пользователя
        std::cout << "Your " << tries_user << " try " << std::endl;
        system("Pause");    // я хотела сделать так, что бы была надпись НЕ "Нажмите любую кнопку", а 
                            // нажмите конкретную кнопку, например "Нажмите Enter для броска",
                            // но не получается. HELP HELP HELP 
        std::cout
            << tlc << hr << hr << hr << trc << std::setw(5)         // с помощью символов 
            << tlc << hr << hr << hr << trc << std::endl            // выводим два "кубика",
            << vr << " " << num_user1 << " " << vr << std::setw(5)  // внутри каждого "кубика" - 
            << vr << " " << num_user2 << " " << vr << std::endl     // выпавшее число пользователя
            << blc << hr << hr << hr << brc << std::setw(5)
            << blc << hr << hr << hr << brc << std::endl;

        ++tries_computer;  // счетчик попыток компьютера
        std::cout << "Computer`s " << tries_user << " try " << std::endl;
        std::cout
            << tlc << hr << hr << hr << trc << std::setw(5)             // с помощью символов 
            << tlc << hr << hr << hr << trc << std::endl                // выводим два "кубика",
            << vr << " " << num_computer1 << " " << vr << std::setw(5)  // внутри каждого "кубика" - 
            << vr << " " << num_computer2 << " " << vr << std::endl     // выпавшее число компьютера
            << blc << hr << hr << hr << brc << std::setw(5)
            << blc << hr << hr << hr << brc << std::endl;

        sum_user += (num_user1 + num_user2);              // счетчик для суммы очков пользователя
        sum_computer += (num_computer1 + num_computer2);  // счетчик для суммы очков компьютера

    } while (tries_user < TRIES_LIMIT && tries_computer < TRIES_LIMIT);   // условие выхода из цикла

    std::cout << "Yout sum is : " << sum_user << std::endl;
    std::cout << "Computer`s sum is : " << sum_computer << std::endl;

    if (sum_user > sum_computer) {       // условие для выиграша пользователя
        std::cout << "Congratulations!!! You Win!" << std::endl;
    }
    else if (sum_user < sum_computer) {  // условие для выиграша компьютера
        std::cout << "Ops... You lose." << std::endl;
    }
    else {                               // условия для "ничья"
        std::cout << "It`s a draw." << std::endl;
    }

    return 0;
}

int main3() {
    /*
        В одновимірному масиві, заповненому випадковими числами,
        визначити мінімальний і максимальний елементи.
    */

    const size_t N = 10;  // размер массива (колличество элементов)
    int arr[N];
    size_t max, min;      // переменные для максимального и минимального элементов
    srand(time(NULL));    // сидирование

    for (size_t i = 0; i < N; ++i) {
        arr[i] = 1 + rand() % 50;  // заполнение массива случайными числами от 1 до 50
        std::cout << arr[i] << ' ';

    }
    std::cout << std::endl;

    max = arr[0];  // присваивание изначального значения 0 для max
    min = arr[0];  // присваивание изначального значения 0 для min
    for (int i = 1; i < N; i++) {  // проверка всех элементов массива
        if (min > arr[i])          // условие для минимального значения
            min = arr[i];
        if (max < arr[i])          // условие для максимального значения
            max = arr[i];

    }
    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;

    return 0;
}


int main4() {
    /*
     Користувач вводить прибуток фірми за рік (12 місяців).
     Потім користувач вводить діапазон (наприклад, 3 і 6 — пошук між третім і шостим місяцем).
     Необхідно визначити місяць, у якому прибуток був максимальним, і
     місяць, у якому прибуток був мінімальним, з урахуванням обраного діапазону.
    */

    const size_t MONTH = 12;  // тип size_t - для индекса массива
    int arr[MONTH];           // константа для указания размера массива
    int profit = 0;           // прибыль, присаиваем начальное значение 0

    for (size_t i = 0; i < MONTH; i++) {  // цикл для заполнения массива, от 1 до 12
        arr[i] = profit;
        std::cout << "Enter profit for " << i + 1 << " month: ";
        std::cin >> profit;
    }

    int m_start;  // месяц начала отсчета
    int m_end;    // месяц окончания отсчета

    std::cout << "Enter first month: ";
    std::cin >> m_start;
    std::cout << "Enter second month: ";
    std::cin >> m_end;

    if (m_start > 12 || m_start < 1) {   // проверка, что месяц начала введен корректно
        std::cout << "Illegal value for 1st month!";
        return -1;
    }
    else if (m_end > 12 || m_end < 1) {  // проверка, что месяц окончания введен корректно
        std::cout << "Illegal value for 2nd month!";
        return -1;
    }
    if (m_start > m_end) {  // проверка, если начальный месяц больше конечного
        int tmp = m_start;  // вводим временную переменную, присваиваем начальному месяцу
        m_start = m_end;     // начальный месяц меняем с конечным
        m_end = tmp;           // конечному месяцу присваиваем временную переменную с содержимым начального
    }

    int max = 0;
    int min = 0;

    for (size_t i = m_start; i <= m_end; ++i) {       // цикл - вывод на экран номер месяца 
        std::cout << i << ' ' << arr[i] << std::endl; //  от начального до конечного - прибыль
    }

    for (size_t i = m_start; i <= m_end; ++i) {  // цикл для определения максимальной прибыли в указанном промежутке
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    for (size_t i = m_start; i <= m_end; ++i) {  // цикл для определения минимальной прибыли в указанном промежутке
        if (min > arr[i]) {                      // НЕ РАБОТАЕТ мин. Я не понимаю, почему, он же точно такой, как макс??????
            min = arr[i];                        // HELP HELP HELP 
        }
    }
    std::cout << " Max = " << max << std::endl << "Min = " << min;
    std::cout << std::endl;

    // HELP HELP HELP 
    // если дойти до шага "Выберите месяц начала и месяц конца", и в месяце конца выбрать месяц "12" - 
    // на месяц 12 выдает непонятное отрицательное значение прибыли, и считает его как min
    // HELP HELP HELP 
    return 0;
}


int main() {

    /* В одновимірному масиві, що складається з N дійсних чисел, обчислити:
     1. Суму від'ємних елементів;
     2. Добуток елементів, що розташовані між min і max елементами;
     3. Добуток елементів з парними номерами;
     4. Суму елементів, що розташовані між першим і останнім від'ємними елементами
    */

    const size_t N = 10;  // тип size_t - для индекса массива
    int arr[N];
    srand(time(NULL));

    for (size_t i = 0; i < N; ++i) {  // заполнение массива рандомными числами
        arr[i] = rand() % 30 - 10;    // от -20 до 10
    }
    for (size_t i = 0; i < N; ++i) {
        std::cout << arr[i] << ' ';  // вывод массива
    }
    std::cout << std::endl;

    // 1. Суму від'ємних елементів;

    int neg = 0;           // переменная колличество отрицательных элементов
    int sum_negative = 0;  // переменная для сумма отрицательных элементов
    std::cout << "Negative: ";
    for (size_t i = 0; i < N; ++i) {
        if (arr[i] < 0) {                // условие для отрицательного           
            std::cout << arr[i] << ' ';  // вывод отрицательных
            ++neg;                       // колличество отрицательных
            sum_negative += arr[i];      // сумма отрицательных   
        }
    }
    std::cout << "\n\nTotal amount of negative elements: " << neg;
    std::cout << "\nSum of negative elements: " << sum_negative;

    // 2.Добуток елементів, що розташовані між min і max елементами;

    int min = 0;  // переменная для минимального элемента
    int max = 0;  // переменная для максимального элемента
    int dob = 0;  // переменная для производного

    for (int i = 0; i < N; ++i) {
        if (min > arr[i]) {  // условие для мин
            min = arr[i];
        }
        if (max < arr[i]) {  // условие для макс
            max = arr[i];
        }

    }
    std::cout << "\n\nMin = " << min;
    std::cout << "\nMax = " << max;

    std::cout << "\nElements between min and max: ";

    for (int i = min + 1; i < max; ++i) {
        std::cout << "Element" << arr[i] << std::endl;  // HELP HELP HELP
                                                         // не могу вывести элемент между мин и макс, не пойму где ошибка
        dob *= arr[i];                                   // производное тоже не считает
    }

    std::cout << "\nDob = " << dob;
    std::cout << std::endl;
    std::cout << "\n\nElements with double elements: " << std::endl;

    // 3. Добуток елементів з парними номерами;
    int x = 0;  // переменная для цикла
    int d = 0;  // переменная для производного
    for (; x < N; ++x) {
        if (x % 2 == 0) {
            std::cout << arr[x] << ' ';
            d *= arr[x];   // все работает, пока стоит "+=" - плюсует верно
        }                   // когда ставлю "*=" - не умножает, выдает "0", 
                            // магия? HELP HELP HELP
    }
    std::cout << "Product of double elements: " << d << std::endl;

    //  4. Суму елементів, що розташовані між першим і останнім від'ємними елементами

    int first_neg_el;               // тип size_t - для индекса массива
    int sum_betw_neg_elements = 0;  // присваиваем сумме изначальное значение 0

    for (first_neg_el = 0; first_neg_el < N; first_neg_el++) {  // цикл для поиска первого отрицательного элемента
        if (arr[first_neg_el] < 0) {
            break;
        }
    }
    if (first_neg_el == N) {        // если цикл прошел все элементы и не сработал
        std::cout << "No negative elements";
    }
    else {                          // если сработал первый if
        std::cout << "\nFirst negative element: " << arr[first_neg_el]
            << " has index " << first_neg_el;
    }
    int k;                          // дополнительная переменная для цикла
    int last_neg_el;                // переменная для последний отрицательный элемент
    for (k = 0; k < N; ++k) {
        last_neg_el = N - 1 - k;    //поиск последнего элемента с конца
        if (arr[last_neg_el] < 0) {
            break;
        }
    }
    if (k == N) {  // если цикл не сработа
        std::cout << "\n\nNo negative elements";
    }
    else {         // если цикл сработал
        std::cout << "\n\nLast negative element: " << arr[last_neg_el]
            << " has index " << last_neg_el;
    }

    std::cout << "\n\nElements between first and last negative: ";

    if (first_neg_el != N && k != N) {                           // цикл для промежутка межу первым и последним элементами
        for (int j = first_neg_el + 1; j < last_neg_el; ++j) {     // границы не включаем
            sum_betw_neg_elements += arr[j];                     // сумма элементов в промежутке
            std::cout << arr[j] << ' ';                          // вывод элементов в промежутке

        }
    }
    std::cout << "\n\nSum between first and last negative elements = " << sum_betw_neg_elements;
    std::cout << std::endl;
    return 0;
}