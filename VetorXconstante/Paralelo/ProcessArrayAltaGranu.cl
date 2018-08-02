kernel void ProcessArray(__global int* data, __global int* outData)
{
    int gid = get_global_id(0);  
		outData[gid] = data[gid] * 2;
}
