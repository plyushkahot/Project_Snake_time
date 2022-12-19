#include "DrawField.h";
void setcur(int x, int y)//установка курсора на позицию  x y 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
void drawField()//
{
	setcur(0, 0);
	//system("cls");
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << "  ";
		for (int j = 0; j < m; j++)
		{
			if (applex == i && appley == j)
				cout << "\033[31m" << field[i][j] << field[i][j];
			else
				if (i == 0 || i == n || j == 0 || j == m)
					cout << "\033[33m" << field[i][j] << field[i][j];
				else
					cout << "\033[32m" << field[i][j] << field[i][j];

		}

		cout << "\n";
	}
	cout << "\033[0m" << "\n  SCORE: " << snake.size() - 3 << "\n  Speed: " << 80 / speed << "\n";
}
