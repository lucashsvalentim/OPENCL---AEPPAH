__kernel void ProcessArray(__global int* data)
{
size_t id = get_global_id(0);
size_t id2 = get_global_id(0) + 1;

 
//break;
 
if(data[id] > data[id2])
{
int aux = data[id];
data[id] = data[id2];
data[id2] = aux;
}

}