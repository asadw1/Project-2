#ifndef MEMORY_MANAGER_H_
#define MEMORY_MANAGER_H_

// Pre-defined block size of 20MB
// 1 MB = 1024*1024 bytes, so 20MB = 20*1024*1024 bytes
// an int is 4 bytes. So our block size is = (20*1024*1024)/4 = 5242880

#define BLOCK_SIZE 5242880 // represents 20MB
// We need to divide that number up into a static array 

// global memory block with size 20 MB
// simulated as an array of integers
// by default empty, so all values are 0
// when memory gets occupied, all occupied cells of the array set to 1
int MemoryBlock[BLOCK_SIZE]= {};

class MemoryManager
{
public:	
	void* my_malloc(int size);
	void* my_free(void* ptr);

private:
	MemoryManager();
	~MemoryManager();
	


};

#endif

