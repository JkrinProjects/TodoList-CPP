//class to hold a list of task objects

#pragma once

#include <vector>
#include <cstddef>

#include "Task.h"

class TodoList
{
    private:
        std::vector<Task> m_tasklist;

    public:
        void addTask(const std::string& title);
        void finishTask(std::size_t index); //unsigned int as cant have negative index
        
        //getters
        const std::vector<Task>& getTaskList() const;
};