#include "Task.h"
#include "Todolist.h"
#include "TodoListController.h"
#include "TodoListUI.h"

//use console as UI for now

int main()
{
    TodoList todoList;
    TodoListController listController(todoList);
    TodoListUI ui(listController);

    ui.run();
    return 0;
    
}

