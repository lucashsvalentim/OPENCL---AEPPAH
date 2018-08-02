#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
#include <array>

#define CL_USE_DEPRECATED_OPENCL_2_0_APIS
int main()
{
	clock_t tempodeex;
	
	
	const int linhas = 3000;
	const int colunas = 60000;
	const int count = linhas * colunas;
	std::array<std::array<int, colunas>, linhas> arr;

	for (int i = 0; i < linhas; i++)
	{
		for (int y = 0; y < colunas; y++)
		{
			arr[i][y] = 4;
		}

	}
	tempodeex = clock();
	for (int i = 0; i < linhas; i++)
	{
		for (int y = 0; y < colunas; y++)
		{
			arr[i][y] = arr[i][y] * 2;
		}

	}
	
	tempodeex = clock() - tempodeex;

	printf("\n\nO tempo de execução foi de:\n%f milisegundos", ((float)tempodeex) / CLOCKS_PER_SEC);
	printf("\n");

	for (int i = 2999; i < linhas; i++)
	{
		for (int y = 59999; y < colunas; y++)
		{
			printf("%d ", arr[i][y]);
		}
		printf("\n");
	}


	std::cin.get();

}