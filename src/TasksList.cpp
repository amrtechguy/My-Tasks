#include <cctype>
#include "../include/TasksList.h"

/**
 * @brief Construct a new TasksList
 * 
 * @param file_name_val the full path of the tasks file.
 */
TasksList::TasksList(std::string file_name_val)
{
    file_name = file_name_val;
}


/**
 * @brief Open the tasks file for reading.
 * 
 * Load the tasks from the file and create a `Task`
 * object from each task.
 * 
 * Push it to a vector of `Task` objects.
 * 
 * @param void.
 * 
 * @return std::vector<Task> a vector of `Task` objects.
 */
std::vector<Task> TasksList::get_tasks_from_file()
{
    // Open the tasks file for reading
    file.open(file_name, std::ios::in);

    // Define a vector for storing `Task` objects
    std::vector<Task> tasks_list;

    // Check if the file is open
    if(!file.is_open())
    {
        std::cout << "Unable to open the file. from [get_tasks_list()]" << std::endl;
    }
    else
    {
        // Define a string variable to store each laoded task
        std::string single_task;
        
        // Loop through the tasks file and store 
        // each line `task` in the variable `single_task`
        while(getline(file, single_task))
        {
            // Push a Task object from each `single_task` to
            // the variable `tasks_list`
            tasks_list.push_back(Task{single_task});
        }
    }

    // Close the file
    file.close();

    return tasks_list;
}


/**
 * @brief Display all tasks to the console.
 * 
 * @param void.
 * 
 * @return void. 
 */
void TasksList::display()
{
    list = get_tasks_from_file();

    // Each task will have a number strating from 1
    unsigned short int line {1};

    std::cout << "\n[Tasks]\n" << std::endl;

    // Check if the list is empty
    if(list.size() == 0)
    {
        std::cout << "The list is empty. Enter `add` to add new tasks." << std::endl;
    }
    else
    {
        // Loop through the tasks and print them to the screen.
        // Each task will be presceeded by a number that identifies it.
        for(auto &task: list)
        {
            std::cout << "[" << line << "] " << task.get() << std::endl;
            line++;
        }
    }
}


/**
 * @brief Rewrite the tasks stored in the variable `tasks_list`
 * to the original tasks file.
 * 
 * This method overrides the original file.
 * 
 * @param void.
 * 
 * @return void. 
 */
void TasksList::rewrite_tasks_to_file()
{
    // Check if the file is open
    if(!file.is_open())
    {
        std::cout << "Unable to open the file to rewrite tasks to it." << std::endl;
    }
    else
    {
        // Loop through the tasks and print each one to
        // the original tasks file with a new line character `\n`
        // at the end of each task.
        for(auto & task: list)
        {
            file << task.get() << '\n';
        }
    }
}


/**
 * @brief Add a new task to the variable tasks_list, then
 * call the method `get_tasks_from_file` to rewrite
 * the tasks to the original file.
 * 
 * @param task an object of Task class that stores the
 * task content as a string.
 * 
 * @return void.
 */
void TasksList::add(Task task)
{
    list = get_tasks_from_file();

    // open the tasks file for writting and overriding
    file.open(file_name, std::ios::out | std::ios::trunc);

    // Check if the file is open
    if(!file.is_open())
    {
        std::cout << "Unable to open the file to add a new task." << std::endl;
    }
    else
    {
        // push the new task to the tasks list.
        list.push_back(task);

        rewrite_tasks_to_file();
    }

    file.close();
}

/**
 * @brief Remove a task from the list based on its number in the list.
 * 
 * @param task_number an integer number that represent the task's order
 * in the list.
 * 
 * @return void.
 */
void TasksList::remove(int task_number)
{
    if(task_number <= 0)
    {
        std::cout << "Please, enter a valid task number to remove." << std::endl;
    }
    else
    {
        list = get_tasks_from_file();

        // Open the tasks file for writting and overriding
        file.open(file_name, std::ios::out | std::ios::trunc);

        // Check if the task number is between 1 and the list size
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
