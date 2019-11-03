#include "QuickSort.h"
#include <stdlib.h>
#define LEN 10
int main()
{
    int *array = new int[LEN +1];
    for(int i=1; i <=LEN; i++)
        array[i] =  (rand()%100);
    std::cout<<"before build"<<std::endl;
    for(int i =1; i<=LEN; i++)
        std::cout<<array[i]<<std::endl;
    QuickSort<int> *heap = new QuickSort<int>(array, LEN, [] (int a, int b) {  return a > b; });
    std::cout<<"after build"<<std::endl;
    //heap->print();
    heap->sort();
    for(int i=1; i <=LEN; i++)
        std::cout<<array[i]<<std::endl;
    /*std::cout<<"after sort"<<std::endl;
    heap->print();
    heap->build();
    std::cout<<"after rebuild"<<std::endl;
    heap->print();
    heap->insert(100);
    heap->insert(400);
    heap->insert(2);
    heap->insert(929);
    heap->insert(931);
    heap->insert(932);
    std::cout<<"after insert"<<std::endl;
    heap->print();
    heap->sort();
    std::cout<<"after sort"<<std::endl;
    heap->print();*/
    return 0;
}
