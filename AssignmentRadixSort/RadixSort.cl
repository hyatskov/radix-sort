// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
__kernel void RadixSort(
    __global const int* restrict input,
    __global       int* restrict output
    )
{
    uint GID = get_global_id(0);

    uint readIdx = GID;
    uint writeIdx = readIdx;

    int val = input[readIdx];
    //output[writeIdx] = val*val;

	// DEBUG code
	val += 17;
	output[writeIdx] = val*val;
}

__kernel void RadixSortReadWrite(
	__global int* array
	)
{
	uint GID = get_global_id(0);

	uint readIdx = GID;
	uint writeIdx = readIdx;

	//array[writeIdx] *= array[readIdx];
	//array[writeIdx] = array[writeIdx]*2;
}