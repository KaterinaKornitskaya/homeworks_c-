// Project_dz_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
/*
Вантажний літак має пролетіти з вантажем із пункту А в пункт С через пункт В. 
Ємність бака для палива в літака — 300 літрів. 
Споживання палива на 1 км залежно від ваги вантажу в літака наступне:
■ до 500 кг: 1 літрів/км;
■ до 1000 кг: 4 літрів/км;
■ до 1500 кг: 7 літрів/км;
■ до 2000 кг: 9 літрів/км;
■ більше ніж 2000 кг літак не піднімає.
Користувач вводить відстань між пунктами А і В, і відстань між пунктами В і С, а також вагу вантажу. 
Програма має розрахувати, яка мінімальну кількість палива необхідна для дозаправки літака в пункті В, 
щоб долетіти з пункту А в пункт С. 
У разі неможливості подолати будьяку з відстаней, 
програма має вивести повідомлення про неможливість польоту за введеним маршрутом.
*/
{
	setlocale(LC_ALL, "Russian");
	float distance_ab;         // расстояние между пунктами А и В, вводится пользователем
	float distance_bc;         // расстояние между пунктами В и С, вводится пользователем
	const int capacity = 300;  // емкость бака, 300 л.
	int weight;                // вес груза, вводится пользователем 
	float res;                 // переменная для результата
	int sp0to500 = 1;          // потребление топлива, л/кг, при весе груза до 500 кг 
	int sp500to1000 = 4;       // потребление топлива, л/кг, при весе груза от 500 до 1000 кг 
	int sp1000to1500 = 7;      // потребление топлива, л/кг, при весе груза от 1000 до 1500 кг 
	int sp1500to2000 = 9;      // потребление топлива, л/кг, при весе груза от 1500 до 2000 кг 
	
	std::cout << "Введите расстояние между пунктами A и B: " << std::endl;
	std::cin >> distance_ab;
	std::cout << "Введите расстояние между пунктами B и C: " << std::endl;
	std::cin >> distance_bc;
	std::cout << "Введите вес груза: " << std::endl;
	std::cin >> weight;

	if (weight < 500 && distance_ab <= capacity / sp0to500 && distance_bc <= capacity / sp0to500
		&& ((distance_ab + distance_bc) > (capacity / sp0to500)))
	{
		res = (distance_ab + distance_bc) - capacity / sp0to500;
		std::cout << "Вам необходимо дозаправится на : " << res << " литров.";
	}
	/*
	выше - условие, на сколько нужно дозаправится, если груз = до 500 кг
	доп условия:
	- расстояние между А и В не должно превышать емкость бака деленное на потребление при грузе до 500 
		- иначе самолет не долетит до В - не хватит емкости бака на такое расстояние
	- расстояние между В и С не должно превышать емкость бака деленное на потребление при грузе до 500 
		- иначе самолет не долетит из В в С - не хватит емкости бака на такое расстояние
	- расстояние АВ и расстояние ВС в сумме - больше, чем емкость бака деленное на потребление при грузе до 500
		- иначе программа выдает дозаправку с минусовым значением (когда дозаправка не требуется, но программу считает минус, излишек
	*/

	else if (weight >= 500 && weight < 1000 && distance_ab <= capacity / sp500to1000 && distance_bc <= capacity / sp500to1000
		&& ((distance_ab + distance_bc) > (capacity / sp500to1000)))
	{
		res = (distance_ab + distance_bc) - capacity / sp500to1000;
		std::cout << "Вам необходимо дозаправится на : " << res << " литров.";
	}
	/*
	выше - условие, на сколько нужно дозаправится, если груз = от 500 до 1000 кг
	доп условия - те же, что и для груза до 500 кг
	*/

	else if (weight >= 1000 && weight < 1500 && distance_ab <= capacity / sp1000to1500 && distance_bc <= capacity / sp1000to1500
		&& ((distance_ab + distance_bc) > (capacity / sp1000to1500)))
	{
		res = (distance_ab + distance_bc) - capacity / sp1000to1500;
		std::cout << "Вам необходимо дозаправится на : " << res << " литров.";
	}
	/*
	выше - условие, на сколько нужно дозаправится, если груз = от 1000 до 1500 кг
	доп условия - те же, что и для груза до 500 кг
	*/

	else if (weight >= 1500 && weight < 2000 && distance_ab <= capacity / sp1000to1500 && distance_bc <= capacity / sp1500to2000
		&& ((distance_ab + distance_bc) > (capacity / sp1500to2000)))
	{
		res = (distance_ab + distance_bc) - capacity / sp1500to2000;
		std::cout << "Вам необходимо дозаправится на : " << res << " литров.";
	}
	/*
	выше - условие, на сколько нужно дозаправится, если груз = от 1500 до 2000 кг
	доп условия - те же, что и для груза до 500 кг
	*/

	else if (weight < 500 && ((distance_ab + distance_bc) < (capacity / sp0to500))
		|| weight >= 500 && ((distance_ab + distance_bc) < (capacity / sp500to1000))
		|| weight >= 1000 && weight < 1500 && ((distance_ab + distance_bc) < (capacity / sp1000to1500))
		|| weight >= 1500 && weight < 2000 && ((distance_ab + distance_bc) < (capacity / sp1500to2000))
		)
	{
		std::cout << "Дозаправка не нужна.";
	}
	// выше - условие, при котором дозаправка не нужна

	else if (weight < 500 && distance_ab > capacity / sp0to500
		|| weight >= 500 && weight <1000 && distance_ab > capacity / sp500to1000 && distance_bc < capacity / sp500to1000
		|| weight >= 1000 && weight <1500 && distance_ab > capacity / sp1000to1500 && distance_bc < capacity / sp1000to1500
		|| weight >= 1500 && weight <2000 && distance_ab > capacity / sp1500to2000 && distance_bc < capacity / sp1500to2000
		)
	{
		std::cout << "Ошибка! Дистанция между A и B слишком большая";
		return -1;
	}
	/*
	выше - ошибка, если самолет не может преодолеть дистанция между А и В при разных вариантах веса груза
	при этом дистанция между В и С допустима
	*/

	else if (weight < 500 && distance_bc > capacity / sp0to500
		|| weight >= 500 && weight <1000 && distance_bc > capacity / sp500to1000 && distance_ab < capacity
		|| weight >= 1000 && weight <1500 && distance_bc > capacity / sp1000to1500 && distance_ab < capacity
		|| weight >= 1500 && weight <2000 && distance_bc > capacity / sp1500to2000 && distance_ab < capacity
		)
	{
		std::cout << "Ошибка! Дистанция между B и C слишком большая";
		return -1;
	}
	/*
	выше - ошибка, если самолет не может преодолеть дистанция между В и С при разных вариантах веса груза
	при этом дистанция между А и В допустима
	*/

	else if (weight < 500 && distance_ab > capacity / sp0to500 && distance_bc > capacity / sp0to500
		|| weight >= 500 && weight <1000 && distance_bc > capacity / sp500to1000 && distance_ab > capacity / sp500to1000
		|| weight >= 1000 && weight <1500 && distance_bc > capacity / sp1000to1500 && distance_ab > capacity / sp1000to1500
		|| weight >= 1500 && weight <2000 && distance_bc > capacity / sp1500to2000 && distance_ab > capacity / sp1500to2000
		)
	{
		std::cout << "Ошибка! Дистанция между A и B и B и C слишком большая";
		return -1;
	}
	// выше - ошибка, если самолет не может преодолеть дистанция между А и В и В и С при разных вариантах веса груза

	else if (weight >= 2000)
	{
		std::cout << "Ошибка! Груз слишком большой для взлета!";
		return -1;
	}
	// выше - ошибка, если груз превышает 2000 кг.

	return 0;
}


