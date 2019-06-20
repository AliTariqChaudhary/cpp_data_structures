#include <string>
#include <iostream>
#include "Queue.cpp"
#include "ArrayStack.cpp"

class ArrayQueue: public Queue{
    std::string * buf;
    int capacity;
    int frontL;
    int size;
    int rear;
public:
    ArrayQueue(int max_len);
    void enq(std::string toAdd);
    std::string deq();
    std::string front();
    bool isEmpty();
    bool isFull();
    void changeFrontRear();
    ~ArrayQueue();
};

ArrayQueue::ArrayQueue(int max_len){//O(1)
    capacity = max_len;
    frontL = 0;
    rear = 0;
    size = 0;
    buf = new std::string[capacity];
}
ArrayQueue::~ArrayQueue(){//O(1)
    delete[] buf;
}
void ArrayQueue::enq(std::string toAdd){//O(1)
    if(isFull())
        throw ContainerOverflow();
    buf[rear] = toAdd;
    rear++;
    size++;
    changeFrontRear();
}
std::string ArrayQueue::deq(){//O(1)
    if(isEmpty())
        throw ContainerUnderflow();
    size--;
    frontL++;
    int temp = frontL - 1;
    changeFrontRear();
    return buf[temp];
}
std::string ArrayQueue::front(){
    if(isEmpty())
	throw ContainerUnderflow();
    return buf[frontL];
}
bool ArrayQueue::isEmpty(){//O(1)
    return size ==0;
}
bool ArrayQueue::isFull(){//O(1)
    return size == capacity;
}
void ArrayQueue::changeFrontRear(){//O(1)
    if(rear == capacity){
        rear = 0;
    }
    if(frontL == capacity){
        frontL = 0;
    }
}
