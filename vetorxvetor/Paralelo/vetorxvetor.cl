__kernel void vetorxvetor(__global int* data, __global int* outData, __global int* data2)
{
 outData[get_global_id(0)] = data[get_global_id(0)] * data2[get_global_id(0)];
}