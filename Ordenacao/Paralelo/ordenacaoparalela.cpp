#include "OpenCLHelper.h"
#include <CL/cl.hpp>
#include <iostream>
#include <time.h>
#define CL_USE_DEPRECATED_OPENCL_2_0_APIS


int main()
{

	//Declaração de variável responsável por medir o tempo
	clock_t tempodeex;

	cl::Program program = CreateProgram("ordenacaoparalela.cl");
	auto context = program.getInfo<CL_PROGRAM_CONTEXT>();
	auto devices = context.getInfo<CL_CONTEXT_DEVICES>();
	auto& device = devices.front();

	auto vendor = device.getInfo<CL_DEVICE_VENDOR>();
	vendor = device.getInfo<CL_DEVICE_VENDOR>();
	auto maxworkitem = device.getInfo<CL_DEVICE_MAX_WORK_ITEM_SIZES>();

	maxworkitem = device.getInfo<CL_DEVICE_MAX_WORK_ITEM_SIZES>();
	tempodeex = clock();
	//std::vector<int> vec(2);  //TESTE
	//std::vector<int> vec(1000);  //PEQUENA
	//std::vector<int> vec(90000000);	//MEDIA
	//std::vector<int> vec(16777216);	//GRANDE
	std::vector<int> vec(100000);


	cl_int err = 0;



	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] = rand();
	}
	/*
	for (int i = 0; i < vec.size(); i++)
	{

		printf("%d ", vec[i]);
	}
	*/
	printf("\n");

	cl::Buffer inBuf(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, sizeof(int) * vec.size(), vec.data(), &err);
	cl::Kernel kernel(program, "ProcessArray");






	cl::CommandQueue queue(context, device);
	//err = queue.enqueueFillBuffer(inBuf, 2, NULL, sizeof(int) * (vec.size()));
	for (int i = 0; i < 100; i++)
	{
		kernel.setArg(0, inBuf);
		queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(vec.size()-1));
	}
	err = queue.enqueueReadBuffer(inBuf, CL_TRUE, 0, sizeof(int)* vec.size(), vec.data());



	//err = queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(vec.size()));
	//err = queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(8091456), cl::NDRange(256));





	int contador = 0;
	for (int i = 0; i < 1; i++)
	{

		contador = contador + 1;
	}

	tempodeex = clock() - tempodeex;

	printf("\n\nO tempo de execução foi de:\n%f milisegundos", ((float)tempodeex) / CLOCKS_PER_SEC);
	printf("\n");
	/*
	for (int i = 0; i < vec.size(); i++)
	{

		printf("%d ", vec[i]);
	}
	*/

	std::cin.get();

}