#include <iostream>

class SelectionSort {
private:
    static void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

public:
    static void selectionSort(int *arr, int size) {

        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;//variable to store the index of smallest number
            for (int j = i + 1; j < size; j++) {
                if (arr[minIndex] > arr[j]) {
                    minIndex = j;
                }
            }
            swap(&arr[minIndex], &arr[i]);
        }
    }
};
