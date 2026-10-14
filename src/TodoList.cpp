#include "TodoList.h"

#include <stdexcept>


void TodoList::addTask(const std::string& title)
{
    m_tasklist.emplace_back(title);
}

void TodoList::toggleFinishedStatus(std::size_t index)
{
    if(index >= m_tasklist.size())
    {
        throw std::out_of_range("Task index is out of range");
    }
    m_tasklist[index].toggleFinished();
}
void TodoList::finishTask(std::size_t index)
{
    if(index >= m_tasklist.size())
    {
        throw std::out_of_range("Task index is out of range");
    }
    m_tasklist[index].markFinished();

}

void TodoList::deleteTask(std::size_t index)
{
    if(index >= m_tasklist.size())
    {
        throw std::out_of_range("Task index is out of range");
    }
    m_tasklist.erase(m_tasklist.begin() + index);
}


//getters
const std::vector<Task>& TodoList::getTaskList() const
{
    return m_tasklist;
}
const Task& TodoList::getTaskAtIndex(std::size_t index) const
{
    return m_tasklist.at(index);
}
const std::size_t TodoList::getTaskCount() const
{
    return m_tasklist.size();
}