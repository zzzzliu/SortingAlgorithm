#include <iostream>
#include <cstdlib>
#include "Vector.h"

Vector::Vector(int size) {
    // constructor
    this->size = size;
    length = 0;
    nums = new int[size];
}
Vector::~Vector(void) {
    delete[] nums;
}
int Vector::GetLength(void) {
    return length;
}


void Vector::Grow(void) {
    // Allocate new space
    int new_size = size * 2;
    int *new_array = new int[new_size];
    // Copy objects
    for (int i = 0; i < size; i++)
        new_array[i] = nums[i];
    // Assign new values
    delete[] nums;
    nums = new_array;
    size = new_size;
}
void Vector::Insert(int index, int num) {
    // Check index
    if (index < 0 || index > length)
        throw "Invalid index";
    // Grow if necessary
    if (length == size)
        Grow();
    // Shift elements after index
    for (int i = length - 1; i >= index; i--)
        nums[i + 1] = nums[i];
    // Insert new element
    nums[index] = num;
    length++;
}
int Vector::Delete(int index) {
    // Check index
    if (index < 0 || index >= length)
        throw "Invalid index";
    // Shift element after index
    int save = nums[index];
    for (int i = index + 1; i < length; i++)
        nums[i - 1] = nums[i];
    // Return element
    length--;
    return save;
}
int Vector::Get(int index) {
    // Check index
    if (index < 0 || index >= length)
        throw "Invalid index";
    // Return element
    return nums[index];
}
void Vector::Exchange(int index1, int index2) {
    // Check index 1
    if (index1 < 0 || index1 >= length)
        throw "Invalid index 1";
    // Check index 2
    if (index2 < 0 || index2 >= length)
        throw "Invalid index 2";
    // Exchange elements
    std::swap(nums[index1], nums[index2]);
}
void Vector::Print(void) {
    for (int i = 0; i < length; i++)
        std::cout << nums[i] << std::endl;
}


int Vector::QuickSortPartition(int left, int right) {
    int p = left;
    int randomPivotIndex = rand() % (right - left + 1) + left;
    Exchange(randomPivotIndex, right); // swap the pivot with right

    for (int now = left; now < right; now++) {
        if (nums[now] < nums[right]) {
            Exchange(now, p);
            p++;
        }
    }
    Exchange(right, p);
    return p;
}
void Vector::QuickSort(int left, int right) {
    if (left >= right) return;
    int p = QuickSortPartition(left, right);
    QuickSort(left, p - 1);
    QuickSort(p + 1, right);
}
void Vector::QuickSort() {
    QuickSort(0, length - 1);
}


void Vector::InsertionSort() {
    for (int i = 1; i < length; i++) {
        int value = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > value) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = value;
    }
}


void Vector::Merge(int left1, int right1, int left2, int right2) {
    int* temp = new int[right2 - left1 + 1];
    int n = 0;
    while (left1 <= right1 || left2 <= right2) {
        if (left2 > right2 || (left1 <= right1 && nums[left1] < nums[left2])) {
            temp[n] = nums[left1];
            left1++;
        } else {
            temp[n] = nums[left2];
            left2++;
        }
        n++;
    }
    while (n > 0) {
        nums[right2] = temp[n - 1];
        n--;
        right2--;
    }
    delete[] temp;
}

void Vector::MergeSortRec(int left, int right) {
    int n = right - left + 1;
    if (n <= 1) return;

    MergeSortRec(left, left + n/2 - 1);
    MergeSortRec(left + n/2, right);
    Merge(left, left + n/2 - 1, left + n/2, right);
}

void Vector::MergeSort() {
    MergeSortRec(0, length - 1);
}