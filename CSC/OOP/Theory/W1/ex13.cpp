#include <iostream>
using namespace std;

/*
Requirement:
- Implement a sort function that can sort arrays of different data types,
allowing the user to dynamically choose between ascending and
descending order
*/

template <typename T>
bool ascending(T a, T b) {
    return a <= b;
}

template <typename T>
bool descending(T a, T b) {
    return a >= b;
}

template <typename T>
void insertionSort(T arr[], int n, bool (*compare)(T, T)) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && !compare(arr[j], key)) {
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

void inputChoice(int& choice) {
    do {
        cout << "Choose the order of sorting: 1. Ascending 2. Descending" << endl;
        cout << "Your choice: ";
        cin >> choice;
    } while (choice != 1 && choice != 2);
}

int main() {

    // Declare arrays of different data types
    int arr1[] = { 7, 2, 8, 5, 13, 27, -5 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    char arr2[] = { 'b', 'a', 'd', 'c', 'e', 'z' };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    float arr3[] = { 12.1, 11.2, 13.3, 5.4, 6.5, 27.4 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    cout << "Original arrays respectively:" << endl;
    printArray(arr1, n1);
    printArray(arr2, n2);
    printArray(arr3, n3);


    // Input the order of sorting
    int choice1, choice2, choice3;
    cout << "--- Array 1 ---" << endl;
    inputChoice(choice1);

    cout << "--- Array 2 ---" << endl;
    inputChoice(choice2);

    cout << "--- Array 3 ---" << endl;
    inputChoice(choice3);

    
    // Sort arrays
    insertionSort(arr1, n1, choice1 == 1 ? ascending<int> : descending<int>);
    insertionSort(arr2, n2, choice2 == 1 ? ascending<char> : descending<char>);
    insertionSort(arr3, n3, choice3 == 1 ? ascending<float> : descending<float>);

    
    // Print arrays
    cout << "Sorted arrays: respectively" << endl;
    printArray(arr1, n1);
    printArray(arr2, n2);
    printArray(arr3, n3);
    
    return 0;
}