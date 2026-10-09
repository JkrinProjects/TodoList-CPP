#include "Task.h"

//constructor
Task::Task(const std::string& title):
    m_title(title),
    m_finished(false)
{ 
}

void Task::toggleFinished()
{
    m_finished = !m_finished;
}
void Task::markFinished()
{
    m_finished = true;
}

const std::string& Task::getTitle() const
{
    return m_title;
}
bool Task::isFinished() const
{
    return m_finished;
}

