#include <iostream>
using namespace std;

/*
Implement a sort function that can sort arrays of different data types in
ascending order
*/

template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    // Declare arrays of different data types
    int arr1[] = { 7, 2, 8, 5, 13, 27 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    char arr2[] = { 'b', 'a', 'd', 'c', 'e' };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    float arr3[] = { 12.1, 11.2, 13.3, 5.4, 6.5 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    // Sort arrays
    insertionSort(arr1, n1);
    insertionSort(arr2, n2);
    insertionSort(arr3, n3);

    // Print arrays
    cout << "Sorted arrays respectively:" << endl;
    printArray(arr1, n1);
    printArray(arr2, n2);
    printArray(arr3, n3);
    
    return 0;
}