#include "OpenCLHelper.h"
#include <CL/cl.hpp>
#include <iostream>
#include <time.h>
#define CL_USE_DEPRECATED_OPENCL_2_0_APIS


int main()
{

	//Declaração de variável responsável por medir o tempo
	clock_t tempodeex;
	clock_t tempotot;
	cl::Program program = CreateProgram("vetorxvetor.cl");
	auto context = program.getInfo<CL_PROGRAM_CONTEXT>();
	auto devices = context.getInfo<CL_CONTEXT_DEVICES>();
	auto& device = devices.front();

	auto vendor = device.getInfo<CL_DEVICE_VENDOR>();
	vendor = device.getInfo<CL_DEVICE_VENDOR>();
	auto maxworkitem = device.getInfo<CL_DEVICE_MAX_WORK_ITEM_SIZES>();

	maxworkitem = device.getInfo<CL_DEVICE_MAX_WORK_ITEM_SIZES>();

	//std::vector<int> vec(2);  //TESTE
	//std::vector<int> vec(1000);  //PEQUENA
	//std::vector<int> vec(90000000);	//MEDIA
	std::vector<int> vec(10);	//GRANDE
    std::vector<int> vec2(10);
	int n = 10;


	cl_int err = 0;


	cl::Buffer inBuf(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, sizeof(int) * vec.size(), vec.data(), &err);
	cl::Buffer inBuf2(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, sizeof(int) * vec2.size(), vec2.data(), &err);
	cl::Buffer outBuf(context, CL_MEM_WRITE_ONLY, sizeof(int) * vec.size(), nullptr, &err);
	cl::Kernel kernel(program, "vetorxvetor");
	err = kernel.setArg(0, inBuf);
	err = kernel.setArg(1, outBuf);
	err = kernel.setArg(2, inBuf2);

	cl::CommandQueue queue(context, device);

	for (int i = 0; i < n; i++)
	{

		vec[i] = 1;
	}

	for (int i = 0; i < 1; i++)
	{

		printf("%d ", vec[n - 1]);
	}
	tempodeex = clock();
	tempotot = clock();
	err = queue.enqueueFillBuffer(inBuf, 4, NULL, sizeof(int) * (vec.size()));
	err = queue.enqueueFillBuffer(inBuf2, 4, NULL, sizeof(int) * (vec.size()));
	tempodeex = clock() - tempodeex;
	printf("\n\nO tempo de envio foi de:\n%f milisegundos", ((float)tempodeex) / CLOCKS_PER_SEC);
	printf("\n");
	tempodeex = 0;

	tempodeex = clock();
	err = queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(vec.size()));
	tempodeex = clock() - tempodeex;
	printf("\n\nO tempo de execucao foi de:\n%f milisegundos", ((float)tempodeex) / CLOCKS_PER_SEC);
	printf("\n");
	tempodeex = 0;

	tempodeex = clock();
	//err = queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(196777216), cl::NDRange(256));
	err = queue.enqueueReadBuffer(outBuf, CL_TRUE, 0, sizeof(int)* vec.size(), vec.data());
	tempotot = clock() - tempotot;
	tempodeex = clock() - tempodeex;
	printf("\n\nO tempo de recuperacao foi de:\n%f milisegundos", ((float)tempodeex) / CLOCKS_PER_SEC);
	printf("\n");
	//cl::finish();
	printf("\n\nO tempo TOTAL foi de:\n%f milisegundos", ((float)tempotot) / CLOCKS_PER_SEC);
	printf("\n");


	for (int i = 0; i < vec.size(); i++)
	{

		printf("%d ", vec[i]);
	}

	std::cin.get();

}