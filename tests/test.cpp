
#include "task.h"

#include "Node.h"

#include "gtest/gtest.h"

TEST(Work, Test1) 
{
    bool calcReady = false;
    std::mutex mut;
    std::condition_variable cv;

    std::shared_ptr<Work> w =
        std::make_shared<Work>(0, 30, fibonacchi,
        [&](size_t uid, int res)
    {
        EXPECT_EQ(res, 832040);
        calcReady = true;
        cv.notify_one();
    });

    std::unique_lock<std::mutex> lock(mut);
    while (!calcReady) cv.wait(lock);
}

TEST(Node, Test1)
{
    bool calcReady = false;
    std::condition_variable cv;

    int calls = 0;
    Node::NodeCallbackT func = Node::NodeCallbackT([&](int res) 
    {
        calls++;

        calcReady = (calls == 3);
        cv.notify_one();
    });

    int nodeId = 1;
    size_t unitNum  = 5;
    Node nn(nodeId, unitNum, func);

    nn.DoWorkOnUnit(fibonacchi, 10);
    nn.DoWorkOnUnit(fibonacchi, 5);
    nn.DoWorkOnUnit(fibonacchi, 7);

    std::mutex mut2;
    std::unique_lock<std::mutex> lock2(mut2);
    while (!calcReady) cv.wait(lock2);

    EXPECT_EQ(calls, 3);
}
