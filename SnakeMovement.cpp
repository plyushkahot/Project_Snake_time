#include "SnakeMovement.h";

// модуль отвечающий за передвижение нашей змейки
void moveSnake()
{
	int f = snake[0].first, s = snake[0].second;
	// в зависимости от напралени€ измен€ем координаты точек нашей змейки, а если клавиша не была нажата
	// просто перемещаем координаты змейки на 1 в ту сторону,в которую у нас она движетс€
	if (dir == "RIGHT") {
		if (snake[0].second == m - 2)
			snake[0].second = 1;
		else
			snake[0].second += 1;
	}
	if (dir == "LEFT") {
		if (snake[0].second == 1)
			snake[0].second = m - 2;
		else
			snake[0].second -= 1;
	}
	if (dir == "UP") {
		if (snake[0].first == 1)
			snake[0].first = m - 2;
		else
			snake[0].first -= 1;
	}
	if (dir == "DOWN") {
		if (snake[0].first == m - 2)
			snake[0].first = 1;
		else
			snake[0].first += 1;
	}

	if (snake[0].first == applex && snake[0].second == appley)// если голова съела €блоко то увеличиваем нашу змейку, т.е 
															  // доабвл€€ем ей ещЄ одну координату
	{
		snake.push_back(make_pair(0, 0));// добавл€ем координату и созадЄм новое €блоко
		newapple();
		if (speed > 10) // измен€ем скорость змейки
			speed -= 2;
	}

	// устанавливаем полученные координаты
	for (int i = 1; i < snake.size(); i++)
	{
		int f1, s1;
		f1 = snake[i].first;
		s1 = snake[i].second;
		snake[i].first = f;
		snake[i].second = s;
		f = f1;
		s = s1;
	}

}