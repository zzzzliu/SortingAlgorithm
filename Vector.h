#ifndef VECTOR_H
#define VECTOR_H
class Vector {
protected:
    int* nums;
    int size;  // Number of elements allocated
    int length;  // Number of elements present
    void Grow(); // double the size of vector if is full

    int QuickSortPartition(int left, int right);
    void QuickSort(int left, int right);

    void Merge(int left1, int right1, int left2, int right2);
    void MergeSortRec(int left, int right);

public:
    Vector(int size = 5);
    ~Vector();
    int GetLength();
    void Insert(int index, int num);
    int Delete(int index);
    int Get(int index);

    void Exchange(int index1, int index2);
    void Print(void);

    void QuickSort();
    void InsertionSort();
    void MergeSort();
};
#endif