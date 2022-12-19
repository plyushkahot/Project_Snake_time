#pragma once
#include <iostream>
#include <Windows.h>

extern int n, m;//размер сетки
extern char field[19][19]; //массив символов для отрисовки
extern int applex, appley; //начальные координаты яблок
void drawApple();
void drawBorder();
void cleanField();
