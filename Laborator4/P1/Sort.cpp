#include "Sort.h"
#include <iostream>
#include <chrono>
#include <random>
#include <stdarg.h>

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

Sort::Sort(int _count, int lower, int upper) {
    count = _count;
    for (int i = 0; i < count; ++i) {
        numberList[i] = uniform_int_distribution<int>(lower, upper)(rng);
    }
}
Sort::Sort() : numberList{}, count(100) {}
Sort::Sort(int* vec, int _count) {
    count = _count;
    for (int i = 0; i < count; ++i) {
        numberList[i] = vec[i];
    }
}
Sort::Sort(int _count, ...) {
    va_list vl;
    va_start(vl, _count);
    count = _count;
    for (int i = 0; i < count; ++i) {
        int nxt = va_arg(vl, int);
        numberList[i] = nxt;
    }
    va_end(vl);
}
Sort::Sort(const char *str) {

    count = 0;
    int sz = 0;
    while (*(str + sz) != '\0') ++sz;
    int nr = 0, sign = 1;
    bool haveNumber = false;
    for (int i = 0; i < sz; ++i) {
        if (str[i] == ',') {
            if (haveNumber) {
                numberList[count++] = sign * nr;
                nr = 0, sign = 1, haveNumber = false;
            }
        }
        else if(str[i] == '-') {
            sign = -1, haveNumber = true;
        }
        else {
            nr = nr * 10 + (str[i] - '0'), haveNumber = true;
        }
    }
    if(haveNumber) numberList[count++] = sign * nr;
}
int Sort::Partition(int low, int high, bool ascendent) {
    int pivot = numberList[low];
    // mereu vom lua pivotul pe poziti arr[low]
    int L = low + 1, R = high;
    while (L <= R) {
        bool good;
        good = ascendent ? numberList[L] <= pivot : numberList[L] >= pivot;
        if (good) {
            L++;
        }
        good = ascendent ? numberList[R] >= pivot : numberList[R] <= pivot;
        if (good) {
            R--;
        }
        good = ascendent ? (numberList[L] > pivot && numberList[R] < pivot) : (numberList[L] < pivot && numberList[R] > pivot);
        if (L < R && good) {
            swap(numberList[L], numberList[R]);
            L++, R--;
        }
    }
    std::swap(numberList[low], numberList[L - 1]);
    return L - 1;
}
void Sort::InsertSort(bool ascendent) {
    for (int i = 0; i < count; ++i) {
        int j = i - 1;
        while (j >= 0) {
            bool shouldSwap = ascendent ? numberList[j] > numberList[j + 1] : numberList[j] < numberList[j + 1];
            if (shouldSwap) {
                swap(numberList[j], numberList[j + 1]);
                j--;
            }
            else {
                break;
            }
        }
    }
}
void Sort::QuickSort(int low, int high, bool ascendent) {
    if (low < high) {
        int k = Partition(low, high, ascendent);
        Sort::QuickSort(low, k - 1, ascendent);
        Sort::QuickSort(k + 1, high, ascendent);
    }
}
void Sort::QuickSort(bool ascendent) {
    Sort::QuickSort(0, count - 1, ascendent);
}
void Sort::BubbleSort(bool ascendent) {
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count - 1; ++j) {
            bool shouldSwap = ascendent ? numberList[j] > numberList[j + 1] : numberList[j] < numberList[j + 1];
            if (shouldSwap) {
                swap(numberList[j], numberList[j + 1]);
            }
        }
    }
}
void Sort::Print() {
    cout << count << '\n';
    for (int i = 0; i < count; ++i) {
        cout << numberList[i] << ' ';
    }
    cout << '\n';
}
int Sort::GetElementsCount() {
    return count;
}
int Sort::GetElementFromIndex(int index) {
    return numberList[index];
}