int main3()
/*
Користувач вводить з клавіатури 7 цілих чисел.
Напишіть програму, яка визначає максимальне з цих 7 чисел
(підказка — рішення має бути простим).
*/
{
	long long num1, num2, num3, num4, num5, num6, num7;  // числа, вводимые пользователем, long long для ввода больших чисел
														 // либо использовть int, и указать ограничение (от...до)

	std::cout << "Enter seven integer numbers" << std::endl << "1st number --> ";
	std::cin >> num1;
	std::cout << "2nd number --> ";
	std::cin >> num2;
	std::cout << "3rd number --> ";
	std::cin >> num3;
	std::cout << "4th number --> ";
	std::cin >> num4;
	std::cout << "5th number --> ";
	std::cin >> num5;
	std::cout << "6ht number --> ";
	std::cin >> num6;
	std::cout << "7th number --> ";
	std::cin >> num7;

	if (num1 == num2 || num1 == num3 || num1 == num4 || num1 == num5 || num1 == num6 || num1 == num7
		|| num2 == num3 || num2 == num4 || num2 == num5 || num2 == num6 || num2 == num7
		|| num3 == num4 || num3 == num5 || num3 == num6 || num3 == num7
		|| num4 == num5 || num4 == num6 || num4 == num7
		|| num5 == num6 || num5 == num7
		|| num6 == num7)  // условие, что не должны быть введены одинаковые числа
						  // в условии не было, но если это не указать, 
						  // и ввести 2 одинаковых числа - не выдает верный результат
	{
		std::cout << "Error! You have entered several identical numbers";

		return -1;
	}
	else if (num1 > num2 && num1 > num3 && num1 > num4 && num1 > num5 && num1 > num6 && num1 > num7)
	{
		std::cout << "The biggest number is " << num1;  // условие, при котором число 1 больше остальных
	}
	else if (num2 > num1 && num2 > num3 && num2 > num4 && num2 > num5 && num2 > num6 && num2 > num7)
	{
		std::cout << "The biggest number is " << num2;  // условие, при котором число 2 больше остальных  
	}
	else if (num3 > num1 && num3 > num2 && num3 > num4 && num3 > num5 && num3 > num6 && num3 > num7)
	{
		std::cout << "The biggest number is: " << num3;  // условие, при котором число 3 больше остальных
	}
	else if (num4 > num1 && num4 > num2 && num4 > num3 && num4 > num5 && num4 > num6 && num4 > num7)
	{
		std::cout << "The biggest number is: " << num4;  // условие, при котором число 4 больше остальных
	}
	else if (num5 > num1 && num5 > num2 && num5 > num3 && num5 > num4 && num5 > num6 && num5 > num7)
	{
		std::cout << "The biggest number is: " << num5;  // условие, при котором число 5 больше остальных
	}
	else if (num6 > num1 && num6 > num2 && num6 > num3 && num6 > num4 && num6 > num5 && num6 > num7)
	{
		std::cout << "The biggest number is: " << num6;  // условие, при котором число 6 больше остальных
	}
	else if (num7 > num1 && num7 > num2 && num7 > num3 && num7 > num4 && num7 > num5 && num7 > num6)
	{
		std::cout << "The biggest number is: " << num7;  // условие, при котором число 7 больше остальных
	}

	return 0;
}


