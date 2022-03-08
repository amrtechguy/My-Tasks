#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
#include <fstream> 
#include <vector>

#include "../include/Task.h"
#include "../include/TasksList.h"

void display_help()
{
    std::cout << "\n" <<
    "* list     : to list all tasks.\n" <<
    "* add      : to add a new task to the list.\n" <<
    "* remove   : to remove a task from the list.\n" <<
    "* help     : to display shortcuts.\n" <<
    "* exit     : to exit the program." <<
    std::endl;
}

void display_menu()
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
            TasksList tasks_list {"tasks.txt"};
            tasks_list.display();
        }

        /* option-> add */
        else if(option == "add")
        {
            std::cout << "New task: ";
            std::string new_task;
            getline(std::cin, new_task);

            TasksList tasks_list {"tasks.txt"};
            tasks_list.add(new_task);
        }

        /* option-> remove */
        else if (option == "remove")
        {
            int line_num {0};
            std::cout << "Task ID: ";

            std::cin >> line_num;
            std::cin.ignore();

            TasksList tasks_list {"tasks.txt"};
            tasks_list.remove((int)line_num);
        }

        /* option-> exit */
        else if (option == "exit")
        {
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
            std::cout << "You entered an invalid option. Enter 'help' for available shortcuts." << std::endl;
        }
    } 
    while (option != "exit");
}

#endif // UTILITY_H