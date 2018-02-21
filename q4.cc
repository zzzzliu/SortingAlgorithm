#include <time.h>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void insertionSort(int v[], int left, int right) {
    int value, i, j;
    for (i = left + 1; i <= right; i++) {
        value = v[i];
        j = i - 1;
        while (j >= left && v[j] > value) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = value;
    }
}

void merge(int v[], int left1, int right1, int left2, int right2) {
    int* temp = new int[right2 - left1 + 1];
    int n = 0;
    while (left1 <= right1 || left2 <= right2) {
        if (left2 > right2 || (left1 <= right1 && v[left1] < v[left2])) {
            temp[n] = v[left1];
            left1++;
        } else {
            temp[n] = v[left2];
            left2++;
        }
        n++;
    }
    while (n > 0) {
        v[right2] = temp[n - 1];
        n--;
        right2--;
    }
    delete[] temp;
}

void mergeSortRec(int v[], int left, int right) {
    int n = right - left + 1;
    if (n <= 1) return;

    mergeSortRec(v, left, left + n/2 - 1);
    mergeSortRec(v, left + n/2, right);
    merge(v, left, left + n/2 - 1, left + n/2, right);
}

void mergeSort(int v[], int n) {

    mergeSortRec(v, 0, n - 1);
}

void hybridSortRec(int v[], int left, int right) {
    int n = right - left + 1;
    if (n <= 1) return;
    if (n < 10) {
        insertionSort(v, left, right);
    } else {
        hybridSortRec(v, left, left + n/2 - 1);
        hybridSortRec(v, left + n/2, right);
        merge(v, left, left + n/2 - 1, left + n/2, right);
    }
}

void hybridSort(int v[], int n) {

    hybridSortRec(v, 0, n - 1);
}

void executeAndPrint (int numberOfElements, string method) {
    int* v = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        v[i] = numberOfElements - i - 1;
    }

    clock_t start = clock();
    if (method == "insertionSort") {
        insertionSort(v, 0, numberOfElements - 1);
    } else if (method == "mergeSort") {
        mergeSort(v, numberOfElements);
    } else {
        hybridSort(v, numberOfElements);
    }

    double elapsed = (double)(clock() - start) * 1000.0 / CLOCKS_PER_SEC;
    std::cout << elapsed << std::endl;

    delete[] v;
}

int main(int argc, char* argv[]) {
    string method = argv[1];
    if (method == "insertionSort") std::cout << method << std::endl;
    if (method == "hybridSort") std::cout << method << std::endl;
    if (method == "mergeSort") std::cout << method << std::endl;

    int elements[] = {5, 50, 500, 5000, 50000, 500000};
    int sizeOfArray = sizeof(elements)/sizeof(elements[0]);
    for (int i = 0; i < sizeOfArray; i++) {
        executeAndPrint(elements[i], method);
    }
}