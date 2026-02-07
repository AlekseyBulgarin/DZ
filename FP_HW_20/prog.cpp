#include <iostream>
#include "function.h"

#define INTEGER

using namespace std;

int main() {
    const int SIZE = 10;

#ifdef INTEGER
    int arr[SIZE];
#endif

#ifdef DOUBLE
    double arr[SIZE];
#endif

#ifdef CHAR
    char arr[SIZE];
#endif

    fillArray(arr, SIZE);
    cout << "Array: ";
    printArray(arr, SIZE);

    cout << "Min: ";
#ifdef INTEGER
    cout << findMin(arr, SIZE) << endl;
#endif
#ifdef DOUBLE
    cout << findMin(arr, SIZE) << endl;
#endif
#ifdef CHAR
    cout << findMin(arr, SIZE) << endl;
#endif

    cout << "Max: ";
#ifdef INTEGER
    cout << findMax(arr, SIZE) << endl;
#endif
#ifdef DOUBLE
    cout << findMax(arr, SIZE) << endl;
#endif
#ifdef CHAR
    cout << findMax(arr, SIZE) << endl;
#endif

    sortArray(arr, SIZE);
    cout << "Sorted array: ";
    printArray(arr, SIZE);

    editValue(arr, 2, 99);
    cout << "After edit: ";
    printArray(arr, SIZE);

    return 0;
}