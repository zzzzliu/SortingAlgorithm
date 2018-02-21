# Sorting Algorithms
 Comparison of 4 basic sorting algorithms - InsertionSort, MergeSort, 
 HeapSort, and QuickSort. All data structures and algorithms are implemented 
 with c++.

## Acknowledgement
Some helper functions are based on the course materials of [Northeastern University
EECE 7205](http://catalog.northeastern.edu/course-descriptions/eece/).

## Compile and Run
In this program, the general `Dynamic Growing Array` and `Heap` are implemented.
For `Dynamic Growing Array`, it doubles its size every time when the array is full. 
`Heap` inherits `Vector` and is utilized for `HeapSort`. 
To compile the code:
```
$ g++ -Wall -Werror Vector.cc Heap.cc main.cc -o main
```
To run the program

```
./main [sortingAlgorithm]
```

There are 4 options for sorting Algorithm - `InsertionSort`, `MergeSort`, `HeapSort`,
and `QuickSort`. For example, if you want test `MergeSort`, just do:
```
./main MergeSort
```

And the result

```
0.005
0.013
0.12
1.615
15.594
178.787
```

Tells you the temporal cost for sorting `50/500/5,000/50,000/500,000` random numbers
with `MergeSort` in millisecond, respectively.

So This can give us some intuitions about the temporal cost of different sorting 
algorithms. To test them, we grow the input size exponentially, and result shows below.
![comparison](https://user-images.githubusercontent.com/30022073/36461178-33960920-168a-11e8-9fce-ddb06bc3ebf9.jpg)

It shows that for O(nlogn) algorithms, the `QuickSort` has the best performance. And 
indeed, `InsertionSort` is the slowest O(n^2). `HeapSort` and `MergeSort` runs 
between those two algorithms.