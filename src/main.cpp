#include <iostream>
#include <string>
#include <fstream> 
#include <vector>

std::vector<std::string> get_tasks_list()
{
    // open the tasks file or create a new one if not exist
    std::fstream tasks_file {"tasks.txt", std::ios::in | std::ios::out | std::ios::app};

    std::vector<std::string> tasks_list;

    if(!tasks_file.is_open())
    {
        std::cout << "Unable to open the file." << std::endl;
    }
    else
    {
        // loop through the file and extract each line
        // as a task and push it to the tasks list
        std::string single_task;
        
        while(getline(tasks_file, single_task))
        {
            tasks_list.push_back(single_task);
        }

        // close the file
        tasks_file.close();
    }

    return tasks_list;
}

void display_tasks(std::vector<std::string> & tasks_list)
{
    // display all tasks
    unsigned short int line {1};

    std::cout << "\n[Tasks]\n" << std::endl;

    for(auto &task: tasks_list)
    {
        std::cout << "[" << line << "] " << task << std::endl;
        line++;
    }
}

void add_task(std::string task)
{
    // open the tasks file or create a new one if not exist
    std::fstream tasks_file {"tasks.txt", std::ios::in | std::ios::out | std::ios::app};

    if(!tasks_file.is_open())
    {
        std::cout << "Unable to open the file to add a new task." << std::endl;
    }
    else
    {
        tasks_file << task << "\n";

        // close the file
        tasks_file.close();
    }
}

void rewrite_tasks_to_file(std::vector<std::string> &tasks_list)
{
    // open the tasks file or create a new one if not exist
    std::fstream tasks_file {"tasks.txt", std::ios::out | std::ios::trunc};

    if(!tasks_file.is_open())
    {
        std::cout << "Unable to open the file to rewrite tasks to it." << std::endl;
    }
    else
    {
        for(auto & line: tasks_list)
        {
            tasks_file << line << '\n';
        }

        // close the file
        tasks_file.close();
    }
}

void remove_task_from_list(std::vector<std::string> tasks_list,  size_t line_number)
{
    if(line_number > 0 && line_number <= tasks_list.size())
    {
        tasks_list.erase(tasks_list.begin() + (line_number - 1));
        rewrite_tasks_to_file(tasks_list);
    }
}

void display_help()
{
    std::cout << "\n" <<
    "* list     : to list all tasks.\n" <<
    "* add      : to add a new task to the list.\n" <<
    "* remove   : to remove a task from the list.\n" <<
    "* exit     : to exit the program.\n" <<
    std::endl;
}

int main()
{
    // display the main menu of shortcuts
    std::string option;
    
    std::cout <<
    "------------------------------------------------\n" << 
    "- [Welcome to My Tasks]\n" <<
    "- You can use the following shortcuts\n" <<
    "------------------------------------------------\n" <<
    std::endl;

    display_help();

    do
    {
        std::cout << "\n-> ";

        getline(std::cin, option);

        /* option-> list */
        if(option == "list")
        {
            auto tasks_list = get_tasks_list();        

            display_tasks(tasks_list);
        }

        /* option-> add */
        else if(option == "add")
        {
            // add a new task
            std::cout << "New task: ";

            std::string new_task;

            getline(std::cin, new_task);

            add_task(new_task);
        }

        /* option-> remove */
        else if (option == "remove")
        {
            // remove a task
            int line_num {0};
            std::cout << "Task ID: ";

            // get & store the line number
            std::cin >> line_num;

            std::cin.ignore();

            auto tasks_list = get_tasks_list();

            remove_task_from_list(tasks_list, line_num);
        }

        /* option-> exit */
        else if (option == "exit")
        {
            // exit
            std::cout << "Goodby!" << std::endl;
            break;
        }

        /* option-> help */
        else if(option == "help")
        {
            display_help();
        }

        /* option-> anything else ... */
        else
        {
            // invalid option
            std::cout << "You entered an invalid option." << std::endl;
        }
    } 
    while (option != "exit");

    return 0;
}