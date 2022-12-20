#pragma once // подключение единожды 
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

extern vector<pair<int, int>> snake; //вектор пар который содержит координату каждой части змейки

bool snakeIsAlive();