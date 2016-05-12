#ifndef STACKQUEUE_H
#define STACKQUEUE_H

#include <deque>

#include "GenericQueue.h"
#include "GenericStack.h"

namespace Week10
{
    template <class T>
    class StackQueue : public Queue<T>, public Stack<T>
    {
    public:
        bool empty() const
        {
            return m_elements.empty();
        }

        size_t size() const
        {
            return m_elements.size();
        }

        const T& front() const
        {
            return m_elements.front();
        }

        void enqueue(const T &item)
        {
            m_elements.push_back(item);
        }

        T deqeue()
        {
            T element;

            if (!m_elements.empty())
            {
                element = m_elements.front();
                m_elements.pop_front();
            }

            return element;
        }

        Queue<T>& operator =(const Queue<T> &queue)
        {
            m_elements.clear();

            Queue<T>* mutableQueue = const_cast<Queue<T>*>(&queue);

            int size = queue.size();
            for (int i = 0; i < size; ++i)
            {
                m_elements.push_back(mutableQueue->deqeue());
            }

            for (auto iter = m_elements.rbegin(); iter != m_elements.rend(); ++iter)
            {
                mutableQueue->enqueue(*iter);
            }

            Queue<T>* currentQueue = static_cast<Queue<T>*>(this);

            return *currentQueue;
        }

        const T& peek() const
        {
            return m_elements.front();
        }

        void push(const T &item)
        {
            m_elements.push_front(item);
        }

        T pop()
        {
            T element;

            if (!m_elements.empty())
            {
                element = m_elements.front();
                m_elements.pop_front();
            }

            return element;
        }

        Stack<T>& operator =(const Stack<T> &stack)
        {
            m_elements.clear();

            Stack<T>* mutableStack = const_cast<Stack<T>*>(&stack);

            int size = stack.size();
            for (int i = 0; i < size; ++i)
            {
                m_elements.push_back(mutableStack->pop());
            }

            for (auto iter = m_elements.rbegin(); iter != m_elements.rend(); ++iter)
            {
                mutableStack->push(*iter);
            }

            Stack<T>* currentStack = static_cast<Stack<T>*>(this);

            return *currentStack;
        }

    private:
        std::deque<T> m_elements;
    };
}

#endif // STACKQUEUE_H
