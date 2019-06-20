#include <string>
#include <iostream>
#include <fstream>
#include "orderedArrayList.cpp"
#include "orderedLinkedList.cpp"
#include "Timer.h"


std::ostream & operator << (std::ostream & out, OrderedArrayList & L){
	L.print(out); return out;
}

std::ostream & operator << (std::ostream & out, OrderedLinkedList & L)
{
	L.print(out); return out;
}

void insert_all_words(std::string file_name, OrderedList & L)//O(n^2)
{
    Timer t;
    double eTime;
    std::ifstream rand_file;
    rand_file.open(file_name);
    t.start();
    std::string line;
    if (rand_file.is_open())
    {
        while (getline(rand_file,line) ){
            L.insert(line);
        }
        rand_file.close();
    }
    t.elapsedUserTime(eTime);
    std::cout << eTime << std::endl;
}

void find_all_words(std::string file_name, OrderedList & L)//O(n^2)
{
    Timer t;
    double eTime;
    std::ifstream rand_file;
    rand_file.open(file_name);
    t.start();
    std::string line;
    if (rand_file.is_open()){
        while (getline(rand_file,line) ){
		L.find(line);
        }
        rand_file.close();
    }
    t.elapsedUserTime(eTime);
    std::cout << eTime << std::endl;
}

void remove_all_words(std::string file_name, OrderedList & L){//O(n^2)
    Timer t;
    double eTime;
    std::ifstream rand_file;
    rand_file.open(file_name);
    t.start();
    std::string line;
    if (rand_file.is_open()){
        while (getline(rand_file,line) ){
            L.remove(line);
        }
        rand_file.close();
    }
    t.elapsedUserTime(eTime);
    std::cout<<eTime<<std::endl;
}


void test_OrderedList_methods(std::string file_name, OrderedList & L){
	insert_all_words(file_name, L);
	find_all_words(file_name, L);
	remove_all_words(file_name, L);
}


int main(int argc, char * argv[]){
	const char * input_file = argc == 2 ? argv[1] : "random.txt";
	OrderedArrayList UAL(45500);
	std::cout<<"Testing OrderedArrayList:"<<std::endl;
	test_OrderedList_methods(input_file, UAL);
	OrderedLinkedList ULL;
	std::cout<<"Testing OrderedLinkedList:"<<std::endl;
	test_OrderedList_methods(input_file, ULL);
	return 0;
}
