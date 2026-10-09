#pragma once

#include "Todolist.h"

class TodoListManager
{
    public:
        void run(TodoList& todoList);

    private:
        void printTodoList(const TodoList& todoList) const;
        void printOptionsMenu() const;
        int getMenuChoice() const;
        void addTask(TodoList& todoList) const;
        void finishTask(TodoList& todoList) const;
        
};

