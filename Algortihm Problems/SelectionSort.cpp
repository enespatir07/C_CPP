#include <iostream>
class Sort {
private:
    static void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
public:
    static void selectionSort(int *arr, int size) {

        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[minIndex] > arr[j]) {
                    minIndex = j;
                }
            }
            swap(&arr[minIndex], &arr[i]);
        }
    }
    static void printArray(int *arr, int size) {
        for (int i = 0; i < size; i++)
            std::cout << arr[i] << " ";
    }
};

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    int *arr = new int(size);
    for (int i = 0; i < size; i++) {
        std::cout << "Element-" << i + 1 << ": ";
        std::cin >> arr[i];
    }
    std::cout << "Original array: ";
    Sort::printArray(arr, size);
    Sort::selectionSort(arr, size);
    std::cout << std::endl <<"Sorted array: ";
    Sort::printArray(arr, size);
}
