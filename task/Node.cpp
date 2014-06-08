#include "Node.h"


Node::~Node()
{
}

int Node::DoWorkOnUnit(const Work::WorkActionT &action, int argument)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    size_t firstFree = 0;
    for (auto &w : m_units)
    {
        if (w == nullptr)
            break;

        firstFree++;
    }

    if (firstFree >= m_units.size())
    {
        return -1; // too much jobs
    }

    Work::WorkCallbackT cb = std::bind(&Node::WorkDoneOn, this, firstFree, std::placeholders::_2);
    m_units[firstFree] = std::make_shared<Work>(firstFree, argument, action, cb);

    return 0;
}

void Node::WorkDoneOn(size_t unitId, int res)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_units[unitId].reset();

    m_callback(res);
}
