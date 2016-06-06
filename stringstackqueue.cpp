#include "stringstackqueue.h"

#include <iostream>

bool StringStackQueue::empty() const
{
    return m_strings.empty();
}

size_t StringStackQueue::size() const
{
    return m_strings.size();
}

const std::string &StringStackQueue::peek() const
{
    return m_strings.front();
}

void StringStackQueue::push(const std::string &string)
{
    m_strings.push_front(string);
}

std::string StringStackQueue::pop()
{
    std::string element;

    if (!m_strings.empty())
    {
        element = m_strings.front();
        m_strings.pop_front();
    }

    return element;
}

StringStack &StringStackQueue::operator =(const StringStack &stack)
{
    m_strings.clear();

    StringStack* mutableStack = const_cast<StringStack*>(&stack);

    int size = stack.size();
    for (int i = 0; i < size; ++i)
    {
        m_strings.push_back(mutableStack->pop());
    }

    for (auto iter = m_strings.rbegin(); iter != m_strings.rend(); ++iter)
    {
        mutableStack->push(*iter);
    }

    return *this;
}

const std::string &StringStackQueue::front() const
{
    return m_strings.front();
}

void StringStackQueue::enqueue(const std::string &string)
{
    m_strings.push_back(string);
}

std::string StringStackQueue::deqeue()
{
    return pop();
}

StringQueue &StringStackQueue::operator =(const StringQueue &queue)
{
    m_strings.clear();

    StringQueue* mutableQueue = const_cast<StringQueue*>(&queue);

    int size = queue.size();
    for (int i = 0; i < size; ++i)
    {
        m_strings.push_back(mutableQueue->deqeue());
    }

    for (auto iter = m_strings.rbegin(); iter != m_strings.rend(); ++iter)
    {
        mutableQueue->enqueue(*iter);
    }

    return *this;
}
