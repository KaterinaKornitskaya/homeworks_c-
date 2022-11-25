// морской_бой.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <conio.h>



int main()
{
	const int N = 10;  // размер массива поля
	int map[N][N] = { 0 };  // объявление массива для поля
							// массив инициализирован нулями

	// разместить корабли случайно
	int x, y;  // координаты кораблей
	int dir = 0;  // переменная для напрвления рисовки корабля
	for (size_t i = 0; i < 5; i++)  // 5 кораблей
	{								// случайное заполнение кораблями
		x = rand() % N;  // случайное число от 0 до 4
		y = rand() % N;  // случайное число от 0 до 4
		map[x][y] = 1;
	}

	for (size_t i = 0; i < N; i++) {  // вывод на экран
		for (size_t j = 0; j < N; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}

	
	
		

	while (true)
	{
		std::cout << "Enter ship coord: " << std::endl;  // эзер вводит координаты цели
		std::cin >> x;
		std::cin >> y;

		if (map[x][y] == 1)  // проверяем содержимое массива с координатами, записана ли 1
		{  // если 1 записана - попадание
			std::cout << "Popal" << std::endl;
			map[x][y] = 0;  // чтобы попадания не были бесконечны - обнулить содержимое ячейки 
			
			bool ship_detect = false;  // по умолчанию корабль НЕ обнаружен
			for (size_t i = 0; i < N; i++) {  // перебор, все ли корабли потоплены
				for (size_t j = 0; j < N; j++)
				{
					if (map[i][j] == 1) {  // если мы нашли ячейку с кораблем
						ship_detect = true;
					}
				}
				if (ship_detect == true) {  

					break;  
				}
				
			}
			if (ship_detect == false) {  // если корабли не обнаружены
				std::cout << "You win!" << std::endl;
				break;  // прервет цикл while
			}

		
		}
		else {
			std::cout << "Promah" << std::endl;
		}
	}



	//_getch();
	system("pause");
	

}

