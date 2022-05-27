#include "Queue.h"

template<class T>
Queue<T>::Queue() : m_data(new T[SIZE]), m_tail(-1), m_size(0), m_maxSize(SIZE)
{};

template<class T>
Queue<T>::Queue(const Queue<T> &q): m_data(new T[q.m_size]), m_tail(q.m_tail),
                                    m_size(q.m_size), m_maxSize(q.m_maxSize)
{
    try {
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = q.m_data[i];
        }
    }
    catch (...)
    {
        delete[] m_data;
        throw;
    }
}

template<class T>
Queue<T>::~Queue() {
    delete[] m_data;
}

template<class T>
Queue<T> &Queue<T>::operator=(const Queue<T>& q) {
    if(this == &q)
        return *this;

    T* tempData = new T[q.m_size];
    try{
        m_maxSize = q.m_maxSize;
        m_size = q.m_size;
        m_tail = q.m_tail;
        for (int i = 0; i < m_size; ++i) {
            m_data = q.m_data;
        }
    }
    catch (...)
    {
        delete[] tempData;
        throw ;
    }
    delete[] m_data;
    m_data = tempData;
    return *this;
}

template<class T>
void Queue<T>::reSize(int size,int newSize) {
    T* temp = new T[newSize];
    try {
        for (int i = 0; i < size; ++i) {
            temp[i] = m_data[i];
        }
    }
    catch (...)
    {
        delete[] temp;
        throw OutOfMemory();
    }
    delete[] m_data;
    m_data = temp;
    m_maxSize = newSize;
}

template<class T>
void Queue<T>::pushBack(const T &t) {
    if(m_size == 0)
    {
        m_data[++m_tail] = t;
        ++m_size;
        return;
    }
    m_size++;
    if(m_size >= m_maxSize) {
        try {
            this->reSize(m_maxSize, m_maxSize + SIZE);
        }
        catch (...) {
            throw;
        }
    }
    m_data[++m_tail] = t;
}

template<class T>
T& Queue<T>::front() {
    if(m_size == 0)
        throw Empty();
   return m_data[0];
}

template<class T>
const T &Queue<T>::front() const {
    if(m_size == 0)
        throw Empty();
    return m_data[0];
}

template<class T>
void Queue<T>::popFront() {
    if(m_size == 0)
        throw Empty();
    for (int i = 0; i < m_size-1; ++i) {
        m_data[i] = m_data[i+1];
    }
    --m_tail;
}

template<class T>
int Queue<T>::size() {
    return m_size;
}

template<class T>
Queue<T> filter(Queue<T> q, bool (*filterFunction)(T)) {
    Queue<T> tempQueue;
    for (int i = 0; i < q.size(); ++i) {
        if(filterFunction(q.m_data[i]))
            tempQueue.pushBack(q.m_data[i]);
    }
    return tempQueue;
}