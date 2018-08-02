#include <string>
#include <fstream>
#include <iostream>
#include <time.h>

#define CL_USE_DEPRECATED_OPENCL_2_0_APIS
int main()
{
	clock_t tempodeex;
	int x = 196777216;
	//std::vector<int> vec(2);  //TESTE
	//std::vector<int> vec(1000);  //PEQUENA
	//std::vector<int> vec(1000000);	//MEDIA
    /*std::vector<int> vec(x);	//GRANDE
	std::vector<int> vec2(x);
	*/


	int *vec;
	int *vec2;
	int num = 196777216;

	vec = (int *)malloc(sizeof(int) * num);
	vec2 = (int *)malloc(sizeof(int) * num);

	int len = sizeof(vec) / sizeof(int);



	tempodeex = clock();
	for (int i = 0; i < num; i++)
	{
		vec[i] = 4;
	}

	for (int i = 0; i < num; i++)
	{
		vec2[i] = vec[i] * 2;
	}
	tempodeex = clock() - tempodeex;

	printf("\n\nO tempo de execução foi de:\n%f milisegundos", ((float)tempodeex) / CLOCKS_PER_SEC);
	printf("\n");

	int contador = 0;
	for (int i = 0; i < 1; i++)
	{
		contador = contador + 1;

		printf("%d ", vec2[x-1]);
	}


	std::cin.get();

}

