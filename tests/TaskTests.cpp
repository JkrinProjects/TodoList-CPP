//https://google.github.io/googletest/primer.html

#include <gtest/gtest.h>

#include <stdexcept>
#include <string>

#include "Task.h"

//task creation tests
TEST(TaskTests, StoresTitle) //also tests 
{
    Task task("pet that dog");

    EXPECT_EQ(task.getTitle(), "pet that dog");
}

TEST(TaskTests, SpacesOnlyTitleThrowsException)
{
    EXPECT_THROW(Task("   "), std::invalid_argument);
}

TEST(TaskTests, NewlineOnlyTitleThrowsException)
{
    EXPECT_THROW(Task("\n"), std::invalid_argument);
}

TEST(TaskTests, TitleWithLeadingAndTrailingWhitespaceIsAccepted)
{
    Task task("  pet that dog  ");
    
    EXPECT_EQ(task.getTitle(), "  pet that dog  ");
}

TEST(TaskTests, MultipleWhitespaceOnlyTitleThrowsException)
{
    EXPECT_THROW(Task(" \t\t\t\n "), std::invalid_argument);
}

TEST(TaskTests, StartsUnfinished)
{
    Task task("pet that dog");

    EXPECT_FALSE(task.isFinished());
}

//changing state tests
TEST(TaskTests, MarkFinishedSetsFinishedState)
{
    Task task("pet that dog");

    task.markFinished();

    EXPECT_TRUE(task.isFinished());
}

TEST(TaskTests, ToggleFinishedChangesState)
{
    Task task("pet that dog");

    task.toggleFinished();

    EXPECT_TRUE(task.isFinished());
}

TEST(TaskTests, TogglingTwiceCyclesToStartingState)
{
    Task task("pet that dog");

    task.toggleFinished();
    task.toggleFinished();

    EXPECT_FALSE(task.isFinished());
}

TEST(TaskTests, EmptyTitleThrowsException)
{
    EXPECT_THROW(
        Task(""),
        std::invalid_argument
    );
}
