#include "OpenCLHelper.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#define CL_USE_DEPRECATED_OPENCL_2_0_APIS

int main()
{
	clock_t tempodeex;
	cl::Program program = CreateProgram("somadetodoselementosdeumvetor.cl");
	auto context = program.getInfo<CL_PROGRAM_CONTEXT>();
	auto devices = context.getInfo<CL_CONTEXT_DEVICES>();
	auto& device = devices.front();

	std::vector<int> vec(2048);

	for (int i = 0; i < vec.size(); ++i)
	{
		vec[i] = 1;
	}

	cl::Kernel kernel(program, "somadetodoselementosdeumvetor");

	auto workGroupSize = kernel.getWorkGroupInfo<CL_KERNEL_WORK_GROUP_SIZE>(device);

	auto numWorkGroups = vec.size() / workGroupSize;

	cl::Buffer buf(context, CL_MEM_READ_ONLY | CL_MEM_HOST_NO_ACCESS | CL_MEM_COPY_HOST_PTR, sizeof(int) * vec.size(), vec.data());
	cl::Buffer outBuf(context, CL_MEM_WRITE_ONLY | CL_MEM_HOST_READ_ONLY, sizeof(int) * numWorkGroups);

	kernel.setArg(0, buf);
	kernel.setArg(1, sizeof(int) * workGroupSize, nullptr);
	kernel.setArg(2, outBuf);

	std::vector<int> outVec(numWorkGroups);

	cl::CommandQueue queue(context, device);
	tempodeex = clock();
	queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(vec.size()), cl::NDRange(workGroupSize));   //WorkGroupSize Deve ser um multiplo de vec.size
	queue.enqueueReadBuffer(outBuf, GL_TRUE, 0, sizeof(int) * outVec.size(), outVec.data());
	tempodeex = clock() - tempodeex;
	printf("\n\nO tempo de execução foi de:\n%f milisegundos", ((float)tempodeex) / CLOCKS_PER_SEC);
	printf("\n");

	std::cin.get();

	//cl::Kernel(program,);

}