
#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

//default c'tor initial size;
#define SIZE 10

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
    int size();

    //iterator
    class Iterator;
    Iterator begin() const;
    Iterator end() const;


    //external functions
    template<class S>
    friend Queue<S> filter(Queue<S> q, bool (*filterFunction)(S));
    template<class S>
    friend void transform(Queue<S> q, void (*transformFunction)(S&));

    //exceptions
    class EmptyQueue{};
    class OutOfMemory{};

    //my functions
    void reSize(int size, int newSize);

private:
    T* m_data;
    int m_tail;
    int m_size;
    int m_maxSize;
};

template <class T>
class Queue<T>::Iterator
{
    const Queue<T>* m_queue;
    int m_index;
    Iterator(const Queue* queue, int index);
    friend class Queue;
public:
    const T& operator*() const;
    Iterator & operator++();
    const Iterator operator++(T);
    bool operator==(const Iterator& it) const;
    bool operator!=(const Iterator& it) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
    //exceptions
    class InvalidOperation{};

};

#endif //EX3_QUEUE_H
