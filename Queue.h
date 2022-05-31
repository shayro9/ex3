
#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

//default c'tor initial size and resizing addition;
#define SIZE 10
#include "new"

using namespace std;
using std::bad_alloc;

//----------Interface---------------

template <class T>
class Queue
{
public:
    Queue();
    Queue(const Queue& q);
    ~Queue();
    Queue& operator=(const Queue& q);
    void pushBack(const T& t);
    T& front();
    const T& front() const;
    void popFront();
    int size() const;

    //iterators
    class Iterator;
    class ConstIterator;
    Iterator begin();
    ConstIterator begin() const;
    Iterator end();
    ConstIterator end() const;

    //exceptions
    class EmptyQueue : exception{};
    class OutOfMemory : exception{};

private:
    T* m_data;
    int m_tail;
    int m_size;
    int m_maxSize;

    //my functions
    void reSize(int size, int newSize);
};

//external functions
template<class S, class H>
Queue<S> filter(Queue<S> q, H filterFunction);
template<class S, class H>
void transform(Queue<S> &q, H transformFunction);

template <class T>
class Queue<T>::Iterator
{
    Queue<T>* m_queue;
    int m_index;
    Iterator(Queue* queue, int index);
    friend class Queue;

public:
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;

    T& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);

    bool operator==(const Iterator& it);
    bool operator!=(const Iterator& it);

    //exceptions
    class InvalidOperation : exception{};

};

template <class T>
class Queue<T>::ConstIterator
{
    const Queue<T>* m_queue;
    int m_index;
    ConstIterator(const Queue* queue, int index);
    friend class Queue;

public:
    ConstIterator(const Iterator& i);
    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const Iterator&);

    const T& operator*() const;
    ConstIterator & operator++();
    const ConstIterator operator++(T);

    bool operator==(const ConstIterator& it) const;
    bool operator!=(const ConstIterator& it) const;

    //exceptions
    class InvalidOperation : exception{};
};

//--------------Implementation-------------------

template<class T>
Queue<T>::Queue() :
        m_data(new T[SIZE]),
        m_tail(-1),
        m_size(0),
        m_maxSize(SIZE)
{}

template<class T>
Queue<T>::Queue(const Queue<T> &q):
        m_data(new T[q.m_size]),
        m_tail(q.m_tail),
        m_size(q.m_size),
        m_maxSize(q.m_maxSize)
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
Queue<T>& Queue<T>::operator=(const Queue<T>& q) {
    if(this == &q)
        return *this;

    T* tempData = new T[q.m_size];
    try{
        m_maxSize = q.m_maxSize;
        m_size = q.m_size;
        m_tail = q.m_tail;
        for (int i = 0; i < m_size; ++i) {
            tempData[i] = q.m_data[i];
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
        throw EmptyQueue();
    return m_data[0];
}

template<class T>
const T &Queue<T>::front() const {
    if(m_size == 0)
        throw EmptyQueue();
    return m_data[0];
}

template<class T>
void Queue<T>::popFront() {
    if(m_size == 0)
        throw EmptyQueue();
    --m_size;
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = m_data[i+1];
    }
    --m_tail;
}

template<class T>
int Queue<T>::size() const{
    return m_size;
}

//----------------Iterator implementation-----------------------
template<class T>
Queue<T>::Iterator::Iterator(Queue<T>* queue, int index) :
        m_queue(queue),
        m_index(index)
{}

template<class T>
T& Queue<T>::Iterator::operator*() const {
    if(m_index >= m_queue->m_size || m_index < 0)
        throw InvalidOperation();
    return m_queue->m_data[m_index];
}

template<class T>
typename Queue<T>::Iterator & Queue<T>::Iterator::operator++() {
    if(*this == this->m_queue->end())
        throw InvalidOperation();
    ++m_index;
    return *this;
}

template<class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int) {
    if(*this == this->m_queue->end())
        throw InvalidOperation();
    Iterator result = *this;
    ++*this;
    return result;
}

template<class T>
bool Queue<T>::Iterator::operator==(const Iterator &it) {
    if(m_queue != it.m_queue)
        throw InvalidOperation();
    return m_index == it.m_index;
}

template<class T>
bool Queue<T>::Iterator::operator!=(const Iterator &it) {
    if(m_queue != it.m_queue)
        throw InvalidOperation();
    return !(*this == it);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::begin() {
    return Iterator(this,0);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end() {
    return Iterator(this,m_size);
}
//end of iterator

//------ConstIterator-------
template<class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T>* queue, int index) :
        m_queue(queue),
        m_index(index)
{}

template<class T>
Queue<T>::ConstIterator::ConstIterator(const Iterator &i) :
    m_queue(i.m_queue),
    m_index(i.m_index)
{}

template<class T>
const T& Queue<T>::ConstIterator::operator*() const {
    if(m_index >= m_queue->m_size || m_index < 0)
        throw InvalidOperation();
    return m_queue->m_data[m_index];
}

template<class T>
typename Queue<T>::ConstIterator & Queue<T>::ConstIterator::operator++() {
    if(*this == this->m_queue->end())
        throw InvalidOperation();
    ++m_index;
    return *this;
}

template<class T>
const typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(T) {
    if(*this == this->m_queue->end())
        throw InvalidOperation();
    ConstIterator result = *this;
    ++*this;
    return result;
}

template<class T>
bool Queue<T>::ConstIterator::operator==(const ConstIterator &it) const {
    if(m_queue != it.m_queue)
        throw InvalidOperation();
    return m_index == it.m_index;
}

template<class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator &it) const {
    if(m_queue != it.m_queue)
        throw InvalidOperation();
    return !(*this == it);
}

template<class T>
typename Queue<T>::ConstIterator &Queue<T>::ConstIterator::operator=(const Iterator & i) {
    if(this == i)
        return *this;

    m_queue = i.m_queue;
    m_index = i.m_index;
    return *this;
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const{
    return ConstIterator(this,0);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const{
    return ConstIterator(this,m_size);
}

template<class S, class H>
Queue<S> filter(Queue<S> q, H filterFunction) {
    Queue<S> tempQueue;
    for (auto iterator = q.begin(); iterator != q.end(); ++iterator) {
        if(filterFunction(*iterator)) {
            try {
                tempQueue.pushBack(*iterator);
            }
            catch (...)
            {
                throw;
            }
        }
    }
    return tempQueue;
}

template<class S, class H>
void transform(Queue<S> &q, H transformFunction) {
    for (auto iterator = q.begin(); iterator != q.end(); ++iterator) {
        transformFunction(*iterator);
    }
}

#endif //EX3_QUEUE_H
