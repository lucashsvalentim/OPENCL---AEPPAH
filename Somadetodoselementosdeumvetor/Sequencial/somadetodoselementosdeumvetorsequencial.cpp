#include <string>
#include <fstream>
#include <iostream>
#include <time.h>

int main()
{
	clock_t tempodeex;
	
	int *vec;

	int num = 33554432;

	vec = (int *)malloc(sizeof(int) * num);

	

	for (int i = 0; i < num; i++)
	{
		vec[i] = 1;
	}

	tempodeex = clock();
	int acumulador = 0;
	for (int i = 0; i < num; i++)
	{
		acumulador += vec[i];
	}
	printf("%d ", acumulador);

	tempodeex = clock() - tempodeex;

	printf("\n\nO tempo de execução foi de:\n%f milisegundos", ((float)tempodeex) / CLOCKS_PER_SEC);
	printf("\n");






	std::cin.get();

}

