#include <cctype>
#include "../include/TasksList.h"

TasksList::TasksList(std::string file_name_val)
{
    file_name = file_name_val;
}


std::vector<Task> TasksList::get_tasks_from_file()
{
    file.open(file_name, std::ios::in);

    std::vector<Task> tasks_list;

    if(!file.is_open())
    {
        std::cout << "Unable to open the file. from [get_tasks_list()]" << std::endl;
    }
    else
    {
        std::string single_task;
        
        while(getline(file, single_task))
        {
            tasks_list.push_back(Task{single_task});
        }
    }

    file.close();

    return tasks_list;
}


// void TasksList::print_list()
// {
//     for(auto & task: list)
//     {
//         std::cout << task.get() << std::endl;
//     }
// }


void TasksList::display()
{
    list = get_tasks_from_file();

    unsigned short int line {1};

    std::cout << "\n[Tasks]\n" << std::endl;

    for(auto &task: list)
    {
        std::cout << "[" << line << "] " << task.get() << std::endl;
        line++;
    }
}


void TasksList::rewrite_tasks_to_file()
{
    if(!file.is_open())
    {
        std::cout << "Unable to open the file to rewrite tasks to it." << std::endl;
    }
    else
    {
        for(auto & task: list)
        {
            file << task.get() << '\n';
        }
    }
}


void TasksList::add(Task task)
{
    list = get_tasks_from_file();
    file.open(file_name, std::ios::out | std::ios::trunc);

    if(!file.is_open())
    {
        std::cout << "Unable to open the file to add a new task." << std::endl;
    }
    else
    {
        list.push_back(task);
        rewrite_tasks_to_file();
    }

    file.close();
}


void TasksList::remove(int task_number)
{
    if(task_number <= 0)
    {
        std::cout << "Please, enter a valid task number to remove." << std::endl;
    }
    else
    {
        list = get_tasks_from_file();
        file.open(file_name, std::ios::out | std::ios::trunc);

        if(task_number > 0 && task_number <= list.size())
        {
            list.erase(list.begin() + (task_number - 1));
            rewrite_tasks_to_file();
        }
        else
        {
            std::cout << "Sorry, unable to remove the task." << std::endl;
        }

        file.close();
    }

    
}


// TasksList::~TasksList()
// {
//     file.close();
// }