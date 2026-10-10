#include <string>
#include <stdexcept>
#include <iostream>

#include "TodoListUI.h"

TodoListUI::TodoListUI(TodoListController& controller)
    : m_controller(controller)
{
}

void TodoListUI::run()
{
    //repeats presentation of menu options and handles cases
    while(true)
    {
        printOptionsMenu();
        const int choice = getMenuChoice();

        switch(choice)
        {
            case 1:
                addTask();
                break;
            
            case 2:
                printTodoList();
                break;
            
            case 3:
                finishTask();
                break;
            case 4:
                return;
        }
    }
}

//display functions
void TodoListUI::printTodoList() const
{
    const std::vector<Task>& tasklist = m_controller.getTodoList().getTaskList();

    
    if(tasklist.empty())
    {
        std::cout << "no tasks added yet\n";
        return;
    }

    std::cout << "\n----To Do List----\n";
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
}

void TodoListUI::printOptionsMenu() const
{
        std::cout << "\n";
        std::cout << "------------\n";
        std::cout << "1: Add a task\n";
        std::cout << "2: List current tasks\n";
        std::cout << "3: Mark a task completed\n";
        std::cout << "4: Quit\n";
        std::cout << "------------\n";
}

/*interact with user*/
std::string TodoListUI::getUserInput(const std::string& prompt) const
{
    std::string userText;
    std::cout<<prompt;
    std::getline(std::cin, userText);
    return userText;
}

int TodoListUI::getIntegerInputInRange(const std::string& prompt, int min, int max) const
{
    while(true)
    {
        const std::string input = getUserInput(prompt);
        try
        {
            const int number = convertToInteger(input);
            if(isInRange(number, min, max))
            {
                return number;
            }
            std::cout<<"must be between "<< min << " and " << max << "\n";
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr <<"invalid input: "<< e.what()<<"\n";
        }
    }    
}


int TodoListUI::getMenuChoice() const
{
    std::string prompt = "Choose a menu option: ";
    int rangeStart = 1;
    int rangeEnd = 4;
    
    return getIntegerInputInRange(prompt, rangeStart, rangeEnd);
}


//controller tasks
void TodoListUI::addTask()
{
    std::string title = getUserInput("Title? ");
    try
    {
        m_controller.addTask(title);
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << e.what() << "\n";
    }
}

void TodoListUI::finishTask()
{
    //perhaps edit helper functions to avoid casting
    const std::size_t numberOfTasks = m_controller.getTodoList().getTaskCount();
    int rangeStart = 1;
    int rangeEnd = static_cast<int>(numberOfTasks);

    if(numberOfTasks == 0)
    {
        std::cout<<"There are no tasks to complete \n";
        return;
    }
    //get task number and validate it exists
    const int taskNumber = getIntegerInputInRange("Which task is done? ",rangeStart, rangeEnd);
    
    m_controller.toggleFinishedStatus(static_cast<std::size_t>(taskNumber-1));

    std::cout<<"Task "<<taskNumber<< " is complete\n";
}

//helpers
int TodoListUI::convertToInteger(const std::string& input) const
{
        std::size_t inputStringPosition;
        int number = std::stoi(input, &inputStringPosition); //std::stoi(const string& str, std::size_t* pos =nullptr)
        
        //reject edge case of numerical input with trailing characters(1q, 2w, 14r)
        if(inputStringPosition != input.length())
        {
           throw std::invalid_argument("trailing characters found");
        }
        return number;
}

bool TodoListUI::isInRange(const int input, int min, int max) const
{
    return (input>=min && input<=max);
}