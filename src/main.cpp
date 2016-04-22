/*
* Group Members: 
* Chad Smith
* Jimmy Yeung
* Asad Waheed 
*/

#include "ProcessSet.h"
#include "Helpers.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void sleepNanoSeconds(int sleepTime)
{
    auto sleepStart = chrono::high_resolution_clock::now();
    int sleepedNanoSeconds = 0;
    do
    {
        sleepedNanoSeconds = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - sleepStart).count();
    }
    while(sleepedNanoSeconds < sleepTime);
}

/*  Part one:
 *  Assuming that the combined memory requirement of all 64 processes is less than 20 MB, use the system calls malloc()
 *  and free() to dynamically allocate and de-allocate memory to your processes. Measure the total system time that is
 *  required to simulate the execution of your 64 processes.
 */
int memorySimulatePartOne(ProcessSet process_set) {
    
    cout << "Starting Memory Simulateion Part One" << endl;
    
    
    auto totalTimeStart = chrono::high_resolution_clock::now();
    
    void *allocatedMemory = NULL;
    
    // Run all 64 processes
    while(process_set.GetNumberProcesses() > 0) {
        auto memAllocStart = chrono::high_resolution_clock::now();
        
        Process currentProcess = process_set.FirstProcess();
        
        cout << "Starting process " << currentProcess.processId << endl;
        
        int memoryFootPrintForCurrentProcess = currentProcess.memoryFootprint;
        
        // Allocate memory for this process
        allocatedMemory = malloc(memoryFootPrintForCurrentProcess * 1024); // The memory footprint is in KB
        
        if (allocatedMemory == NULL) {
            cout << "Error allocating memory for process with process ID " << currentProcess.processId << endl ;
            return -2;
        }
        // free the memory for this process
        free(allocatedMemory);
        
        // Delete the process since we are done.
        process_set.PopProcess();
        
//        auto memAllocEnd = chrono::high_resolution_clock::now();
//        long long memAllocTimeSpent = (chrono::duration_cast<chrono::nanoseconds>(memAllocStart - memAllocEnd).count());
//        cout << "Current Process execution time was : " << memAllocTimeSpent << " nanoseconds" << endl;
        
//        // Assume one cycle time will take the cpu 1 milisecond to run
//        if (process_set.GetNumberProcesses() > 0) {
//            // 1000000 = milisecond
//            int sleepTime = 1000000 * currentProcess.numberCycles;
//            sleepNanoSeconds(sleepTime);
//        }
    }
    
    auto totalTimeEnd = chrono::high_resolution_clock::now();
    cout << "Total program execution time: " << (chrono::duration_cast<chrono::nanoseconds>(totalTimeEnd - totalTimeStart).count()) << " nanoseconds" << endl;
    
    return 1;
}

int main(int argc, char** argv)
{
    // Create a set of processes
    ProcessSet process_set;
    process_set.BuildProcessSet(std::cin);
    
    // Run Part one
    memorySimulatePartOne(process_set);
    
	return 0;
}