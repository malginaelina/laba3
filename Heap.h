#ifndef LABA3_HEAP_H
#define LABA3_HEAP_H
#include <iostream>
#include <list>
#include <cmath>
#include "func.h"

using namespace std;
template<typename T> class BinaryHeap
{
private:
    T* list;
    int size;

public:
    void Insert(T value);
    int GetSize(){
        return size;
    }
    void Heapify(int i);
    T DeleteMax();
    void Print();
    bool Find(T value);
    void DeleteItem(T value);
    BinaryHeap<T>* SubHeap(T value);
    int Height(int hsize);
    int NodeHeight(int index);
    BinaryHeap<T>() {
        list = new T[0];
        size = 0;
    }
    ~BinaryHeap();
    string ToString();
};

template<typename T> BinaryHeap<T>::~BinaryHeap<T>() {
    while (size>0)
        this->DeleteMax();
}

template<typename T> void BinaryHeap<T> :: Insert(T value) {
    int i, parent;
    i = size;
    list[i] = value;
    parent = (i-1)/2;
    while(parent >= 0 && i > 0)  {
        if(list[i] > list[parent]) {
            T temp = list[i];
            list[i] = list[parent];
            list[parent] = temp;
        }
        i = parent;
        parent = (i-1)/2;
    }
    size++;
}

template<typename T> void BinaryHeap<T>:: Heapify(int i) {
    int left, right;
    T temp;
    left = 2*i+1;
    right = 2*i+2;
    if(left < size) {
        if(list[i] < list[left]) {
            temp = list[i];
            list[i] = list[left];
            list[left] = temp;
            Heapify(left);
        }
    }
    if(right < size) {
        if(list[i] < list[right]) {
            temp = list[i];
            list[i] = list[right];
            list[right] = temp;
            Heapify(right);
        }
    }
}

template<typename T> T BinaryHeap<T>::DeleteMax() {
    T x;
    x = list[0];
    list[0] = list[size-1];
    size--;
    Heapify(0);
    return(x);
}

template<typename T> bool BinaryHeap<T>::Find(T value) {
    bool l = false;
    for(int i=0; i<size; i++){
        if(list[i] == value){
            l = true;
        }
    }
    return l;
}

template<typename T> void BinaryHeap<T>::DeleteItem(T value) {
    int i=0;
    while(list[i]!=value){
        i++;
    }
    list[i] = list[size - 1];
    size--;
    Heapify(i);
}

template<typename T> int BinaryHeap<T>::Height(int hsize){
    int k = 0;
    int l = pow(2, k);
    while (l < hsize){
        k++;
        l+= pow(2, k);
    }
    k++;
    return k;
}

template<typename T> int BinaryHeap<T>::NodeHeight(int index){
    int k = Height(size)-Height(index++)+1;
    return k;
}

template<typename T> BinaryHeap<T>* BinaryHeap<T>::SubHeap(T value) {
    BinaryHeap<T>* heap = new BinaryHeap<T>();
    int i = 0;
    int height = 1;
    while (list[i]!=value)
        i++;
    heap->Insert(list[i]);
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int point = l;
    int k = NodeHeight(i);
    while(height < k) {
        while((l <= r) && (l < size) ) {
            heap->Insert(list[l]);
            l++;
        }
        height++;
        l = 2 * point + 1;
        r = 2 * r + 2;
    }
    return heap;
}

template<typename T> string BinaryHeap<T>::ToString(){
    string result = "";
    for(int i=0; i<size; i++)
        result += ToStr(list[i]) + " ";
    return result;
}

template<typename T> void BinaryHeap<T>::Print() {
    int i = 0;
    int k = 1;
    while(i < size) {
        while((i < k) && (i < size)) {
            print(list[i]);
            cout << " ";
            i++;
        }
        cout << endl;
        k = k * 2 + 1;
    }
}

#endif //LABA3_HEAP_H
