#include <stdio.h>
#include <stdlib.h>

int **fill(int row, int column)
{
	int i, j;
	int **a = (int**)malloc(sizeof(int*)*row);
	for (i = 0; i < row; i++)
		a[i] = (int*)malloc(sizeof(int)*column);
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			a[i][j] = rand() % 100;
		}
	}
	return a;
}


void output(int **a, int row, int column)
{
	int j, i;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
    }
	printf("\n");
}


void min(int **a, int row, int colum)
{
	int i, j, min;
	for (i = 0; i < row; i++)
	{
		min =10000;
		for (j = 0; j < colum; j++)
		{
			if (a[i][j]<min)
				min = a[i][j];
		}
		printf("row %d% d\n",i,min);
	}
}

int main()
{
	int row, column;
	int **arr;
	int n;
	printf("size: ");
	scanf("%d%d", &row, &column);
	arr = fill(row, column);
	output(arr, row, column);
	min(arr, row, column);

return 0;
}
