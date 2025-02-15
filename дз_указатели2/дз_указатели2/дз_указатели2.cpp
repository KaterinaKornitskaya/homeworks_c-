﻿// дз_указатели2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

// прототипы используемых в программе функций
void fill_arr_A(int* arr_A, size_t m);
void fill_arr_B(int* arr_B, size_t n);
void print_arr_A(int* arr_A, size_t m);
void print_arr_B(int* arr_B, size_t n);
void not_common_A(int* arr_A, int* arr_B, int* arr_C, size_t m, size_t n);
void not_common_AB(int* arr_A, int* arr_B, int* arr_C, size_t m, size_t n);

int main()
{
	size_t m;  // размер для массива А
	size_t n;  // размер для массива В

	std::cout << "Enter first array size: ";
	std::cin >> m;
	std::cout << "Enter second array size: ";
	std::cin >> n;

	int* arr_A;          // указатель на массив А
	int* arr_B;          // указатель на массив В
	arr_A = new int[m];  // выделение памяти под массив А
	arr_B = new int[n];  // выделение памяти под массив В

	size_t k = 0;             // размер для массива С, меняется в ходе программы
	int* arr_C = new int[k];  // выделение памяти под динамический массив С

	srand(time(NULL));  
	fill_arr_A(arr_A, m);
	fill_arr_B(arr_B, n);
	std::cout << "First array: \n";
	print_arr_A(arr_A, m);
	std::cout << "Second array: \n";
	print_arr_B(arr_B, n);
	not_common_A(arr_A, arr_B, arr_C, m, n);
	not_common_AB(arr_A, arr_B, arr_C, m, n);
	delete[] arr_A;
	delete[] arr_B;
	delete[] arr_C;

	return 0;
}


void fill_arr_A(int *arr_A, size_t m)  // ф-ия, заполнение массива А
{
	for (size_t i = 0; i < m; i++) 
	{
		arr_A[i] = rand() % 10;
	}
}

void fill_arr_B(int* arr_B, size_t n)  // ф-ия, заполнение массива В
{
	for (size_t i = 0; i < n; i++)
	{
		arr_B[i] = rand() % 10;
	}
}

void print_arr_A(int* arr_A, size_t m)  // ф-ия, вывод на экран массива А
{
	for (size_t i = 0; i < m; i++)
	{
		std::cout << *(arr_A + i) << ' ';
	}
	std::cout << std::endl;
}

void print_arr_B(int* arr_B, size_t n)  // ф-ия, вывод на экран массива В
{
	for (size_t i = 0; i < n; i++)
	{
		std::cout << *(arr_B + i) << ' ';
	}
	std::cout << std::endl;
}

/*
 Завдання 1. Дани два масиви: А[M] і B[N] (M і N вводяться з клавіатури).
 Необхідно створити третій масив мінімально можливого розміру,
 у якому потрібно зібрати елементи масиву A,
 які не включаються до масиву B, без повторень.
*/
void not_common_A(int* arr_A, int* arr_B, int* arr_C, size_t m, size_t n) {
	size_t k = 0;  // накопительная переменная для размера массива С (итогового)
	for (size_t i = 0; i < m; i++)
	{
		bool buffer = false;
		for (size_t j = 0; j < n; j++)
		{
			if (arr_A[i] == arr_B[j])
			{
				buffer = true;
				break;
			}			
		}
		if (!buffer) {
			arr_C[k] = arr_A[i];
			k++;			
		}		
	}
	std::cout << "No common A: ";
	for (size_t i = 0; i < k; i++)
	{
		std::cout << arr_C[i] << ' ';
	}
	std::cout << std::endl;
}

/*
 Завдання 2. Дани два масиви: А[M] і B[N] (M і N вводяться з клавіатури).
 Необхідно створити третій масив мінімально можливого розміру,
 у якому потрібно зібрати елементи масивів A і B, які не є загальними для них, без 
повторень..
*/
void not_common_AB(int* arr_A, int* arr_B, int* arr_C, size_t m, size_t n) {
	size_t k = 0;
	for (size_t i = 0; i < m; i++)
	{
		bool buffer = false;
		for (size_t j = 0; j < n; j++)
		{
			if (arr_A[i] == arr_B[j])
			{
				buffer = true;
				break;
			}
		}
		if (!buffer) {
			arr_C[k] = arr_A[i];
			k++;
		}
	}
	for (size_t i = 0; i < m; i++)
	{
		bool buffer = false;
		for (size_t j = 0; j < n; j++)
		{
			if (arr_B[i] == arr_A[j])
			{
				buffer = true;
				break;
			}
		}
		if (!buffer) {
			arr_C[k] = arr_B[i];
			k++;
		}
	}
	std::cout << "No common A and B: ";
	for (size_t i = 0; i < k; i++)
	{
		std::cout << arr_C[i] << ' ';
	}
	std::cout << std::endl;
}

/*
Запускается, но в ходе работы выдет ошибку

void not_common_A - работает, единственная проблема - 
  усть повторяющиеся элементы

void not_common_AB - здесь ошибки
  запускается, выдает выреный результат,
  (кроме того, что как и в ф-ии выше есть повторяющиеся числа),
  а потом выдает ошибку. 
  Я не пойму, где проблема.
  И в самом алгоритме с тру/фолс думаю ошибки, можно было бы
  сделать проще, но я не пойму как.

  HELP HELP HELP
*/