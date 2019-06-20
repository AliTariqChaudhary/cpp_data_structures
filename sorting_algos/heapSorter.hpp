#include "sorter.hpp"

class HeapSorter: public Sorter{
    public:
    HeapSorter(int newCap)
    :Sorter(newCap){};
    void swap(int one, int two){
        std::string temp = toSort[one];
        toSort[one] = toSort[two];
        toSort[two] = temp;
    }
    void siftSmallestDown(int index, int newsize){
        int root = index;
        int lchild = 2*index+1;
        int rchild = 2*index+2;
        if(lchild<newsize && toSort[lchild]> toSort[root])
            root = lchild;
        if(rchild<newsize && toSort[rchild]> toSort[root])
            root = rchild;
        if(root != index){
            swap(index, root);
            siftSmallestDown(newsize, root);
        }
    };
    void heapify(){
        for (int i = size/2 - 1; i >= 0; i--) 
            siftSmallestDown(i,size);
    };
    void sort(){
        heapify();
        for(int i = size-1; i>=0; i--){
            swap(0,i);
            siftSmallestDown(0,i);
        }
    }
};
