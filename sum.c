#include <stdio.h>
#include <stdlib.h>


int **fill(int row, int column) {

	int i, j;
	int **a = (int**)malloc(sizeof(int*)*row);
	for (i = 0; i < row; i++)
		a[i] = (int*)malloc(sizeof(int)*column);
	for (i = 0; i < row; i++) {

		for (j = 0; j < column; j++) {

			a[i][j] = rand() % 100;
		}
	}
	return a;
}

int sum(int **a, int row, int colum)
{
	int i, j;
	int s = 0;
	for (i = 0; i < row; i++) {

		for (j=0;j<colum;j++) {

			s += a[i][j];
		}
	}
	return printf("%d\n",s);
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

int main()
{
	int row, column;
	int **arr;
	int n;
	printf("size: ");
	scanf("%d%d", &row, &column);
	arr = fill(row, column);
	output(arr, row, column);
	sum(arr,row,column);


return 0;
}
