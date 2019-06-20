#include "sorter.hpp"

class InsertionSorter: public Sorter{
    public:
    InsertionSorter(int newCap)
    :Sorter(newCap){};
    void sort(){
        std::string temp = "";
        int tempcount;
        for(int i = 1; i<size; i++){
            temp = toSort[i];
            for(tempcount = i-1; tempcount>=0&&toSort[tempcount]>temp; tempcount--)
                toSort[tempcount+1] = toSort[tempcount];
            toSort[tempcount+1] = temp;
        }    
    };
};