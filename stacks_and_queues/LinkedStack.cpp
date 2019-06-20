#include <string>
#include <iostream>

class LinkedStack: public Stack 
{
	struct ListNode {
		std::string info;
		ListNode * next;
		ListNode(std::string new_info, ListNode *new_next) : 
            		info(new_info), next(new_next) { }
		static void print(std::ostream & out, ListNode *L)
		{
			if (L)
			{
				out << L->info << std::endl;
				print(out, L->next);
			}
		}
	};
	ListNode * head;
public:
    LinkedStack();
	void push(std::string toAdd);
    std::string pop();
    std::string top();
    bool isEmpty();
    bool isFull();
	~LinkedStack();
};

LinkedStack::LinkedStack(){//O(1)
	head = new ListNode("\0", nullptr);
}
LinkedStack::~LinkedStack(){//O(n)
    ListNode* temp;
    while(head!=nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
void LinkedStack::push(std::string toAdd){//O(1)
    if(isEmpty()){
        head->info = toAdd;
        return;
    }
    ListNode* temp = head;
    head = new ListNode(toAdd, temp);
}
std::string LinkedStack::pop(){//O(1)
    if(isEmpty())
        throw ContainerUnderflow();
    std::string answer = head->info;
    ListNode* temp = head;
    head = head->next;
    delete temp;
    if(head == nullptr)
        head = new ListNode("\0", nullptr);
    return answer;
}
std::string LinkedStack::top(){//O(1)
    if(isEmpty())
        throw ContainerUnderflow();
    return head->info;
}
bool LinkedStack::isEmpty(){//O(1)
    if(head->info == "\0" && head->next == nullptr)
        return true;
    return false;
}
bool LinkedStack::isFull(){//O(1)
    return true;
}
