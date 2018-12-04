#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N = 25


int arr[N];

int output(int a[])
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d", a[i]);
	return 0;
}

int player()
{
	int k, k1, k2;
	printf("stones quantity\n");
	scanf("%d",&k);

	if(k==1){
        scanf("%d", &k1);
		arr[k1] = 0;
	}
	else if (k==2){
        scanf("%d%d", &k1, &k2);
		arr[k1] = 0;
		arr[k2] = 0;
	}

	return 0;
}


int array_list()
{
	int i;
	int a[25];
	for (i = 0; i < N; i++)
	a[i] = i;
	for (i = 0; i < N; i++)
		printf("%3d", a[i]);
	return 0;
}


int bot()
{
	int i,n,k,k1,k2;
	int counter = 0;
	n = rand() % 2 + 1;
	for (i = 0; i < N-1; i++)
	{
		if (arr[i] + arr[i + 1] > 1)
			counter++;
	}

	if (counter == 0){
		n = 1;
		do{
			k = rand() % 26;
            }
		while (arr[k] == 0);
		arr[k] = 0;
	}
	else
	{
		do
		{
			k1 = rand() % 25;
			k2 = k1 + 1;
		} while (arr[k1] == 0 || arr[k2]==0);
		arr[k1] = 0;
		arr[k2] = 0;
	}

	return 0;
}


int check(int *prov)
{
	bool k;
	int i;
	for (i = 0; i < N; i++)
	{
		if (prov[i] == 0)
		{
			k = true;
		}
		else
		{
			k = false;
			break;
		}
	}
	if (k == false)
		return 1;
	else
		return 0;
}


int main()
{
	int i;
	for (i = 0; i < N; i++)
		arr[i] = 1;

	do
	{
			array_list();
			printf("\n");
			output(arr);
			printf("\n");
			player();
			if (check(arr) == 0)
			{
				printf("player win");
				break;
			}

			bot();
			if (check(arr) == 0)
			{
				printf("bot win");
				break;
			}

	} while (true);

	return 0;
}

