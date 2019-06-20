#include <string>
class Stack{
	public:
	virtual void push(std::string word){std::string temp = word;};
	virtual std::string pop(){return "";};
	virtual std::string top(){return "";};
    virtual bool isEmpty(){return true;}
};
