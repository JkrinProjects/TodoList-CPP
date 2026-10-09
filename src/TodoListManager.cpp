#include "TodoListManager.h"

#include <iostream>
#include <vector>
#include <cstddef>
#include <stdexcept>
#include <string>

//future changes: define an enum class for switch cases

void TodoListManager::run(TodoList& todoList)
{
    while(true)
    {
        printOptionsMenu();
        int choice = getMenuChoice();

        switch(choice)
        {
            case 1:
                addTask(todoList);
                break;
            
            case 2:
                printTodoList(todoList);
                break;
            
            case 3:
                finishTask(todoList);
                break;
            case 4:
                return;
        }
    }
}

void TodoListManager::printTodoList(const TodoList& todoList) const
{
    const std::vector<Task>& tasklist = todoList.getTaskList();
    
    std::cout << "\n";
    std::cout << "----To Do List----\n";

    if(tasklist.empty())
    {
        std::cout << "no tasks added yet\n";
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

void TodoListManager::printOptionsMenu() const
{
        std::cout << "\n";
        std::cout << "------------\n";
        std::cout << "1: Add a task\n";
        std::cout << "2: List current tasks\n";
        std::cout << "3: Mark a task completed\n";
        std::cout << "4: Quit\n";
        std::cout << "------------\n";

}

int TodoListManager::getMenuChoice() const
{
    while(true)
    {
        std::cout << "Enter option number: ";

        std::string userInput;
        std::getline(std::cin, userInput);

        int choiceNumber;
            try
            {
                //convert input string to integer
                std::size_t inputStringPosition;
                choiceNumber = std::stoi(userInput, &inputStringPosition); //std::stoi(const string& str, std::size_t* pos =nullptr)

                //catches strings that start with intgers but contain characters(typos like 1q, 2w)
                if(inputStringPosition != userInput.length())
                {
                    std::cout<<"invalid character detected: "<<userInput[inputStringPosition]<<"\n";
                    continue;
                }
                if(choiceNumber < 1 || choiceNumber > 4)
                {
                    std::cout << choiceNumber << " is not a valid option\n";
                    continue;
                }
                
                return choiceNumber;               
            }
            //catches input missing integer completely
            catch (const std::invalid_argument)
            {
                std::cout << "invalid input: Please enter a number\n";
                continue;
            }    
    }   
}

void TodoListManager::addTask(TodoList& todoList) const
{
    //std::cin.get(); //clear new line from input buffer
    
    std::string title;
    std::cout << "Enter title for new task: ";
    std::getline(std::cin, title);
    if(!title.empty())
    {
        todoList.addTask(title);
    }
    else
    {
        std::cout<<"title can not be empty\n";
    }
}

void TodoListManager::finishTask(TodoList& todoList) const
{
    std::string userInput;
    std::size_t todoListLength = todoList.getTaskCount();
    std::size_t indexOfTaskNumber;
    
    std::cout << "Which task is completed? ";
    std::getline(std::cin, userInput);
    
    
    try
    {
        //validate input is a correctly formatted integer 
        std::size_t position;
        int finishedTaskNumber = std::stoi(userInput, &position);
        if(position != userInput.length())
        {
            throw std::invalid_argument("please enter only integers");
        }
        //protect against overflow from negatives from size_t
        if(finishedTaskNumber < 1)
        {
            throw std::out_of_range("task number must be >= 1");
        }
        //validate number not greater than number of tasks
        indexOfTaskNumber = static_cast<std::size_t>(finishedTaskNumber);
        if(indexOfTaskNumber > todoListLength)
        {
            throw std::out_of_range("there are not that many tasks");
        }
        
        todoList.finishTask(indexOfTaskNumber - 1);
        std::cout << "task: " << indexOfTaskNumber << " marked complete\n";
    }
    catch(const std::out_of_range& e)
    {
        std::cout<<"invalid task number: "<< e.what()<< "\n";
    }
    catch(const std::invalid_argument& e)
    {
        std::cout<<"invalid input detected: "<< e.what() <<"\n";
    }
}