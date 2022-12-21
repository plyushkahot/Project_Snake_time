#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include "AppleGeneration.h";
using namespace std;

extern int n, m;//размер сетки
extern string dir;//RIGHT LEFT UP DOWN
extern double speed;//скорость игры
extern vector<pair<int, int>> snake;//вектор пар который содержит координату каждой части змейки
extern int applex, appley;//начальные координаты яблока

void moveSnake();