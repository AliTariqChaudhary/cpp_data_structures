#include <iostream>
#include <string>
#include <fstream>
#include "ArrayStack.cpp"
#include "LinkedStack.cpp"

void fillAll(std::string file_name, Stack & stk)//O(n)
{
    std::ifstream rand_file;
    rand_file.open(file_name);
    std::string line;
    if (rand_file.is_open())
    {
        while (getline(rand_file,line) ){
            stk.push(line);
        }
        rand_file.close();
    }
}

void emptyAll(std::string file_name, Stack & stk){//O(n)
    std::ofstream myfile;
    myfile.open (file_name);
    std::string temp;
    while(!stk.isEmpty()){
        myfile<<stk.pop()<<std::endl;   
    }
    myfile.close();
}

int main(int argc, char * argv[]){
    if(argc>4)
        return 0;
    const char * input_file = argv[1];
    const char*  aout = argv[2];
    const char* lout = argv[3];
    LinkedStack LS;
	fillAll(input_file, LS);
    emptyAll(lout, LS);
    ArrayStack AS(45500);
    fillAll(input_file, AS);
    emptyAll(aout, AS);
	return 0;
}
