#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <math.h>
#include "timer.h"


struct Hasher {
    virtual int hash(std::string s, int N) = 0;
};

struct GeneralStringHasher: Hasher {
    int hash(std::string s, int N) {//O(1)
	const unsigned shift = 6;
    const unsigned zero = 0;
    unsigned mask = ~zero >> (32-shift);  // low 6 bits on
    unsigned result = 0;
    int len = std::min(int(s.size()), 6);
    for (int i = 0; i < len; i++)
        result = (result << shift) | (s[i] & mask);
    return result % N;
	}
};

struct SumHasher : Hasher {
	int hash(std::string s, int N) {
		int result = 0;
		for (unsigned int i=0; i<s.size(); ++i)
			result += s[i];
		return abs(result) % N;
	}
};

struct ProdHasher : Hasher {
	int hash(std::string s, int N) {
		int result = 1;
		for (unsigned int i=0; i<s.size(); ++i)
			result *= s[i];
		return abs(result) % N;
	}
};


class ChainedHashTable{
struct ListNode {
	std::string key;
    int value;
	ListNode * next;
	ListNode(std::string new_info,int new_val, ListNode *new_next) : 
           		key(new_info), value(new_val), next(new_next) { }
    ListNode() : 
           		key(""), value(0), next(nullptr) { }
	static void print(std::ostream & out, ListNode *L)
	{
		if (L)
    	{
			out << L->key<< " "<<L->value<< std::endl;
			print(out, L->next);
		}
	}
};

private:
    int size;
    Hasher& ChainedHash;
    ListNode* table;
    int* lengths;
public:
    ChainedHashTable(int capacity, Hasher & myHasher)
    :size(capacity), ChainedHash(myHasher){
        table = new ListNode[size];
        lengths = new int[size];
        for(int i= 0; i<5000; i++)
            lengths[i] = 0;
    }
    ChainedHashTable(const ChainedHashTable& other)
    :size(other.size), ChainedHash(other.ChainedHash){
        table = new ListNode[size];
        for(int i = 0; i<size; i++){
            table[i].key = other.table[i].key;
            table[i].value = other.table[i].value;
            table[i].next = other.table[i].next;
        }
    }
    int minLen(){
         return *std::min_element(lengths, lengths+size);
    }
    int maxLen(){
         return *std::max_element(lengths, lengths+size);
    }
    int avgLen(){
         int temp = 0;
         for(int i = 0; i<size; i++)
             temp++;
         return temp/size;
    }
    int stdDev(){
        int var_sum = 0;
        int temp1 = avgLen();
        for(int i = 0; i<size; i++)
            var_sum+= ((lengths[i]-temp1)* (lengths[i]-temp1));
        double var = double(var_sum)/double(size);
        double answer = sqrt(var);
        return answer;
     }
    int& operator[](std::string word){//Worst Case: O(L) Typical Case:O(1)
        int temp1 = ChainedHash.hash(word, size);
        ListNode* tempLN = &table[temp1];
        while(tempLN->next != nullptr && tempLN->key != word)
            tempLN = tempLN->next;
        if(tempLN->key == word)
            return tempLN->value;
        insert(word);
        while(tempLN->next != nullptr && tempLN->key != word)
            tempLN = tempLN->next;
        if(tempLN->key == word){
            tempLN->value--;
            return tempLN->value;
        }
        return tempLN->value;
    }    
    void insert(std::string word){//Worst Case: O(L) Typical Case:O(1)
        int temp1 = ChainedHash.hash(word, size);
        ListNode* tempLN = &table[temp1];
        while(tempLN->next != nullptr && tempLN->key != word)
            tempLN = tempLN->next;
        if(tempLN->key == word)
            tempLN->value=1;
        else if(tempLN->value == 0){
            tempLN->key = word;
            tempLN->value = 1;
            lengths[temp1]++;
        }
        else{
            tempLN->next = new ListNode(word,1,nullptr);
            lengths[temp1]++;
            }
    }
    bool find(std::string word){//Worst Case: O(N) Typical Case: O(1)
        int temp1 = ChainedHash.hash(word, size);
        ListNode* tempLN = &table[temp1];
        while(tempLN->next != nullptr && tempLN->key != word)
            tempLN = tempLN->next;
        if(tempLN->key == word)
            return true;
        return false;
    }
    void remove(std::string word){//Worst Case: O(N) Typical Case: O(1)
        int temp1 = ChainedHash.hash(word, size);
        ListNode* tempLN = &table[temp1];
        while(tempLN->next != nullptr && tempLN->key != word)
            tempLN = tempLN->next;
        if(tempLN->key == word)
        {
            if(tempLN->next == nullptr){
                if(tempLN->value == 1){
                    tempLN->value--;
                    tempLN->key = "";
                    lengths[temp1]--;
                }
                else
                    tempLN->value--;
            }
            else{
                ListNode* temp2 = tempLN->next;
                tempLN-> key = tempLN->next->key;
                tempLN-> value = tempLN->value;
                tempLN-> next = tempLN->next->next;
                delete temp2;
                lengths[temp1]--;
            }
        }
    }
    ~ChainedHashTable(){
        delete[] table;
    }
};

