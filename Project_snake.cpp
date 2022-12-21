#include <iostream>
#include <vector>
#include <ctime>
#include <Windows.h>
#include "SnakeMovement.h";
#include "DrawField.h";
#include "CheckRules.h"
HANDLE hConsole; //для раскраски консоли
using namespace std;

int n = 19, m = 19;//размер сетки
char field[19][19];//массив символов для отрисовки
string dir = "RIGHT";//RIGHT LEFT UP DOWN
double speed = 80;//скорость игры
vector<pair<int, int>> snake;//вектор пар который содержит координату каждой части змейки
int applex = 8, appley = 13;//начальные координаты яблока

int main()
{
	system("title Snake"); // имя окна консоли
	
	while (true) // бесконечное выполнение программы 
	{
		// присваиваем начальные данные змейки(т.к. в ходе программы они изменяются)
		n = 19;
		m = 19;
		field[19][19];
		dir = "RIGHT";
		speed = 80;
		snake.clear();
		applex = 8; 
		appley = 13;
		
		// добавлям 3 части тела(координаты) нашей змейки
		snake.push_back(make_pair(8, 4));
		snake.push_back(make_pair(8, 3));
		snake.push_back(make_pair(8, 2));


		// выбираем уровень
		int level;
		int timeLive;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 10); //красим консоль в зелёный цвет
		cout << "\n" << "==========================\n";
		cout << "$$       GAME SNAKE     $$\n";
		cout << "==========================\n";
		SetConsoleTextAttribute(hConsole, 15); //красим консоль в белый цвет
		cout << " -  1 level - 10 second  -\n";
		cout << " -  2 level - 60 second  -\n";
		cout << " -  3 level - 90 second  -\n";
		cout << " -  4 level - 120 second -\n";
		cout << " -  5 level - 150 second -\n";
		cout << " -  6 level - 180 second -\n";
		cout << " -  7 level - 210 second -\n";
		cout << " -  8 level - 240 second -\n";
		cout << " -  9 level - 270 second -\n";
		cout << " -  9 level - 300 second -\n";
		SetConsoleTextAttribute(hConsole, 10); //зелёный цвет текста в консоли
		cout << "==========================\n\n";

		SetConsoleTextAttribute(hConsole, 15); //возвращаем белый цвет текста в консоли
		cout << "\n Enter level:\n\n > ";
		cin >> level;

		// присваиваем в зависимости от уровня опреелённое количество времени
		switch (level)
		{
		case 1:
			timeLive = 10000;
			break;
		case 2:
			timeLive = 60000;
			break;
		case 3:
			timeLive = 90000;
			break;
		case 4:
			timeLive = 120000;
			break;
		case 5:
			timeLive = 150000;
			break;
		case 6:
			timeLive = 180000;
			break;
		case 7:
			timeLive = 210000;
			break;
		case 8:
			timeLive = 240000;
			break;
		case 9:
			timeLive = 270000;
			break;
		case 10:
			timeLive = 300000;
			break;
		}

		// создаём таймер и инициализируем 0, для того чтобы в следующей итерации цикла таймер начиналс заново
		unsigned int resultTime = 0;

		unsigned int startTime = 0;

		// запускаем таймер
		startTime = clock();

		// переменная указывающая на то, врезалась ли наша змейка сама в себя
		bool check = true;

		// переменная которая говорит о том выиграли ли мы
		bool checkWin = false;
		
		// запускаем игру
		while (check)
		{
			// если змейка врезалась сама в себя то устанавливаем в check false
			if (!snakeIsAlive()) check = false;

			// считываем нажатия клавиш и в зависимости от клавиши устанавлеваем в  dir направление
			if (GetAsyncKeyState(VK_UP)) {
				if (dir != "DOWN") dir = "UP";
			}
			else if (GetAsyncKeyState(VK_DOWN)) {
				if (dir != "UP") dir = "DOWN";
			}
			else if (GetAsyncKeyState(VK_LEFT)) {
				if (dir != "RIGHT") dir = "LEFT";
			}
			else if (GetAsyncKeyState(VK_RIGHT)) {
				if (dir != "LEFT") dir = "RIGHT";
			}
			// подклчаем другие модули
			moveSnake();
			cleanField();
			drawApple();
			drawSnake();
			drawBorder();
			drawField();
			// создаём задержку, чтобы змейка не двигалась слишком быстро
			if (dir == "LEFT" || dir == "RIGHT")
				Sleep(speed);
			else
				Sleep(speed * 2);
			
			// засекаем конец времени
			unsigned int endTime = clock();

			resultTime = endTime - startTime;
			// проверяем больше ли оно задонного, если да завершаем игру
			if (resultTime > timeLive)
				break;

			// выводим таймер
			cout <<"  Time: " << (timeLive/1000 -  resultTime/1000) - 1 << "\n\n";
			// проверяем если время закончилось, то мы выиграли и устанавиваем в checkWin в true
			if (((timeLive / 1000 - resultTime / 1000) - 1) == 0) checkWin = true;
		}
		// если выиграли вводим имя победителя
		if (checkWin)
		{
			cout << "\nYOU WIN!!!\n";
			string name;
			cout << "ENTER NAME: ";
			cin >> name;
		}
		else
			//если проиграли выводим GAME OVER
			cout << "\nGAME OVER\n";

		system("pause");
		system("cls");
	}
}
