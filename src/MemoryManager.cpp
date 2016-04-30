#include "MemoryManager.h"
#include "Process.h"
#include <cstdlib>

MemoryManager::MemoryManager()
{
    
}

MemoryManager::~MemoryManager()
{
	
}

void* MemoryManager::my_malloc(unsigned int size, unsigned int PID)
{
	// call the system’s malloc() function once to request the initial 20MB
	// size block
	mem_block *block = (mem_block *)malloc(BLOCK_SIZE);
	unsigned int blockIndex = 0, sizeCount = 0, startIndex = 0;

	while(blockIndex < BLOCK_SIZE)
	{
		if(block[blockIndex].isAllocated == 1)
		{
			sizeCount = 0; // reset size count
			blockIndex++;
			startIndex = blockIndex;
		} 
		else
		{
			sizeCount++;
		}
	}


}

void* MemoryManager::my_free(void* ptr)
{

}
