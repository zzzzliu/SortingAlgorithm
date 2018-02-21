#include <iostream>
#include "Vector.h"
#include "Heap.h"

void executeAndPrint (int numberOfElements, std::string method) {
    Heap heap;
    for (int i = 0; i < numberOfElements; i++)
        heap.Insert(0, rand() % numberOfElements);

    clock_t start = clock();
    if (method == "InsertionSort") {
        heap.InsertionSort();
    } else if (method == "MergeSort") {
        heap.MergeSort();
    } else if (method == "QuickSort"){
        heap.QuickSort();
    } else {
        heap.HeapSort();
    }

    double elapsed = (double)(clock() - start) * 1000.0 / CLOCKS_PER_SEC;
    std::cout << elapsed << std::endl;
}

int main(int argc, char* argv[]) {
    std::string method = argv[1];

    int elements[] = {5, 50, 500, 5000, 50000, 500000};
    int sizeOfArray = sizeof(elements)/sizeof(elements[0]);
    for (int i = 0; i < sizeOfArray; i++) {
        executeAndPrint(elements[i], method);
    }
}