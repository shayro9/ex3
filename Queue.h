
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


    //external functions
    template<class S>
    friend Queue<S> filter(Queue<S> q, bool (*filterFunction)(S));
    template<class S>
    void transform(Queue<S>, void (*transformFunction)(S));

    //exceptions
    class InvalidSize{};
    class OutOfMemory{};
    class Empty{};

    //my functions
    void reSize(int size, int newSize);

private:
    T* m_data;
    int m_tail;
    int m_size;
    int m_maxSize;
};

#endif //EX3_QUEUE_H
