#pragma once
class Sort
{
    // add data members
    int count;
    int numberList[100];
    void QuickSort(int low, int high, bool ascendent);
    int Partition(int low, int high, bool ascendent);

public:
    // add constuctors
    Sort(int count, int lower, int upper);
    Sort();
    Sort(int* vec, int count);
    Sort(int count, ...);
    Sort(const char* str);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};