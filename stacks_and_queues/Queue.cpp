#include <string>
class Queue{
	public:
	virtual void enq(std::string word){std::string temp = word;};
	virtual std::string deq(){return "";};
	virtual std::string front(){return "";};
    virtual bool isEmpty(){return false;}
};
