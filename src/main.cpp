#include <iostream>
#include <string>
#include <fstream> 
#include <vector>

int main()
{
    // display the main menu of shortcuts
    std::string option;
    
    std::cout <<
    "------------------------------------------------\n" << 
    "- [Welcome to My Tasks]\n" <<
    "- You can use the following shortcuts\n" <<
    "------------------------------------------------\n" <<
    "* list     : to list all tasks.\n" <<
    "* add      : to add a new task to the list.\n" <<
    "* remove   : to remove a task from the list.\n" <<
    "* exit     : to exit the program.\n";

    do
    {
        std::cout << "\n-> ";

        getline(std::cin, option);

        // open the tasks file or create a new one if not exist
        std::fstream tasks_file {"tasks.txt", std::ios::in | std::ios::out | std::ios::app};

        /* option-> list */
        if(option == "list")
        {
            // list all tasks
            std::cout << "\n[Tasks]\n" << std::endl;
            
            // check if the file is open
            if(!tasks_file.is_open())
            {
                std::cout << "Unable to open the tasks file." << std::endl;
            }
            else
            {
                // loop through the file and extract each line
                // as a task and push it to the tasks list
                std::vector<std::string> tasks_list;

                std::string single_task;
                
                while(getline(tasks_file, single_task))
                {
                    tasks_list.push_back(single_task);
                }

                // display all tasks
                unsigned short int line {1};
                for(auto &task: tasks_list)
                {
                    std::cout << "[" << line << "] " << task << std::endl;
                    line++;
                }

                // close the file
                tasks_file.close();
            }
        }

        /* option-> add */
        else if(option == "add")
        {
            // add a new task
            std::cout << "New task: ";
            std::string new_task;
            getline(std::cin, new_task);
            tasks_file << new_task << "\n";
        }

        /* option-> remove */
        else if (option == "remove")
        {
            // remove a task
            std::cout << "Task ID: ";
        }

        /* option-> exit */
        else if (option == "exit")
        {
            // exit
            std::cout << "Goodby!" << std::endl;
            break;
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