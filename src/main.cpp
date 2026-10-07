#include <iostream>
#include <string>
#include <vector>
#include <print> //new print library
//local imports
#include "Todolist.h"

//use console as UI for now
void printTodoList(const TodoList& todoList)
{
    const std::vector<Task>& tasklist = todoList.getTaskList();

    std::println("----To Do List----");

    if(tasklist.empty())
    {
        std::println("no tasks added yet");
        return;
    }
    for(std::size_t i = 0; i<tasklist.size(); ++i)
    {
        const Task& task = tasklist[i];
        if(task.isFinished())
        {
            std::println("{}: [x] {}", i+1, task.getTitle());
        }
        else
        {
            std::println("{}: [ ] {}", i+1, task.getTitle());            
        }

        
    }
}

int main()
{
    TodoList todoList;

    while(true)
    {
        std::println("1: Add a task");
        std::println("2: list current tasks");
        std::println("3: mark a task completed");
        std::println("4: quit");
        std::println("Enter option number: ");

        int choiceNumber;
        std::cin >> choiceNumber;
        
        if(choiceNumber < 1 || choiceNumber > 4)
        {
            std::println("{} is not a valid option", choiceNumber);
        }

        
        switch(choiceNumber)
        {
            case 1: //add task
            {    
                std::cin.get(); //clear new line from input buffer
                
                std::string title;
                std::println("Enter title for new task: ");
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

                std::println("Which task is completed? ");
                std::cin>>taskNumber;

                if(taskNumber > 0)
                {
                    todoList.finishTask(taskNumber - 1);
                    std::println("task {} marked complete", taskNumber);
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