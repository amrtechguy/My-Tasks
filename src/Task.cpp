#include <iostream>
#include "../include/Task.h"

Task::Task(std::string content_val)
    : content {content_val}
{}

std::string Task::get()
{
    return content;
}