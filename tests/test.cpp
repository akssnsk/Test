
#include "task.h"

#include "gtest/gtest.h"

TEST(Tasks, Fibonacchi1) 
{
  EXPECT_EQ(fibonacchi(7), 13);
  EXPECT_EQ(fibonacchi(8), 21);
  EXPECT_EQ(fibonacchi(46), 1836311903);
}

