//assert_EQ ensures failure/protects against undefined behavior

#include <gtest/gtest.h>

#include <stdexcept>
#include <string>
#include <vector>

#include "TodoList.h"
#include "Task.h"

//constructor test
TEST(TodoListTests, StartsEmpty)
{
    TodoList list;

    EXPECT_EQ(list.getTaskCount(), std::size_t{0});
    EXPECT_TRUE(list.getTaskList().empty());
}

TEST(TodoListTests, EmptyTitleThrowsException)
{
    TodoList list;

    EXPECT_THROW(list.addTask(""), std::invalid_argument);

    EXPECT_EQ(list.getTaskCount(), std::size_t{0});
}

//GetTaskAtIndex() tests
TEST(TodoListTests, GetTaskAtIndexReturnsCorrectTask)
{
    TodoList list;

    list.addTask("first task");
    list.addTask("second task");
    list.addTask("third task");

    EXPECT_EQ(list.getTaskAtIndex(1).getTitle(), "second task");
}

TEST(TodoListTests, GetTaskAtIndexThrowsForInvalidIndex)
{
    TodoList list;
    list.addTask("pet that dog");

    EXPECT_THROW(list.getTaskAtIndex(1), std::out_of_range);
}

TEST(TodoListTests, GetTaskAtIndexThrowsWhenListIsEmpty)
{
    TodoList list;

    EXPECT_THROW(list.getTaskAtIndex(0), std::out_of_range);
}

TEST(TodoListTests, GetTaskAtIndexReturnsCorrectTaskState)
{
    TodoList list;

    list.addTask("pet that dog");
    list.addTask("exercise");

    list.finishTask(1);

    EXPECT_FALSE(list.getTaskAtIndex(0).isFinished());
    EXPECT_TRUE(list.getTaskAtIndex(1).isFinished());
}

//AddTask() tests
TEST(TodoListTests, AddTaskIncreasesCount) //also tests that a task is actually added
{
    TodoList list;

    list.addTask("pet that dog");

    EXPECT_EQ(list.getTaskCount(), std::size_t{1});
}

TEST(TodoListTests, AddTaskAddsCorrectTitle)
{
    TodoList list;

    list.addTask("pet that dog");

    const Task& testedtask = list.getTaskAtIndex(0);

    EXPECT_EQ(testedtask.getTitle(), "pet that dog");
}

TEST(TodoListTests, AddMultipleTasksInCorrectOrder)
{
    TodoList list;

    list.addTask("pet that dog");
    list.addTask("do laundry");
    list.addTask("exercise");

    ASSERT_EQ(list.getTaskCount(), std::size_t{3});

    EXPECT_EQ(list.getTaskAtIndex(0).getTitle(), "pet that dog");
    EXPECT_EQ(list.getTaskAtIndex(1).getTitle(), "do laundry");
    EXPECT_EQ(list.getTaskAtIndex(2).getTitle(), "exercise");
}

//finishTask() tests
TEST(TodoListTests, FinishTaskMarksTaskFinished)
{
    TodoList list;

    list.addTask("pet that dog");
    list.finishTask(0);

    EXPECT_TRUE(list.getTaskAtIndex(0).isFinished());
}

TEST(TodoListTests, FinishTaskInEmptyListThrowsRangeException)
{
    TodoList list;
    EXPECT_THROW(list.finishTask(0), std::out_of_range);
}

TEST(TodoListTests, FinishHigherTaskNumberThanExistsThrowsRangeException)
{
    TodoList list;
    list.addTask("pet that dog");
    list.addTask("exercise");
    list.addTask("read");

    EXPECT_THROW(list.finishTask(3), std::out_of_range);
}


//toggle finish tests
TEST(TodoListTests, ToggleFinishedChangesTaskState)
{
    TodoList list;

    list.addTask("pet that dog");
    list.toggleFinishedStatus(0);

    EXPECT_TRUE(list.getTaskAtIndex(0).isFinished());
}

//deletTask() tests
TEST(TodoListTests, DeleteTaskDecreasesCount)
{
    TodoList list;

    list.addTask("pet that dog");
    list.addTask("Exercise");

    list.deleteTask(0);

    EXPECT_EQ(list.getTaskCount(), std::size_t{0});
}

TEST(TodoListTests, DeleteTaskRemovesCorrectTask)
{
    TodoList list;
    list.addTask("pet that dog");
    list.addTask("exercise");
    list.addTask("read");

    list.deleteTask(1);

    ASSERT_EQ(list.getTaskCount(), std::size_t{2});
    EXPECT_EQ(list.getTaskAtIndex(0).getTitle(), "pet that dog");
    EXPECT_EQ(list.getTaskAtIndex(1).getTitle(), "read");
}

TEST(TodoListTests, DeleteFinalTaskResultsInEmptyList)
{
    TodoList list;
    list.addTask("pet that dog");

    list.deleteTask(0);

    EXPECT_TRUE(list.getTaskList().empty());
    EXPECT_EQ(list.getTaskCount(), std::size_t{0});
}

TEST(TodoListTests, InvalidDeleteIndexThrowsRangeException)
{
    TodoList list;
    list.addTask("pet that dog");

    EXPECT_THROW(list.deleteTask(1), std::out_of_range);

    EXPECT_EQ(list.getTaskCount(), std::size_t{1});
}

TEST(TodoListTests, DeleteFromEmptyListThrowsOutOfRangeException)
{
    TodoList list;
    EXPECT_THROW(list.deleteTask(0), std::out_of_range);
}