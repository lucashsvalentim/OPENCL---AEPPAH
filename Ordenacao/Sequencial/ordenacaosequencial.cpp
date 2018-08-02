#include <string>
#include <fstream>
#include <iostream>
#include <time.h>

int main()
{
	clock_t tempodeex;

	int *vec;

	int num = 100000;

	int aux = 0;

	vec = (int *)malloc(sizeof(int) * num);


	for (int i = 0; i < num; i++)
	{
		vec[i] = rand();
	}
	/*
	for (int i = 0; i < num; i++)
	{
		printf("%d ", vec[i]);
	}
	*/
	printf("\n");
	
	tempodeex = clock();
	for (int i = 0; i < num; i++)
	{
		for (int y = 0; y < num-1; y++)
		{
			if (vec[y] > vec[y+1])
			{
				aux = vec[y];
				vec[y] = vec[y + 1];
				vec[y + 1] = aux;

			}

		}

	}
	/*
	for (int i = 0; i < num; i++)
	{
		printf("%d ", vec[i]);
	}
	*/
	tempodeex = clock() - tempodeex;

	printf("\n\nO tempo de execução foi de:\n%f milisegundos", ((float)tempodeex) / CLOCKS_PER_SEC);
	printf("\n");

	std::cin.get();

}

