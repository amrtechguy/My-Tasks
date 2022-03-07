#ifndef TASK_H
#define TASK_H

#include <string>

class Task
{
private:
    std::string content;

public:
    Task(std::string content_val);
    void display();
};

#endif // TASK_H