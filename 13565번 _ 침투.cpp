#include <stdio.h>
#include <stdlib.h>

char **matrix = NULL;
int row = 0;
int column = 0;

bool checkPercolate(int x, int y)
{
	if (x == (row - 1)) return true;

	bool result = false;
	bool result2 = false;
	bool result3 = false;
	bool result4 = false;

	matrix[x][y] = '1';

	if (matrix[x + 1][y] == '0') result = checkPercolate(x + 1, y);
	if (y != (column - 1) && matrix[x][y + 1] == '0') result2 = checkPercolate(x, y + 1);
	if (y != 0 && matrix[x][y - 1] == '0') result3 = checkPercolate(x, y - 1);
	if (x != 0 && matrix[x - 1][y] == '0') result4 = checkPercolate(x - 1, y);

	if (result || result2 || result3 || result4) return true;
	else return false;
}

int main()
{
	row = 0;
	column = 0;
	scanf("%d", &row);
	scanf("%d", &column);
	
	matrix = (char**)malloc(sizeof(char*)*row);
	
	for (int i = 0; i < row; i++)
	{
		matrix[i] = (char*)malloc((sizeof(char)*column) + 1);
		scanf("%s", matrix[i], (sizeof(char)*column) + 1);
	}

	bool flag = false;
	
	for (int i = 0; i < column; i++)
	{
		if (matrix[0][i] == '0')
		{
			flag = checkPercolate(0, i);
			if (flag) break;
		}
	}

	if (flag) puts("YES");
	else puts("NO");

	for (int i = 0; i < row; i++) free(matrix[i]);

	free(matrix);

	return 0;
}
