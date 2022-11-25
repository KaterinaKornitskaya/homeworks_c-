// бой 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>

// глобальные переменные
const int N = 10;			// размер массива поля
const int NUM_SHIPS = 9;	// кол-во кораблей
int ship_id = 1;			// идентификатор корабля
int ships[10] = { 0 };		// массив для корабля (ячейка - палуба)
							// 9 кораблей на поле боля + нулевой элемент, который не исполь для инициализ кораблей

// прототипы функций:
void set_rand_ships (int map[N][N], int size_ship, int num_ships, int ship_id);     // ф-ия, случайная расстановка кораблей
void map_show (int map[N][N], int mask[N][N], bool use_mask);						// ф-ия, вывод поля с кораблями
int shoot (int map[N][N], int x, int y, int ships[NUM_SHIPS + 1], int mask[N][N]);  // ф-ия для стрельбы



int main()
{
	srand(time(NULL));
	while (true)														// цикл игры
	{ 
		int map[N][N] = { 0 };											// объявление массива для поля человека
		int map2[N][N] = { 0 };											// объявление массива для поля бота
																		// массив инициализирован нулями
		int ships1[NUM_SHIPS + 1] = { 0, 4, 3, 3, 2, 2, 2, 1, 1, 1 };   // массив кораблей для человека								
		int ships2[NUM_SHIPS + 1] = { 0, 4, 3, 3, 2, 2, 2, 1, 1, 1 };	// массив кораблей для бота
			
		int mask[N][N] = { 0 };											// объявление массива для невидимой маски поверх поля
		int mask2[N][N] = { 0 };										// маска для поля бота
		
		for (size_t i = 1; i <= NUM_SHIPS; i++) {						// раставляем корабли человека:		
			set_rand_ships(map, ships1[i], 1, i);
		}

		for (size_t i = 1; i <= NUM_SHIPS; i++) {						// раставляем корабли бота:		
			set_rand_ships(map2, ships2[i], 1, i);
		}
				
		int x = 0;														//  координаты стрельбы
		int y = 0;														//  координаты стрельбы

		bool turn = 1;													// переменная для хода, 1 - ходит человек
		
		while (true)													// цикл отвечающий за спереключение хода
		{
			int resultShoot = 0;
			do															// цикл отвечающий за стрельбу
			{
				map_show(map, mask, 0);									// 0 - не используем маску для своей карты
				std::cout << std::endl;
				map_show(map2, mask2, 1);								// 1 - используем маску для карты бота

				if (turn == 1) {									    // ходит человек
					std::cout << std::endl << "Enter coord to shoot: ";
					std::cin >> x;
					std::cin >> y;
					resultShoot = shoot(map2, x, y, ships2, mask2);
				}
				else {													// ход бота
					std::cout << std::endl << "Computer: ";
					Sleep(1000);
					x = rand() % N;										// ход бота рандомный
					y = rand() % N;										// ход бота рандомный
					resultShoot = shoot(map, x, y, ships1, mask);
				}

				if (resultShoot == 1) {									// анализ результата вызова
					std::cout << "Ranen" << std::endl;
				}
				else if (resultShoot == 2) {
					std::cout << "Killed" << std::endl;
				}
				else {
					std::cout << "Promah" << std::endl;
				}
				Sleep(1000);
				system("cls");
			} while (resultShoot != 0);									// продолж, пока не произошел промах
			turn = !turn;
		} 		
		_getch();
		system("cls");
	}	
	system("pause");
	return 0;
}


