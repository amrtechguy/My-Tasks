#include <iostream>
#include "../include/Task.h"

Task::Task(std::string content_val)
    : content {content_val}
{}

void Task::display()
{
    std::cout << content << std::endl;
}