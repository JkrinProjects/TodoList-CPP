//manages the Todolist class so that Todolist only has to 

#include <string>
#include <stdexcept>
#include <vector>

#include "TodoListController.h"

//constructor
TodoListController::TodoListController(TodoList& todolist)
    :m_todoList(todolist)
{

}
void TodoListController::addTask(const std::string& title) const
{
    m_todoList.addTask(title);
}

//delegates to TodoList::toggleFinishedStatus() to validate index and toggle state
void TodoListController::toggleFinishedStatus(std::size_t index) const
{
    m_todoList.toggleFinishedStatus(index);
}

void TodoListController::markFinished(std::size_t index) const
{
    m_todoList.finishTask(index);
}

void TodoListController::toggleFinishedStatus(std::size_t index) const
{
    m_todoList.finishTask(index);
}

void TodoListController::deleteTask(std::size_t index) const
{
    m_todoList.deleteTask(index);
}

std::size_t TodoListController::getTaskCount() const
{
    return m_todoList.getTaskCount();

}

const Task& TodoListController::getTask(std::size_t index) const
{
    const std::vector<Task>& tasks = m_todoList.getTaskList();

    if (index >= tasks.size())
    {
        throw std::out_of_range("There are not that many tasks");
    }
    return tasks[index];
}



