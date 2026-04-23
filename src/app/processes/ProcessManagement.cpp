#include "ProcessManagement.hpp"
#include <iostream>
#include <cstring>

ProcessManagement::ProcessManagement() {}

bool ProcessManagement::sumbitToQueue(std::unique_ptr<Task> task)
{
    taskQueue.push(std::move(task));
    return true;
}

void ProcessManagement::executeTask() 
{
    
}