#include <iostream>
#include <string>
#include <vector>
//local imports
#include "Todolist.h"

//use console as UI for now
void printTodoList(const TodoList& todoList)
{
    const std::vector<Task>& tasklist = todoList.getTaskList();
    
    std::cout << "\n";
    std::cout << "----To Do List----\n";

    if(tasklist.empty())
    {
        std::cout << "no tasks added yet";
        return;
    }
    for(std::size_t i = 0; i<tasklist.size(); ++i)
    {
        const Task& task = tasklist[i];
        if(task.isFinished())
        {
            std::cout << i + 1 << ": [x] " << task.getTitle() << '\n';
        }
        else
        {
            std::cout << i + 1 << ": [ ] " << task.getTitle() << '\n';            
        }

        
    }
    //std::cout << "\n";
}

int main()
{
    TodoList todoList;

    while(true)
    {
        std::cout << "\n";
        std::cout << "------------\n";
        std::cout << "1: Add a task\n";
        std::cout << "2: List current tasks\n";
        std::cout << "3: Mark a task completed\n";
        std::cout << "4: Quit\n";
        std::cout << "------------\n";
        std::cout << "Enter option number: ";

        std::string userInput;
        std::getline(std::cin, userInput);
        int choiceNumber;

        try
        {
            //convert input string to integer
            std::size_t inputStringPosition;
            choiceNumber = std::stoi(userInput, &inputStringPosition); //std::stoi(const string& str, std::size_t* pos =nullptr)
            
            if(inputStringPosition != userInput.length())
            {
                std::cout<<"Please only enter a number\n";
                continue;
            }
        }
        catch(const std::invalid_argument)
        {
            std::cout << "Please enter a number\n";
            continue;
        }    
        
        
        if(choiceNumber < 1 || choiceNumber > 4)
        {
            std::cout << choiceNumber << " is not a valid option\n";
            continue;
        }

        
        switch(choiceNumber)
        {
            case 1: //add task
            {    
                //std::cin.get(); //clear new line from input buffer
                
                std::string title;
                std::cout << "Enter title for new task: ";
                std::getline(std::cin, title);
                if(!title.empty())
                {
                    todoList.addTask(title);
                }
                break;
            }
            
            case 2: //list existing tasks
            {    
                printTodoList(todoList);
                break;
            }
            case 3:
            {
                std::size_t taskNumber;

                std::cout << "Which task is completed? ";
                std::cin>>taskNumber;

                if(taskNumber > 0)
                {
                    todoList.finishTask(taskNumber - 1);
                    std::cout << "task: " << taskNumber << " marked complete\n";
                }
                break;
            }
            case 4:
            {
                return 0;
            }
        }
    }
    return 0;
}

//future changes: define an enum class for switch cases