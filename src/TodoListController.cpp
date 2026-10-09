#include <string>
#include <stdexcept>

#include "TodoListController.h"

//constructor
TodoListController::TodoListController(TodoList& todolist)
    :m_todoList(todolist)
{

}

void TodoListController::addTask(std::string& title) const
{
    if(title.empty())
    {
        throw std::invalid_argument("title can not be empty");
    }
    m_todoList.addTask(title);
}

//calls TodoList::toggleFinishedStatus() which calls Task::toggleFinished()  
void TodoListController::toggleFinishedStatus(std::size_t& index) const
{
    m_todoList.toggleFinishedStatus(index);
}

const TodoList& TodoListController::getTodoList() const
{
    return m_todoList;
}