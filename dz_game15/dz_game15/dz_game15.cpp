﻿// dz_game15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <time.h>

#define gotoxy(x,y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y })

/*
 Гра "пятнашки"
Задача: реалізувати підрахунок кількості зроблених кроків
а) виводити номер кроку під час гри
б) виводити останнє повідомлення - за скільки кроків виграно
*) реалізувати можливість повторити гру (після виграшу)
*/

int main()
{
    const short N = 4;
    short field[N][N];
    const char
        lt = (char)218,  // ┌
        rt = (char)191,  // ┐
        lb = (char)192,  // └
        rb = (char)217,  // ┘
        hl = (char)196,  // ─
        vl = (char)179;  // │
    char c;          // клавіша, яку натискає користувач
    short x, y;      // циклові змінні - координати поля
    short x0, y0;    // координати порожньої (нульової) комірки
    bool was_move;   // чи був зроблений хід
    bool game_over;  // чи кінець гри
    
    char play_again;  // символьна змінна для продовження/завершення гри
    


    // заповнюємо поле числами від 1 до 15, в кінці 0

    for (y = 0; y < N; ++y) {
        for (x = 0; x < N; ++x) {
            field[y][x] = y * N + x + 1;
        }
    }
    x0 = y0 = N - 1;  // присвоєння x0 і y0 значення нуль
    field[y0][x0] = 0;
    do {
        system("cls");
        
    // Перемішуємо - робимо декілька випадкових ходів
    srand(time(NULL));
    for (x = 0; x < 5; ++x) {
        switch (rand() % 4) {  // rand() % 4  -від 0 до 3 - випадковий хід
        case 0:  // up
            if (y0 < N - 1) {
                field[y0][x0] = field[y0 + 1][x0];
                y0 += 1;
                field[y0][x0] = 0;               
            }
            break;
        case 1:  // left
            if (x0 < N - 1) {  // хід дозволений
                field[y0][x0] = field[y0][x0 + 1];
                x0 += 1;
                field[y0][x0] = 0;              
            }
            break;
        case 2:  // right
            if (x0 > 0) {
                field[y0][x0] = field[y0][x0 - 1];
                x0 -= 1;
                field[y0][x0] = 0;               
            }
            break;
        case 3:  // down
            if (y0 > 0) {
                field[y0][x0] = field[y0 - 1][x0];
                y0 -= 1;
                field[y0][x0] = 0;              
            }
        }
    }
    was_move = false;
    int moves = 0;
       
        do {  // ігровий цикл           
            ++moves;
            gotoxy(0, 2);  // виводимо поле у тому самому місці (затираємо попереднє)
        // Виводимо поле
        // рисуем рамку для игры
            std::cout << lt;
            for (x = 0; x < N; ++x) {
                std::cout << hl << hl << hl;
            }
            std::cout << hl << rt << std::endl;

            for (y = 0; y < N; ++y) {
                std::cout << vl;
                for (x = 0; x < N; ++x) {
                    if (field[y][x] == 0) {
                        std::cout << std::setw(3) << ' ';
                    }
                    else {
                        std::cout << std::setw(3) << field[y][x];
                    }
                }
                std::cout << ' ' << vl << std::endl;
            }
            std::cout << lb;
            for (x = 0; x < N; ++x) {
                std::cout << hl << hl << hl;
            }
            std::cout << hl << rb << std::endl;

            // Після аналізу натисненої клавіші перевіряємо чи зроблено хід
            if (was_move) {

                // Тут перевіряємо чи кінець гри
                game_over = true;
                for (y = 0; y < N; ++y) {
                    for (x = 0; x < N; ++x) {
                        if (field[y][x] != (y * N + x + 1) % (N * N)) {
                            game_over = false;
                        }
                    }
                }
                if (game_over) break;
            }

            // пропонуємо зробити хід
            std::cout << "Make a move";
            c = _getch();
            if (c == -32 || c == 0 || c == 224) {
                c = _getch();
            }
            if (c == 75 || c == 77 || c == 80 || c == 72)

            //was_move = false;  // скидаємо ознаку зробленого кроку
            // std::cout << (int)c;  // перевірити яка кнопка що означає
            switch (c) {
            case 72:  // up
                if (y0 < N - 1) {
                    field[y0][x0] = field[y0 + 1][x0];
                    y0 += 1;
                    field[y0][x0] = 0;
                    was_move = true;                   
                }
                else {  // рух неможливий
                    Beep(300, 300);
                }
                break;
            case 75:  // left
                if (x0 < N - 1) {  // хід дозволений
                    field[y0][x0] = field[y0][x0 + 1];
                    x0 += 1;
                    field[y0][x0] = 0;
                    was_move = true;                    
                }
                else {  // крайня комірка - рух неможливий
                    Beep(300, 300);
                }
                break;
            case 77:  // right
                if (x0 > 0) {
                    field[y0][x0] = field[y0][x0 - 1];
                    x0 -= 1;
                    field[y0][x0] = 0;
                    was_move = true;                  
                }
                else {  // рух неможливий
                    Beep(300, 300);
                }
                break;
            case 80:  // down
                if (y0 > 0) {
                    field[y0][x0] = field[y0 - 1][x0];
                    y0 -= 1;
                    field[y0][x0] = 0;
                    was_move = true;                  
                }
                else {  // рух неможливий
                    Beep(300, 300);
                }
                break;
            case 27:  // ESC
                break;
            default:  // якщо натисли якусь іншу клавішу
                Beep(700, 300);  // звук частотою 700 Гц, тривалістю 300 мс (з системних можливостей Windows)
            }
            gotoxy(0, 9);
            std::cout << moves << " moves\n";
 
        } while (c != 27);
        
        std::cout << "You are winner! You win in " << moves-1 << " moves." 
            << "\nPlay again? Press \"y\" if YES, or \"n\" if NO. ";
        std::cin >> play_again;

    }while (play_again == 'y');
    return 0;
}


