#ifndef TASKSLIST_H
#define TASKSLIST_H

#include <string>
#include <vector>
#include <Task.h>

class TasksList
{
private:
    std::vector<Task> list;

public:
    TasksList(std::string file);
    void display();
    void add(Task task);
    void remove(int task_number);
    ~TasksList();
};

#endif // TASKSLIST_H