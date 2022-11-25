// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string>


struct car
{
    std::string color;
    std::string model;
    std::string number;
};

car* arr;
const int size = 10;

void input_arr()                                                 // функция заполнения массива данными об авто
{
    arr = new car[size];                                         // выделение памяти под массив 

    for (int i = 0; i < size; i++)                               // заполняем массив данными
    {
        std::cout
            << " Car number "
            << i + 1 << ".\n";
            

        std::cout << " Enter color: ";
        std::cin >> arr[i].color;

        std::cout << " Enter model: ";
        std::cin >> arr[i].model;

        std::cout << " Enter number: ";
        std::cin >> arr[i].number;

    }
}

void print_rec(int i)                                           // функция вывода данных массива
{
    if (size < 1) std::cout             // если размер массива меньше 1, то массив не заполнен
        << " Car details not yet filled!"
         << "\n";
    else                                                        // иначе выводим данные в консоль
    {
        std::cout 
            << " Car number "
            << i + 1 << "\n"
            

            << " Color           " << arr[i].color << "\n"
            << " Model           " << arr[i].model << "\n"
            << " Number          " << arr[i].number << "\n\n";
    }
}

void output_arr()                                               // функция вывода данных массива на экран консоли
{
    if (size <= 0) std::cout              // если размер массива меньше <= 0, то массив не заполнен
        << " Car details not yet filled!"
        << "\n";

    else for (int i = 0; i < size; i++) print_rec(i);           // иначе выводим на экран консоли
}

int search()                                                    // функция поиска автомобиля по данным
{

    if (size < 1) std::cout               // если размер массива меньше < 1, то массив не заполнен
        << " Car details not yet filled!"
         << "\n";
    else                                                        // иначе предлагаем выбрать характеристику для поиска
    {
        //system("pause");
        Sleep(2000);
        system("cls");

        std::cout << " Enter number to search\n";

        std::string data;
        std::cin >> data;

        int count_s = 0;                                         // счетчик кол-ва найденных авто

        for (int i = 0; i < size; i++)
        {
            std::string temp;

            temp = arr[i].number;

            if (temp == data)                                    // вывод, если совпадение нашлось
            {
                print_rec(i);
                count_s++;
            }
        }
        return count_s;                                          // возвращаем найденное кол-во авто
    }
    return 0;
}
void editCar()                                                   // функция редактирования данных об автомобиле
{
    int carChoice;                                               // переменная для хранения порядкового номера авто
    int editChoice;                                              // переменная для хранения выбранного параметра для редактирования

    std::string newData;                                         // переменная для ввода нового значения для параметра

    output_arr();                                                // выводим список авто со всеми параметрами

    if (size < 1) std::cout                // если размер массива меньше < 1, то массив не заполнен
        << " Car details not yet filled!"
        << "\n";
    else                                                         // иначе, выполняем редактирование
    {
        bool flag = true;
        do
        {
            std::cout << std::endl << " Enter the serial number of car:\n";
            std::cin >> carChoice;

            if (carChoice > 10 || carChoice < 1)                  // если введенного порядкового номера не существует
            {
                std::cout << " Incorrect value!\n";               // выводим сообзение об ошибке, и предлагаем ввести номер еще раз
            }
            else flag = false;                                    // иначе, меняем flag и выходим из цикла

        } while (flag);

        carChoice--;                                              // уменьшаем порядковый номер авто на 1, 
        // чтоб обратиться к данным авто по правильному индексу

        std::cout << " Enter edit type: " << std::endl
            << " 1 - color" << std::endl
            << " 2 - model" << std::endl
            << " 3 - number" << std::endl;
        std::cin >> editChoice;

        switch (editChoice)
        {
        case 1:
            std::cout << " Enter a new car color:\n";
            std::cin >> newData;
            arr[carChoice].color = newData;
            break;

        case 2:
            std::cout << " Enter a new car model:\n";
            std::cin >> newData;
            arr[carChoice].model = newData;
            break;

        case 3:
            std::cout << " Enter a new car number:\n";
            std::cin >> newData;
            arr[carChoice].number = newData;
            break;

        default:
            std::cout << " Incorrect value!" << std::endl;
            break;
        }
    }
}

int main()
{
    system("title Cars data");

    bool work = true;
    int menu;

    do
    {
        std::cout << "MENU\n"
            << "1 - add car details\n"
            << "2 - show car details\n"
            << "3 - data search\n"
            << "4 - data edit\n"
            << "Any key - exit\n"
            << "Choose an option: ";
        std::cin >> menu;

        //system("pause");
        Sleep(2000);
        system("cls");

        switch (menu)                                                        // проверяем ввод пользователя
        {                                                                    // и выполняем соотв. функции и действия
        case 1:

            input_arr();
            break;

        case 2:

            output_arr();
            Sleep(2000);
            break;

        case 3:
        {
            int count = search();
            (count < 1) ? std::cout                 // если функция search() вернула значение < 1, то
                << " Car data not found!"                                    // совпадений не найдено
                << "\n" :

                std::cout                        // иначе показываем кол-во найденных авто
                << "Total found: " << count
                << " car(s)"  << "\n";
            Sleep(2000);
            break;
        }
        case 4:

            editCar();
            break;
        default:

            work = false;
            break;
        }

        //system("pause");
        Sleep(2000);
        system("cls");

    } while (work);

    delete[] arr;                                                             // освобождение памяти дин. массива

    return 0;
}
