void drawBorder()
{
	char border = char(178);
	for (int i = 1; i < n ; i++)
	{
		field[i][0] = border;
		field[i][m] = border;
	}
	for (int i = 0; i < m; i++)
	{
		field[0][i] = border;
		field[n][i] = border;
	}
}
