#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include <functional>
#include <iostream>

template<typename T>
class QuickSort
{
    public:
        QuickSort(T *a, int length, std::function<void(T,T)> &isGreater);
        void sort();
        ~QuickSort();
    private:
        QuickSort();
        void swap(int p, int r);
        void quickSort(int p, int r);
        int partition(int p, int r);
        std::function<bool(T,T)> isGreater;
        int mLength;
        T *mA;
};

template<typename T> QuickSort<T>::QuickSort(T *a, int length, std::function<void(T,T)> &func)
{
    isGreater = func;
    mA = a;
    mLength = length;
}

template<typename T> void QuickSort<T>::sort()
{
    quickSort(0, mLength-1);
}

template<typename T> void QuickSort<T>::quickSort(int p, int r)
{
    if(p<r)
    {
        int q = partition(p, r);
        quickSort(p, q-1);
        quickSort(q+1, r);
    }
}


template<typename T> int QuickSort<T>::partition(int p, int r)
{
    T x = mA[r];
    int i=p-1;
    for(int j=p ; j< r-1; j++)
    {
        if( isGreater(mA[j], x))
        {
            i++;
            swap(i, j);
        }
    }
    swap(i+1, r);
    return i+1;
}
template<typename T> void QuickSort<T>::swap(int p, int q)
{
    T temp = mA[p];
    mA[p] = mA[q];
    mA[q] = temp;
}
#endif
