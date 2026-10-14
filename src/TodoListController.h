#pragma once

#include "TodoList.h"

class TodoListController
{
    public:
        //controller contstructor
        TodoListController(TodoList& todolist);
        
        //list methods
        void addTask(const std::string& title) const;
        void toggleFinishedStatus(std::size_t index) const;
        void markFinished(std::size_t index) const;
        void deleteTask(std::size_t index) const;

        //getters
        std::size_t getTaskCount() const;
        const Task& getTask(std::size_t index) const;
        
        
        //const TodoList& getTodoList() const;

    private:
        TodoList& m_todoList;
};