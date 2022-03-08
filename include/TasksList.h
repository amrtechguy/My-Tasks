#ifndef TASKSLIST_H
#define TASKSLIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Task.h"

class TasksList
{
private:
    std::fstream file;
    std::string file_name;
    std::vector<Task> list;

public:
    TasksList(std::string file_name);
    void display();
    void add(Task task);
    void remove(int task_number);
    std::vector<Task> get_tasks_from_file();
    void rewrite_tasks_to_file();
    // void print_list();
    // ~TasksList();
    
};

#endif // TASKSLIST_H