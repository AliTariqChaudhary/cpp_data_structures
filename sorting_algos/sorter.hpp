#ifndef SORTER_HPP
#define SORTER_HPP

#include <string>
#include <fstream>
#include <iostream>


class Sorter{
    public:
    std::string* toSort;
    int capacity;
    int size;
    Sorter(int newCapacity){
        capacity = newCapacity;
        toSort = new std::string[capacity];
    }
    ~Sorter(){
        delete[] toSort;
    }
    void print(std::ostream &out){
        for(int i= 0; i<size; i++)
            out<<toSort[i]<<std::endl;
    };
    void insertAllFromFile(int partition,  std::string fileName){
        std::ifstream rand_file;
        rand_file.open(fileName);
        std::string line;
        size = capacity/10;
        size*=partition;
        int count = 0;
        if(rand_file.is_open())
        {
            while (getline(rand_file,line) ){
                if(count<=size)
                    toSort[count] = line;
                else
                    break;
                count++;
            }
            rand_file.close();
        }
    };
    virtual void sort(){};

};

#endif