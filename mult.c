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
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void multiply(int **arr1, int **arr2, int row,int column2)
{
	int i, j, k;
	int **mul = (int**)malloc(row * sizeof(int*));
	for (i = 0; i < row; i++)
		mul[i] = (int*)malloc(column2 * sizeof(int));
	for (i = 0; i < row; i++)
		for (j = 0; j < row; j++)
		{
			mul[i][j] = 0;
			for (k = 0; k < row; k++)
				mul[i][j] += arr1[i][k] * arr2[k][j];
		}
	output(mul,row,column2);
}

int main()
{
	int row, column, row1, column1, i;
	int **arr2; int **arr1;
	printf("size1: ");
	scanf("%d%d", &row, &column);
	printf("size2: ");
	scanf("%d%d", &row1, &column1);
	arr1 = fill(row, column);
	arr2 = fill(row1, column1);
	output(arr1, row, column);
	output(arr2, row1, column1);
	multiply(arr1, arr2, row, column1);
	
	
	return 0;
}
