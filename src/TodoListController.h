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

        //getters
        const TodoList& getTodoList() const;

    private:
        TodoList& m_todoList;
};