#ifndef TASKSLIST_H
#define TASKSLIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Task.h"

/**
 * @brief The main class the handles everything relating to the tasks 
 * including loading tasks from the original  file, displaying them to the console, 
 * adding new tasks, removing tasks, and rewritting to the tasks file.
 */
class TasksList
{
private:
    // An object from the class `fstream` to open and handle 
    // the tasks file
    std::fstream file;

    // A variable to store the full path of the tasks file 
    std::string file_name;

    // A vector of `Task` objects to store the tasks
    std::vector<Task> list;

public:
    TasksList(std::string file_name);

    void display();

    void add(Task task);

    void remove(int task_number);

private:
    std::vector<Task> get_tasks_from_file();

    void rewrite_tasks_to_file(); 
};

#endif // TASKSLIST_H