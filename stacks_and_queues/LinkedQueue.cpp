#include <string>
#include <iostream>

class LinkedQueue: public Queue 
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
	ListNode* head;
    ListNode* tail;
public:
    LinkedQueue();
	void enq(std::string toAdd);
    std::string deq();
    std::string front();
    bool isEmpty();
    bool isFull();
	~LinkedQueue();
};

LinkedQueue::LinkedQueue(){//O(1)
	head = new ListNode("\0", nullptr);
    tail = head;
}
LinkedQueue::~LinkedQueue(){//O(n)
    ListNode* temp;
    while(head!=nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
void LinkedQueue::enq(std::string toAdd){//O(1)
    if(isEmpty())
        head->info = toAdd;
    else{
        tail->next = new ListNode(toAdd, nullptr);
        tail = tail->next;
    }
}
std::string LinkedQueue::front(){//O(1)
    if(isEmpty())
	throw ContainerUnderflow();
    return head->info;
}
std::string LinkedQueue::deq(){//O(1)
    
    if(isEmpty())
        throw ContainerUnderflow();
    if(head->next == nullptr){
       std::string temp1 = head->info;
       head->info = "\0";
       return temp1;
    }
    ListNode* temp = head;
    head = head->next;
    std::string answer = temp->info;
    delete temp;
    return answer;
}
bool LinkedQueue::isEmpty(){//O(1)
    if(head == nullptr)
         return false;
    if(head->next == nullptr && head->info == "\0")
        return true;
    return false;
}
bool LinkedQueue::isFull(){//O(1)
    return true;
}
