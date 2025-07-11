#pragma once

template <typename T>
struct RecursiveStack {
    T* items;
    int top;
    unsigned int maxSize;

    void init(unsigned int stackSize);
    void release();

    bool isEmpty();
    bool isFull();
    void push(T newItem);
    T pop();
    T topValue();

    void copyStackRecursive(const RecursiveStack<T>& s);
    void copyStackHelper(const RecursiveStack<T>& s, int index);
    void printRecursive();
    void printHelper(int index);
};

// Include the implementation file
#include "recursive_stack.ipp"

