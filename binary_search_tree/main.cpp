#include <iostream>
#include <string>
#include "binarySearchTree.hpp"

void insertAll(BinarySearchTree<std::string, int>& b, int part, std::string file_name){//O(NlogN)
    double eTime;
    std::ifstream rand_file;
    rand_file.open(file_name);
    std::string line;
    int temp = 45392/10;
    temp*=part;
    int count = 0;
    if(rand_file.is_open())
    {
        while (getline(rand_file,line) ){
            if(count<=temp)
                b.insert(line, 1);
            else
                break;
            count++;
        }
        rand_file.close();
    }
}

void findAll(BinarySearchTree<std::string, int>& b, int part, std::string file_name){//O(NlogN)
    double eTime;
    std::ifstream rand_file;
    rand_file.open(file_name);
    std::string line;
    int temp = 45392/10;
    temp*=part;
    int count = 0;
    if(rand_file.is_open())
    {
        while (getline(rand_file,line) ){
            if(count<=temp)
                b.find(line);
            else
                break;
            count++;
        }
        rand_file.close();
    }
}

void removeAll(BinarySearchTree<std::string, int>& b, int part, std::string file_name){//O(NlogN)
    double eTime;
    std::ifstream rand_file;
    rand_file.open(file_name);
    std::string line;
    int temp = 45392/10;
    temp*=part;
    int count = 0;
    if(rand_file.is_open())
    {
        while (getline(rand_file,line) ){
            if(count<=temp)
                b.remove(line);
            else
                break;
            count++;
        }
        rand_file.close();
    }
}
void measureAll(std::string fileName){
    for(int i = 1; i<=10; i++){
        BinarySearchTree<std::string, int> b;
        insertAll(b,i, fileName);
        findAll(b,i, fileName);
        removeAll(b,i, fileName);
    } 
}
void testBrackets(){
    BinarySearchTree<std::string, int> b;
    b.insert("haha",1);
    b["haha"]++;
    std::cout<<b["haha"]<<std::endl;
}
void testCount(){
     BinarySearchTree<std::string, int> b;
     insertAll(b,10, "random.txt");
     b.countLengths();
}
int main()  {
    measureAll("random.txt");
    measureAll("words.txt");
    return 0;
  }
