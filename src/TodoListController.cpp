//manages the Todolist class. Overkill for console but should be useful when UI is built

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

void TodoListController::deleteTask(std::size_t index) const
{
    m_todoList.deleteTask(index);
}

//getters
std::size_t TodoListController::getTaskCount() const
{
    return m_todoList.getTaskCount();

}

const Task& TodoListController::getTaskAtIndex(std::size_t index) const
{
    return m_todoList.getTaskAtIndex(index);
}

/*const std::vector<Task>& TodoListController::getFullTaskList() const
{
    const std::vector<Task>& tasks = m_todoList.getTaskList();

    if (tasks.size() == 0)
    {
        throw std::out_of_range("There are no current tasks");
    }
    return tasks;
}*/



