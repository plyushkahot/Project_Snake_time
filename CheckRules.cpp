#include "CheckRules.h";

bool snakeIsAlive() //проверка не врезалась ли змейка сама в себя
{
	for (int i = 0; i < snake.size(); i++)
	{
		if (i != 0)
			if (snake[i].first == snake[0].first && snake[i].second == snake[0].second)
				// если части змеи равны, то есть соприкоснулись 
				return false;
	}
	return true;
}