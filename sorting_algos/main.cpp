#include <iostream>
#include <string>
#include "heapSorter.hpp"
#include "insertionSorter.hpp"
#include "quickSorter.hpp"
#include "Timer.h"


void testInsert(int partitions, std::string fn){
   Timer t;
   double eTime;
   InsertionSorter IS(45392);
   IS.insertAllFromFile(partitions, fn);
   t.start();
   IS.sort();
   t.elapsedUserTime(eTime);
   std::cout<<"File: "<<fn<<"Partition: "<<partitions<<"/10. Sorter: InsertionSorter   Time: "<<eTime<<"s"<<std::endl;
 
}

void testHeap(int partitions, std::string fn){   
   Timer t;
   double eTime;
   HeapSorter HS(45392);
   HS.insertAllFromFile(partitions, fn);
   t.start();
   HS.sort();
   t.elapsedUserTime(eTime);
   std::cout<<"File: "<<fn<<"Partition: "<<partitions<<"/10. Sorter: HeapSorter   Time: "<<eTime<<"s"<<std::endl;

}

void testQuick(int partitions, std::string fn){
   Timer t;
   double eTime;
   QuickSorter QS(45392);
   QS.insertAllFromFile(partitions, fn);
   t.start();
   QS.sort();
   t.elapsedUserTime(eTime);
   std::cout<<"File: "<<fn<<"Partition: "<<partitions<<"/10. Sorter: QuickSorter   Time: "<<eTime<<"s"<<std::endl;

}

int main(){
   for(int i = 1; i<=10; i++){
       testInsert(i, "random.txt");
       testInsert(i, "words.txt");
       testHeap(i, "random.txt");
       testHeap(i, "words.txt");
       testQuick(i, "random.txt");
       testQuick(i, "words.txt");    
}
    return 0;
}
