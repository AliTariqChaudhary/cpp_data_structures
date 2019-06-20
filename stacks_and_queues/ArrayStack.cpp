#include <string>
#include <iostream>
#include "Stack.cpp"

class ContainerOverflow{
     std::string reason = "Stack full.";
};
class ContainerUnderflow{
     std::string reason = "Stack empty.";
};

class ArrayStack: public Stack
{
    std::string * buf;
    int capacity;
    int size;
public:
    ArrayStack(int max_len);
    void push(std::string toAdd);
    std::string pop();
    std::string top();
    bool isEmpty();
    bool isFull();
    ~ArrayStack();
};

ArrayStack::ArrayStack(int max_len){//O(1)
    capacity = max_len;
    size = 0;
    buf = new std::string[capacity];
}
ArrayStack::~ArrayStack(){//O(1)
    delete[] buf;
}
void ArrayStack::push(std::string toAdd){//O(1)
    if(isFull())
         throw ContainerOverflow();
    buf[size] = toAdd;
    size++;
}
std::string ArrayStack::pop(){//O(1)
    if(isEmpty())
        throw ContainerUnderflow();
    size--;
    return buf[size];
}
std::string ArrayStack::top(){//O(1)
    if(isEmpty())
	throw ContainerUnderflow();
    return buf[size-1];
}
bool ArrayStack::isEmpty(){//O(1)
    return size ==0;
}
bool ArrayStack::isFull(){//O(1)
    return size == capacity;
}
