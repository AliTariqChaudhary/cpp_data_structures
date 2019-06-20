#include <string>
#include <iostream>


class OrderedLinkedList: public OrderedList 
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
	OrderedLinkedList();
	void insert(std::string word);
	bool find(std::string word);
	void remove(std::string word);
	void print(std::ostream & out);
	bool isOne();
	bool isFull();
	~OrderedLinkedList();
};

OrderedLinkedList::OrderedLinkedList(){//O(1)
	head = new ListNode("\0", nullptr);
}
OrderedLinkedList::~OrderedLinkedList(){//O(n)
	if(head-> next == nullptr){
		delete head;
		return;
	}
	ListNode* p;	
	for(p=head; p->next!= nullptr;remove(p->info)){
	}
	remove(p->info);
	delete head;
};
bool OrderedLinkedList::isFull(){//O(1)
	return false;
}
bool OrderedLinkedList::isOne(){//O(1)
	return head->next == nullptr;
}

bool OrderedLinkedList::find(std::string word){//O(n)
	for(ListNode* p = head; p != nullptr; p = p->next){
		if(p->info==word){
			return true;
		}
	}
	return false;
}
void OrderedLinkedList::insert(std::string word){//O(n)
	if(head->info == "\0" && head->next == nullptr){
		head->info = word;
		return;
	}
    if(head->next == nullptr){
         if(word>=head->info){
            head->next = new ListNode(word, nullptr);
            return;
         }
         else{
             ListNode* tempt = head;
             head = new ListNode(word, tempt);
             return;
         }
    }
    std::string temps = "\0";
    ListNode* pp;
    ListNode* p;
    for(p = head; p != nullptr; p = p->next){
        if(p->info==word){
			break;
		}
        if(temps == "\0")
            temps = p->info;
        else{
            if(word>=temps && word <= p->info)
                break;
            else
                temps = p->info;
        }
        pp = p;
    }
    pp-> next = new ListNode(word, p);
}
void OrderedLinkedList::remove(std::string word){//O(n)
	if(!find(word))
		return;
	if(head->info == word){
		if(!isOne()){
			head->info = head->next->info;
			ListNode* temp = head->next;
			head->next = head->next->next;
			delete temp;
			return;
		}
		head->info = "";
		return;
	}
	ListNode* p = head;
	for(p; p->next!= nullptr && p->next->info != word; p = p->next){
	}
	if(p->next != nullptr){
		ListNode* temp2 =  p->next;
		p->next = p->next->next;
		delete temp2;
	}	
}

void OrderedLinkedList::print(std::ostream & out){//O(n)
	ListNode::print(out,head);

}
