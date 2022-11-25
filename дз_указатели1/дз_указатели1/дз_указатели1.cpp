// дз_указатели1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

typedef short var_type;  // псевдоним для типа данных, используем short

// прототипы всех используемых в программе функций
void fill_arr(var_type* arr1, size_t n);
void reverse_arr(var_type* arr1, var_type* arr2, size_t n);
void reverse_arr(var_type* arr1, size_t n);
void print_arr(var_type* arr1, var_type* arr2, size_t n);
void print_arr3(var_type* arr3, size_t n);

void fill_arr(var_type* arr1, size_t n)     // ф-ия для заполнения начального массива arr1
{                                           // var_type* arr1 - указатель на массив1
    for (size_t i = 0; i < n; i++)
    {
        *(arr1 + i) = rand() % 21 - 10;     // прямое разименование смещенного указателя, 
    }                                       // заполнение рандомными числами -10...+10 вкл.
}

void reverse_arr                            // ф-ия копирования массива в обратном порядке
(var_type* arr1, var_type* arr2, size_t n)  
{                                           
    for (size_t i = 0; i < n; i++)
    {
        arr2[(n - 1) - i] = *(arr1 + i);    // копирование элементов из 1го во 2ой массив
    }                                       // в обратном порядке
}

void reverse_arr                            // ф-ия смены порядка эл-ов массива1 в обратную сторону
(var_type* arr1, size_t n)
{
    std::cout << "Reverse order for array1: \n";
    for (size_t i = 0; i < n; i++)
    {
         arr1[(n - 1) - i];
        std::cout << arr1[(n - 1) - i] << " ";
           
    }  
    std::cout << std::endl;
}

void copy_arr                               // ф-ия копирования массива
(var_type* arr1, var_type* arr3, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        *(arr3+i) = *(arr1 + i);            // копирование элементов из 1го в 3ий массив
    }
}

void print_arr                              // ф-ия вывода arr1 и arr2 на экран
(var_type* arr1, var_type* arr2, size_t n)  
{  
    std::cout << "Array1 (start array): \n";
    for (size_t i = 0; i < n; i++)
    {
        std::cout << *(arr1 + i) << " ";    // вывод массива1
    }
    std::cout << std::endl;
    std::cout << "Array2 (reversed array1): \n";
    for (size_t i = 0; i < n; i++)
    {
        std::cout << *(arr2 + i) << " ";    // вывод массива2
    }
    std::cout << std::endl;
}

void print_arr3(var_type* arr3, size_t n)   // ф-ия вывода 3го масива на экран
{
    std::cout << "Array3 (copied array1): \n";
    for (size_t i = 0; i < n; i++)
    {
        std::cout << *(arr3 + i) << " ";    // вывод массива3
    }
    std::cout << std::endl;
}

int main() {
    var_type* arr1;          // указатель на массив1
    var_type* arr2;          // указатель на массив2
    var_type* arr3;          // указатель на массив3
    size_t n = 10;           // переменная для размера массива
    arr1 = new var_type[n];  // выделение памяти под массив1
    arr2 = new var_type[n];  // выделение памяти под массив2
    arr3 = new var_type[n];

    srand(time(NULL));       // сидирование  
    fill_arr(arr1, n);

    /*
    Використовуючи два покажчики на масиви цілих чисел, 
    скопіювати один масив у інший так, щоб у другому масиві 
    елементи знаходилися у зворотному порядку.
    */
    reverse_arr(arr1, arr2, n);
    print_arr(arr1, arr2, n);
    delete[] arr2;  // освобождение памяти для массива2

    /*
    Використовуючи два покажчики на масив цілих чисел, 
    скопіювати один масив у інший. 
    */
    copy_arr(arr1, arr3, n);
    print_arr3(arr3, n);
    delete[] arr3;  // освобождение памяти для массива3

    /*
    Використовуючи покажчик на масив цілих чисел, 
    змінити порядок проходження елементів масиву на протилежний.
    */
    reverse_arr(arr1, n);
    delete[] arr1;  // освобождение памяти для массива1
 
    return 0;
}
