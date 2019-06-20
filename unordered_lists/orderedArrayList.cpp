#include <string>
#include <iostream>
#include "orderedList.cpp"
class OrderedArrayList: public OrderedList
{
	std::string * buf;
	int capacity;
	int size;
public:
	OrderedArrayList(int max_len);
	void insert(std::string word);
	bool find(std::string word);
	void remove(std::string word);
	void print(std::ostream & out);
    bool isEmpty();
    bool isFull();
	~OrderedArrayList();
};

OrderedArrayList::OrderedArrayList(int max_len){//O(1)
    capacity = max_len;
    size = 0;
    buf = new std::string[capacity];
}

OrderedArrayList::~OrderedArrayList(){//O(1)
    delete[] buf;
}
bool OrderedArrayList::isEmpty(){//O(1)
    return size == 0;
}
bool OrderedArrayList::isFull(){//O(1)
    return size == capacity;
}
void OrderedArrayList::insert(std::string word){//O(n)
    if(isFull())
        return;
    if(isEmpty()){
       buf[0] = word;
       size++;
       return;
    }
    int min = 0;
    int max = size-1;
    int mid;
    while(min<=max){
        mid = min + (max-min)/2;
        if(word < buf[mid])
            max = mid -1;
        else if(word > buf[mid])
            min = mid +1;
        else
            break;
    } 
    if(buf[mid] <  word)
        mid++;
    for (int i = size; i>mid; --i)
        buf[i] = buf[i-1];
    size++;
    buf[mid] = word;    
}
bool OrderedArrayList::find(std::string word){//O(log2(n))
    int min = 0;
    int max = size-1;
    int mid;
    while(min<=max){
        mid = min + (max-min)/2;
        if(word < buf[mid])
            max = mid -1;
        else if(word > buf[mid])
            min = mid +1;
        else
            break;
    }
    if(word == buf[mid])
        return true;
    return false;
}
void OrderedArrayList::remove(std::string word){//O(n)
    int min = 0;
    int max = size-1;
    int mid;
    while(min<=max){
        mid = min + (max-min)/2;
        if(word < buf[mid])
            max = mid -1;
        else if(word > buf[mid])
            min = mid +1;
        else
            break;
    }
    if(word == buf[mid]){
        if(size == 1){
        buf[0] = "\0";
        size--;
        }
        for(int i = mid; i<size; i ++)
            buf[i]  = buf[i+1];
    
        size --;
    }
}
void OrderedArrayList::print(std::ostream& out){//O(n)
    for(int i = 0; i<size; i++){
        out<<buf[i]<<std::endl;
    }
}

