//Test Fixtures - https://google.github.io/googletest/primer.html
// TEST_F macro to use the fixture

#include <gtest/gtest.h>

#include "TodoList.h"
#include "Task.h"
#include "TodoListController.h"

class TodoListControllerTests : public testing::Test 
{
    protected:
        TodoList list;
        TodoListController controller{list};
};

//constructor tests
TEST_F(TodoListControllerTests, StartsWithEmptyList)
{
    EXPECT_EQ(controller.getTaskCount(), std::size_t{0});
    EXPECT_TRUE(list.getTaskList().empty());
}


//getTaskAtIndex() tests
TEST_F(TodoListControllerTests, GetTaskAtIndexReturnsCorrectTask)
{
    controller.addTask("pet that dog");
    controller.addTask("do laundry");
    controller.addTask("exercise");

    EXPECT_EQ(controller.getTaskAtIndex(1).getTitle(), "do laundry");
}

TEST_F(TodoListControllerTests, GetTaskAtIndexThrowsForInvalidIndex)
{
    controller.addTask("pet that dog");

    EXPECT_THROW(controller.getTaskAtIndex(1), std::out_of_range);
}

TEST_F(TodoListControllerTests, GetTaskAtIndexThrowsWhenListIsEmpty)
{
    EXPECT_THROW(controller.getTaskAtIndex(0), std::out_of_range);
}

TEST_F(TodoListControllerTests, GetTaskAtIndexReturnsCorrectTaskState)
{
    controller.addTask("pet that dog");
    controller.addTask("exercise");

    controller.markFinished(1);

    EXPECT_FALSE(controller.getTaskAtIndex(0).isFinished());
    EXPECT_TRUE(controller.getTaskAtIndex(1).isFinished());
}

//addTask() tests
TEST_F(TodoListControllerTests, AddTaskIncreasesCount)
{
    controller.addTask("pet that dog");

    EXPECT_EQ(controller.getTaskCount(), std::size_t{1});
}

TEST_F(TodoListControllerTests, AddTaskAddsCorrectTitle)
{
    controller.addTask("pet that dog");

    const Task& testedtask = controller.getTaskAtIndex(0);

    EXPECT_EQ(testedtask.getTitle(), "pet that dog");
}

TEST_F(TodoListControllerTests, AddMultipleTasksInCorrectOrder)
{
    controller.addTask("pet that dog");
    controller.addTask("do laundry");
    controller.addTask("exercise");

    ASSERT_EQ(controller.getTaskCount(), std::size_t{3});

    EXPECT_EQ(controller.getTaskAtIndex(0).getTitle(), "pet that dog");
    EXPECT_EQ(controller.getTaskAtIndex(1).getTitle(), "do laundry");
    EXPECT_EQ(controller.getTaskAtIndex(2).getTitle(), "exercise");
}

TEST_F(TodoListControllerTests, AddTaskWithEmptyTitleThrowsException)
{
    EXPECT_THROW(controller.addTask(""), std::invalid_argument);

    EXPECT_EQ(controller.getTaskCount(), std::size_t{0});
}

//markFinished() tests
TEST_F(TodoListControllerTests, MarkFinishedMarksTaskFinished)
{
    controller.addTask("pet that dog");

    controller.markFinished(0);

    EXPECT_TRUE(controller.getTaskAtIndex(0).isFinished());
}

TEST_F(TodoListControllerTests, MarkFinishedInEmptyListThrowsRangeException)
{
    EXPECT_THROW(controller.markFinished(0), std::out_of_range);
}

TEST_F(TodoListControllerTests, MarkHigherTaskNumberThanExistsThrowsRangeException)
{
    controller.addTask("pet that dog");
    controller.addTask("exercise");
    controller.addTask("read");

    EXPECT_THROW(controller.markFinished(3), std::out_of_range);
}

//toggleFinishedStatus() tests
TEST_F(TodoListControllerTests, ToggleFinishedChangesTaskState)
{
    controller.addTask("pet that dog");

    controller.toggleFinishedStatus(0);

    EXPECT_TRUE(controller.getTaskAtIndex(0).isFinished());
}

TEST_F(TodoListControllerTests, ToggleFinishedTwiceChangesTaskBackToUnfinished)
{
    controller.addTask("pet that dog");

    controller.toggleFinishedStatus(0);
    controller.toggleFinishedStatus(0);

    EXPECT_FALSE(controller.getTaskAtIndex(0).isFinished());
}

TEST_F(TodoListControllerTests, ToggleFinishedInEmptyListThrowsRangeException)
{
    EXPECT_THROW(controller.toggleFinishedStatus(0), std::out_of_range);
}

TEST_F(TodoListControllerTests, ToggleHigherTaskNumberThanExistsThrowsRangeException)
{
    controller.addTask("pet that dog");

    EXPECT_THROW(controller.toggleFinishedStatus(1), std::out_of_range);
}

//deleteTask() tests
TEST_F(TodoListControllerTests, DeleteTaskDecreasesCount)
{
    controller.addTask("pet that dog");
    controller.addTask("exercise");

    controller.deleteTask(0);

    EXPECT_EQ(controller.getTaskCount(), std::size_t{1});
}

TEST_F(TodoListControllerTests, DeleteTaskRemovesCorrectTask)
{
    controller.addTask("pet that dog");
    controller.addTask("exercise");
    controller.addTask("read");

    controller.deleteTask(1);

    ASSERT_EQ(controller.getTaskCount(), std::size_t{2});

    EXPECT_EQ(controller.getTaskAtIndex(0).getTitle(), "pet that dog");
    EXPECT_EQ(controller.getTaskAtIndex(1).getTitle(), "read");
}

TEST_F(TodoListControllerTests, DeleteFinalTaskResultsInEmptyList)
{
    controller.addTask("pet that dog");

    controller.deleteTask(0);

    EXPECT_TRUE(list.getTaskList().empty());
    EXPECT_EQ(controller.getTaskCount(), std::size_t{0});
}

TEST_F(TodoListControllerTests, InvalidDeleteIndexThrowsRangeException)
{
    controller.addTask("pet that dog");

    EXPECT_THROW(controller.deleteTask(1), std::out_of_range);

    EXPECT_EQ(controller.getTaskCount(), std::size_t{1});
}

TEST_F(TodoListControllerTests, DeleteFromEmptyListThrowsOutOfRangeException)
{
    EXPECT_THROW(controller.deleteTask(0), std::out_of_range);
}