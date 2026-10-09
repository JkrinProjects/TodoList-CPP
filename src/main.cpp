#include "Todolist.h"
#include "TodoListManager.h"

//use console as UI for now

int main()
{
    TodoList todoList;
    TodoListManager listManager;

    listManager.run(todoList);
    return 0;
    
}

//future changes: define an enum class for switch cases