#pragma once

#include "TodoListController.h"

class TodoListUI
{
    public:
        TodoListUI(TodoListController& controller);
        void run();

    private:
        TodoListController m_controller;

        //display methods
        void printTodoList() const;
        void printOptionsMenu() const;

        //interact with user
        int getMenuChoice() const;
        std::string getUserInput(const std::string& prompt) const;
        int getIntegerInputInRange(const std::string& prompt, int min, int max) const; //calls getUserInput(), convertToInteger() and isInRange() to prompt the user for valid input 

        //delegate to controller
        void addTask();
        void finishTask();
        void toggleFinishedStatus();

        //helpers
        int convertToInteger(const std::string& input) const;
        bool isInRange(const int input, int min, int max) const;

};

