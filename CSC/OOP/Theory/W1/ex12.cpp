#include <iostream>
using namespace std;

/*
Requirement:
- Implement a sort function that can sort arrays of integers, allowing the user
to dynamically choose between ascending and descending order.
*/

bool ascending(int a, int b) {
    return a <= b;
}

bool descending(int a, int b) {
    return a >= b;
}

void insertionSort(int arr[], int n, bool (*compare)(int, int)) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && !compare(arr[j], key)) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    // A sample array of integers
    int arr[] = { 7, 2, 8, 5, 13, 27 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Input the order of sorting
    int choice;
    do {
        cout << "Choose the order of sorting: 1. Ascending 2. Descending" << endl;
        cout << "Your choice: ";
        cin >> choice;
    } while (choice != 1 && choice != 2);

    // Sort the array according to the user's choice
    insertionSort(arr, n, choice == 1 ? ascending : descending);

    // Print the sorted array
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}