void set_rand_ships
(int map[N][N], int size_ship, int num_ships, int ship_id) {			// ф-ия, случайная расстановка кораблей

	int x, y;															// координаты кораблей
	int dir = 0;														// переменная для напрвления рисовки корабля
	int count_ship = 0;													// счетчик кораблей

	while (count_ship < 1)												// цикл для расстановки нужного кол-ва кораблей
	{
		x = rand() % N;													// генерируем случайную первичную позицию
		y = rand() % N;													// первичная позиция
		dir = rand() % 4;												// случайное направление от 0 до 3

		int temp_x = x;													// временно храним значения
		int temp_y = y;													// чтобы потом начать с начальных, а не измененных

																		// проверка, можно ли сюда ставить корабль
		bool setting_pos = 1;											// флаг - возможна ли поставить корабль
		for (size_t i = 0; i < size_ship; i++)							// size_ship-палубные корабли
		{
			if (x < 0 || y < 0 || x >= N || y >= N) {					// если х,у за пределами - нельзя
				setting_pos = 0;
				break;
			}
			if (map[x]    [y]     >= 1 ||								// проверка ячейки, чтобы корабли
				map[x]    [y + 1] >= 1 ||								// не соприкасались
				map[x]    [y - 1] >= 1 ||								// и не пересекались
				map[x + 1][y]     >= 1 ||								// >= 1 - ship_id это 1, корабль, все что больше ок
				map[x + 1][y + 1] >= 1 ||
				map[x + 1][y - 1] >= 1 ||
				map[x - 1][y]     >= 1 ||
				map[x - 1][y + 1] >= 1 ||
				map[x - 1][y - 1] >= 1) {
				setting_pos = 0;
				break;
			}
																		// проверка выше должна быть до поля с расстановки по координатам
			switch (dir)												// в зависимости от направления
			{
			case 0:													    // корабль растет вправо		
				x++;
				break;
			case 1:														// корабль растет вниз	
				y++;
				break;
			case 2:														// корабль растет влево	
				x--;
				break;
			case 3:														// корабль растет вверх	
				y--;
				break;
			}
		}

		if (setting_pos == 1)											// если предыдущ проверка пройдена - если можно ставить корабли
		{
			x = temp_x;													// берем значение из сохраненных
			y = temp_y;													// чтобы расстановка началась с нужных коорд

			for (size_t i = 0; i < size_ship; i++) {					// size_ship-палуб, цикл расстановки значений в массив
				map[x][y] = ship_id;
				switch (dir)											// в зависимости от направления
				{
				case 0:													// корабль растет вправо		
					x++;
					break;
				case 1:												    // корабль растет вниз	
					y++;
					break;
				case 2:													// корабль растет влево	
					x--;
					break;
				case 3:													// корабль растет вверх	
					y--;
					break;
				}
			}
			count_ship++;  // считаем установленные корабли
		}
	}
}

void map_show(int map[N][N], int mask[N][N], bool use_mask) {			// ф-ия, вывод поля с кораблями
																		// вывод поля c кораблями на экран
	std::cout << " ";
	for (size_t i = 0; i < N; i++) {
		std::cout << i;
	}
	std::cout << std::endl;

	for (size_t i = 0; i < N; i++) {
		std::cout << i;
		for (size_t j = 0; j < N; j++)
		{
			if (mask[i][j] == 1 || use_mask == 0) {						// проверить содержание ячейки маски
																		// если равна 1 - выводим мар, иначе пробел
				if (map[i][j] == 0) {
					std::cout << "-";
				}
				else if (map[i][j] == -1) {
					std::cout << "x";
				}
				else if (map[i][j] == -2) {
					std::cout << ".";
				}
				else {
					std::cout << map[i][j];
				}
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

int shoot
(int map[N][N], int x, int y, int ships[NUM_SHIPS + 1], int mask[N][N]) {  // ф-ия для стрельбы

	int result = 0;														   // результат стрельбы
	if (map[x][y] >= 1)
	{																	   // если содержимое ячейки равно 1 - там есть корабль
		ships[map[x][y]]--;												   // доступ к ячейке ships - к палубам, при попадании минусуем
		if (ships[map[x][y]] <= 0) {									   // если палуб не осталось			
			result = 1;
		}
		else {
			result = 1;
		}
		map[x][y] = -1;													   // пометить попадание в корабль
	}
	else
	{
		map[x][y] = -2;													   // если промах
	}	
	mask[x][y] = 1;
	return result;
}