void testConstructor(Hasher & hasher)
{ 
    ChainedHashTable test = ChainedHashTable(5000, hasher);
}

void testCopyConstructor(Hasher & hasher)
{ 
    ChainedHashTable test = ChainedHashTable(5000, hasher);
    ChainedHashTable test2 = test;
}

void insertAll(ChainedHashTable& h, std::string file_name){//Worst Case: O(N^2) Typical Case: O(N)
    Timer t;
    double eTime;
    std::ifstream rand_file;
    rand_file.open(file_name);
    std::string line;
    t.start();
    if(rand_file.is_open())
    {
        while (getline(rand_file,line) ){
            h.insert(line);
        }
        rand_file.close();
    }
    t.elapsedUserTime(eTime);
    std::cout<<"	min = "<<h.minLen()<<"; max = "<<h.maxLen()<<"; average = "<<h.avgLen()<<"; std_dev = "<<h.stdDev()<<std::endl;
    std::cout <<"	insertAll = "<<eTime <<" sec" <<std::endl;
}

void findAll(ChainedHashTable& h, std::string file_name){//Worst Case: O(N^2) Typical Case: O(N)
    Timer t;
    double eTime;
    std::ifstream rand_file;
    rand_file.open(file_name);
    std::string line;
    t.start();
    if(rand_file.is_open())
    {
        while(getline(rand_file,line) ){
            h.find(line);
            
        }
        rand_file.close();
    }
    t.elapsedUserTime(eTime);
    std::cout <<"	findAll = "<< eTime <<" sec"<< std::endl;
}

void removeAll(ChainedHashTable& h, std::string file_name){//Worst Case: O(N^2) Typical Case: O(N)
    Timer t;
    double eTime;
    std::ifstream rand_file;
    rand_file.open(file_name);
    std::string line;
    t.start();
    if(rand_file.is_open())
    {
        while (getline(rand_file,line) ){
            h.remove(line);
        }
        rand_file.close();
    }
    t.elapsedUserTime(eTime);
    std::cout<<"	removeAll =  "<< eTime <<" sec" <<std::endl;
}

void testBrackets(Hasher& hasher, std::string word){
    ChainedHashTable test = ChainedHashTable(5000, hasher);
    test.insert(word);
    test[word]++;
}
void testHash(std::string inputFileName, Hasher & hasher)
{
    ChainedHashTable test = ChainedHashTable(5000, hasher);
    testConstructor(hasher);
    testCopyConstructor(hasher);
    insertAll(test, inputFileName);
    findAll(test, inputFileName);
    removeAll(test, inputFileName);
    testBrackets(hasher, "what is up");

}

int main()  {
  GeneralStringHasher h;
  SumHasher sh;
  ProdHasher ph;
  std::cout<<"Hash function 1 chain length statistics"<<std::endl;
  testHash("random.txt", h);
  std::cout<<"Hash function 2 chain length statistics"<<std::endl;
  testHash("random.txt", sh);
  std::cout<<"Hash function 3 chain length statistics"<<std::endl;
  testHash("random.txt", ph);}
