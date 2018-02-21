#include "Heap.h"
#include <iostream>
int Heap::Left(int i) {
    return i * 2 + 1;
}
int Heap::Right(int i) {
    return i * 2 + 2;
}
int Heap::Parent(int i) {
    return (i - 1) / 2;
}

void Heap::MaxHeapify(int i, int size) {
    // iterative version of MaxHeapify
    bool mark;
    do {
        // declare variables
        int left = Left(i);
        int right = Right(i);
        int max;

        // find the the index of max value among i/left/right
        if (left < size && nums[i] < nums[left])
            max = left;
        else
            max = i;
        if (right < size && nums[max] < nums[right])
            max = right;

        // if the max index is i, the program doesn't enter the
        // if statement and we will quit the iteration
        // else we will continue maxHeapify
        mark = false;
        if (max != i) {
            Exchange(i, max);
            i = max;
            mark = true;
        }
    } while (mark);
}


void Heap::BuildMaxHeap() {
    for (int i = Parent(GetLength() - 1); i >= 0; i--) {
        MaxHeapify(i, GetLength());
    }
}
void Heap::HeapSort() {
    BuildMaxHeap();
    for (int i = GetLength() - 1; i >= 1; i--) {
        Exchange(0, i);
        MaxHeapify(0, i);
    }
}