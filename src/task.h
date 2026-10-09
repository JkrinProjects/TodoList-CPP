//class to represent an individual task

#pragma once

#include <string>

class Task
{
    private:
        std::string m_title;
        bool m_finished;


    public:
        Task(const std::string& title);
        
        //setters
        void markFinished();
        void toggleFinished();

        //getters
        const std::string& getTitle() const;
        bool isFinished() const;
        
};


