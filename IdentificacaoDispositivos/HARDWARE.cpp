#include <CL/cl.hpp>
#include <iostream>
#define CL_USE_DEPRECATED_OPENCL_2_0_APIS

int main()
{
	std::vector<cl::Platform> platforms;
	cl::Platform::get(&platforms);

	_ASSERT(platforms.size() > 0);

	auto platform = platforms.front();
	std::vector<cl::Device> devices;
	platform.getDevices(CL_DEVICE_TYPE_ALL, &devices);

	_ASSERT(devices.size() > 0);

	auto device = devices[0];
	auto vendor = device.getInfo<CL_DEVICE_VENDOR>();
	auto version = device.getInfo<CL_DEVICE_VERSION>();
	auto maxworkitem = device.getInfo<CL_DEVICE_MAX_WORK_ITEM_SIZES>();
	int maxworkgroupsize = device.getInfo<CL_DEVICE_MAX_WORK_GROUP_SIZE>();

	maxworkitem = device.getInfo<CL_DEVICE_MAX_WORK_ITEM_SIZES>();
	maxworkgroupsize = device.getInfo<CL_DEVICE_MAX_WORK_GROUP_SIZE>();

	printf(" %d\n", maxworkgroupsize);

	int qtdplataformas = 0;
	int qtddevices = 0;

	qtdplataformas = platforms.size();
	qtddevices = devices.size();

	for (int y = 0; y < qtdplataformas; y++)
	{
		 platform = platforms[y];
		 printf("Plataforma : %d\n", y);

		for (int w = 0; w < qtddevices; w++)
		{
			device = devices[w];
			vendor = device.getInfo<CL_DEVICE_VENDOR>();
			version = device.getInfo<CL_DEVICE_VERSION>();

			printf("Fabricante: ");
			for (int i = 0; i < 30; i++)
			{
				printf("%c", vendor[i]);
			}
			printf("\n");
			printf("Versao OpenCL: ");
			for (int i = 0; i < 30; i++)
			{
				printf("%c", version[i]);
			}
			printf("\n");
		}
	}
	
	std::cin.get();

}

