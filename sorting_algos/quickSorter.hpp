#include "sorter.hpp"
#include <string>
#include <algorithm>
class QuickSorter: public Sorter{
    public:
    QuickSorter(int newCap)
    :Sorter(newCap){};
    std::string medianOfThree(int l, int h){
        int temp = size/2;
        return max(min(toSort[l],toSort[temp]), min(max(toSort[l], toSort[temp]), toSort[h]));
        
    }
    void swap(int one, int two){
        std::string temp = toSort[one];
        toSort[one] = toSort[two];
        toSort[two] = temp;
    }
    int partition(int l, int h){
        std::string pivot = medianOfThree(l,h);
        int temp = l-1;
        for(int i = l; i<h; i++){
            if(toSort[i]<=pivot){
                temp++;
                swap(i, temp);
            }
        }
        swap(temp+1, h);
        return temp+1;
    }
    void sorter(int l, int h){
            if(l<h){
                int part = partition(l,h);
                sorter(l, part-1);
                sorter(part+1, h);
            }
    };
    void sort(){
        if(size<16)
            insertionSort();
        else
           sorter(0, size-1);
    }
    void insertionSort(){
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