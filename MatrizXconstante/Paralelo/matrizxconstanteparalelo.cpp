#include "OpenCLHelper.h"
#include <iostream>
#include <array>
#include <time.h>
#define CL_USE_DEPRECATED_OPENCL_2_0_APIS

int main()
{
	cl::Program program = CreateProgram("matrizxconstanteparalelo.cl");
	clock_t tempodeex;
	auto context = program.getInfo<CL_PROGRAM_CONTEXT>();
	auto devices = context.getInfo<CL_CONTEXT_DEVICES>();
	auto& device = devices.front();

	const int linhas = 3000;
	const int colunas = 60000;
	const int count = linhas * colunas;
	std::array<std::array<int, colunas>, linhas> arr;


	auto vendor = device.getInfo<CL_DEVICE_VENDOR>();
	vendor = device.getInfo<CL_DEVICE_VENDOR>();
	auto maxworkitem = device.getInfo<CL_DEVICE_MAX_WORK_ITEM_SIZES>();

	maxworkitem = device.getInfo<CL_DEVICE_MAX_WORK_ITEM_SIZES>();

	for (int i = 0; i < linhas; i++)
	{
		for (int y = 0; y < colunas; y++)
		{
			arr[i][y] = 4;
		}

	}

	for (int i = 0; i < 1; i++)
	{
		for (int y = 0; y < 1; y++)
		{
			printf("%d ", arr[linhas][y - 1]);
		}
		printf("\n");
	}


	cl::Buffer buf(context, CL_MEM_READ_WRITE | CL_MEM_HOST_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(int) * count, arr.data());
	cl::Kernel kernel(program, "matrizxconstanteparalelo");
	kernel.setArg(0, buf);

	cl::CommandQueue queue(context, device);
	tempodeex = clock();
	queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(3000, 60000), cl::NDRange(16, 16));
	//err = queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(196777216), cl::NDRange(256));
	queue.enqueueReadBuffer(buf, GL_TRUE, 0, sizeof(int) * count, arr.data());
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