int main2()
/*
Користувач вводить чотиризначне число.
Необхідно змінити в цьому числі 1 і 2 цифри, а також 3 і 4 цифри.
Якщо користувач вводить не чотиризначне число, вивести повідомлення про
помилку.
*/
{
	int number;			   // число, вводимое пользователем
	short n1, n2, n3, n4;  // цифры, из которых состоит число

	std::cout << "Enter four-digit number" << std::endl << std::endl;
	std::cin >> number;

	n4 = number - ((number / 10) * 10);
	n3 = (number / 10) - ((number / 100) * 10);
	n2 = (number / 100) - ((number / 1000) * 10);
	n1 = number / 1000;

	if (number < 1000 || number > 9999)  // условиe, что число является 4-значным (от 1000 до 9999)
	{
		std::cout << "Error! This number isn't a four-digit number"
			<< std::endl;

		return -1;  // указание на ошибку, если число не 4-значное
	}
	else
	{
		std::cout << n2 << n1 << n4 << n3
			<< std::endl;
	}

	return 0;
}

int main1()
/*
Користувач вводить з клавіатури ціле шестизначне число.
Написати програму, яка визначає, чи є введене число щасливим
(щасливим вважається шестизначне число, у якого сума
перших 3 цифр дорівнює сумі других трьох цифр).
Якщо користувач ввів НЕ шестизначне число — повідомлення про помилку.
*/
{
	setlocale(LC_ALL, "Russian");

	int number;                    // число, вводимое пользователем, переменная int  - так как число будет не > 999999
	short n1, n2, n3, n4, n5, n6;  // цифры, из которых состоит число, переменная short - числа маленькие (от 1 до 9)

	std::cout << "Введите шестизначное число" << std::endl;
	std::cin >> number;

	n6 = number - ((number / 10) * 10);
	n5 = (number / 10) - ((number / 100) * 10);
	n4 = (number / 100) - ((number / 1000) * 10);
	n3 = (number / 1000) - ((number / 10000) * 10);
	n2 = (number / 10000) - ((number / 100000) * 10);
	n1 = number / 100000;

	if (number < 100000 || number > 999999)  // условия, что число должно быть шестизначным (не < 10000 и не > 999999)
	{
		std::cout << "Ошибка, Ваше число не является шестизначным"
			<< std::endl;

		return -1;  // указывает на ошибку, если число введено неверно
	}
	else if ((n1 + n2 + n3) == (n4 + n5 + n6))
	{
		std::cout << "Ух ты! У вас счастливое число."
			<< std::endl;
	}
	else
	{
		std::cout << "Упс... Ваше число не счастливое."
			<< std::endl;
	}

	return 0;
}
