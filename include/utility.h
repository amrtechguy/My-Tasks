#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
#include <fstream> 
#include <vector>

#include "../include/Task.h"
#include "../include/TasksList.h"

/**
 * @brief Display a list of shortcuts supported by the program.
 * 
 * @param `void`.
 * @return `void`.
 */
void display_help()
{
    std::cout << "\n" <<
    "* list     : to list all tasks.\n" <<
    "* add      : to add a new task to the list.\n" <<
    "* remove   : to remove a task from the list.\n" <<
    "* help     : to display a list of valid shortcuts.\n" <<
    "* exit     : to exit the menu." <<
    std::endl;
}

/**
 * @brief The main menu that contains a list of
 * options that you can use to interact with the program.
 * 
 * Use the shortcut 'exit' to exit the menu and 
 * logout of the program.
 * 
 * @param `void`
 * @return `void`
 */
void display_menu()
{
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


        // Option `list`: displays all tasks
        if(option == "list")
        {
            TasksList tasks_list {"tasks.txt"};
            tasks_list.display();
        }

        // Option `add`: add a new task
        else if(option == "add")
        {
            std::cout << "New task: ";
            std::string new_task;
            getline(std::cin, new_task);

            TasksList tasks_list {"tasks.txt"};
            tasks_list.add(new_task);
        }

        // Option `remove`: remove a task based on 
        // its number in the tasks list
        else if (option == "remove")
        {
            int line_num {0};
            std::cout << "Task ID: ";

            std::cin >> line_num;
            std::cin.ignore();

            TasksList tasks_list {"tasks.txt"};
            tasks_list.remove((int)line_num);
        }

        // Option `exit`: exit the menu
        else if (option == "exit")
        {
            std::cout << "Goodby!\n" << std::endl;
            break;
        }

        // Option `help`: displays a list of shortcuts
        else if(option == "help")
        {
            display_help();
        }

        // Option `...`: any other option is invalid
        else
        {
            std::cout << "You entered an invalid option. Enter 'help' for available shortcuts." << std::endl;
        }
    }

    // Keep displaying the menu until you get `exit`
    while (option != "exit");
}

#endif // UTILITY_H