#ifndef MEMORY_MANAGER_H_
#define MEMORY_MANAGER_H_

// Pre-defined block size of 20MB
// 1 MB = 1024*1024 bytes, so 20MB = 20*1024*1024 bytes
// an int is 4 bytes. So our block size is = (20*1024*1024)/4 = 5242880

extern const int BLOCK_SIZE = 5242880; // represents 20MB

class MemoryManager
{
public:	
	void my_malloc();
	void my_free();

private:
	MemoryManager();
	~MemoryManager();
	


};

#endif

