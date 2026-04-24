#include "ProcessManagement.hpp"
#include <iostream>
#include <cstring>
#include <memory>
#include <sys/wait.h>
#include "../encryptDecrypt/Cryption.hpp"

ProcessManagement::ProcessManagement() {}

bool ProcessManagement::sumbitToQueue(std::unique_ptr<Task> task)
{
    taskQueue.push(std::move(task));
    return true;
}

void ProcessManagement::executeTask() 
{
   while(!taskQueue.empty()) {
	   std::unique_ptr<Task> taskToExecute = std::move(taskQueue.front());
	   taskQueue.pop();
	   std::cout << "Executing task: " << taskToExecute->toString() << std::endl;
	   executeCryption(taskToExecute->toString());
   }
}
