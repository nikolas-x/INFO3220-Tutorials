#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H

namespace week12
{
    template <class T>
    class SharedPointer
    {
    public:

        /**
         * @brief SharedPointer creates an new instance of an empty shared pointer
         */
        SharedPointer()
            : m_element(nullptr)
            , m_counter(nullptr)
        {

        }

        /**
         * @brief SharedPointer creates an new instance of a shared pointer storing item
         * @param item the item to store in a newly created const reference
         */
        SharedPointer(const T& item)
            : m_element(new T(item))
            , m_counter(new int(1))
        {

        }

        /**
         * @brief SharedPointer creates a new instance of a shared pointer storing the raw pointer
         * @param rawPointer the pointer to store in the newly created shared pointer
         */
        SharedPointer(T* rawPointer)
            : m_element(new T(*rawPointer))
            , m_counter(new int(1))
        {

        }

        /**
         * @brief SharedPointer creates a new instance of a shared pointer based on the construction of an existing shared pointers
         * @param sharedPointer the shared pointer for which the new shared pointer will be based on
         */
        SharedPointer(const SharedPointer &sharedPointer)
            : m_element(sharedPointer.m_element)
            , m_counter(sharedPointer.m_counter)
        {
            if (sharedPointer)
            {
                (*m_counter)++;
            }
        }

        /**
         * @brief ~SharedPointer destructor for the shared pointer
         */
        ~SharedPointer()
        {
            reset();
        }

        /**
         * @brief get retrieves the raw pointer stored in the shared pointer
         * @return the raw pointer stored in the shared pointer
         */
        T* get() const
        {
            return m_element;
        }

        /**
         * @brief reset returns the shared pointer to a state as if it had been default constructed
         */
        void reset()
        {
            if (unique())
            {
                delete m_element;
                delete m_counter;
            }
            else
            {
                if (m_counter)
                {
                    (*m_counter)--;
                }
            }

            m_element = nullptr;
            m_counter = nullptr;
        }

        /**
         * @brief unique checks if the shared pointer object does not share ownership over its pointer with other shared_ptr objects. Empty pointers are not unique (as they do not own any pointers)
         * @return true if the shared pointer is unique otherwise false
         */
        bool unique() const
        {
            return m_counter && (*m_counter) == 1;
        }

        /**
         * @brief operator = copy assignments add the object as a shared owner of other's assets and the counter is then increased by 1
         * @param sharedPointer which is assignment to this pointer
         * @return a reference to this pointer
         */
        SharedPointer& operator=(const SharedPointer &sharedPointer)
        {
            if (this == &sharedPointer)
            {
                return *this;
            }

            reset();
            m_element = sharedPointer.m_element;
            m_counter = sharedPointer.m_counter;

            if (sharedPointer)
            {
                (*m_counter)++;
            }

            return *this;
        }

        /**
         * @brief operator * recovers a reference to the shared pointer
         * @return a reference to the shared pointer
         */
        T& operator*() const
        {
            return *m_element;
        }

        /**
         * @brief operator -> recovers the pointer to the object stored in the shared pointer
         * @return the pointer to the object stored in the shared pointer
         */
        T* operator->() const
        {
            return m_element;
        }

        /**
         * @brief operator bool return true iff the pointer is not null
         */
        operator bool() const
        {
            return m_element != nullptr;
        }

    private:
        T* m_element;
        int* m_counter;
    };
}

#endif // SHAREDPOINTER_H
