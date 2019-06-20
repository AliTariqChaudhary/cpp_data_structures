#include <iostream>
#include <string>
#include <fstream>
#include "ArrayQueue.cpp"
#include "LinkedQueue.cpp"

void fillAll(std::string file_name, Queue & que)//O(n)
{
    std::ifstream rand_file;
    rand_file.open(file_name);
    std::string line;
    if (rand_file.is_open())
    {
        while (getline(rand_file,line) ){
            que.enq(line);
        }
        rand_file.close();
    }
}

void emptyAll(std::string file_name, Queue & que){//O(n)
    std::ofstream myfile;
    myfile.open (file_name);
    while(!que.isEmpty()){
        myfile<<que.deq()<<std::endl;   
    }
    myfile.close();
}

int main(int argc, char * argv[]){
    if(argc<4)
       return 0;
    const char* input_file = argv[1];
    const char* array_file = argv[2];
    const char* linked_file = argv[3];
    ArrayQueue AQ(45500);
    fillAll(input_file, AQ);
    emptyAll(array_file, AQ);
    LinkedQueue LQ;
	fillAll(input_file, LQ);
    emptyAll(linked_file, LQ);
	return 0;
}
