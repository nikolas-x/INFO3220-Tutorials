#ifndef STRINGSTACKQUEUE_H
#define STRINGSTACKQUEUE_H

#include <deque>

#include "stringqueue.h"
#include "stringstack.h"

class StringStackQueue : public StringQueue, public StringStack
{
public:
    StringStackQueue() {}
    ~StringStackQueue() {}

    bool empty() const;
    size_t size() const;

    // StringStack interface
    const std::string &peek() const;
    void push(const std::string &string);
    std::string pop();
    StringStack &operator =(const StringStack &stack);

    // StringQueue interface
    const std::string &front() const;
    void enqueue(const std::string &string);
    std::string deqeue();
    StringQueue &operator =(const StringQueue &queue);

private:
    std::deque<std::string> m_strings;
};

#endif // STRINGSTACKQUEUE_H
