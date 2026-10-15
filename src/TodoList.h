//class to hold a list of task objects

#pragma once

#include <vector>
#include <cstddef>
#include <string>

#include "Task.h"

class TodoList
{
    private:
        std::vector<Task> m_tasklist;

    public:
        void addTask(const std::string& title);
        void toggleFinishedStatus(std::size_t index);
        void finishTask(std::size_t index);
        void deleteTask(std::size_t index);

        //getters
        const std::vector<Task>& getTaskList() const;
        const Task& getTaskAtIndex(std::size_t index) const;
        const std::size_t getTaskCount() const;
};