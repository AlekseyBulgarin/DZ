#include <iostream>
#include <cstdlib>
#include <ctime>
#include "function.h"

using namespace std;

void fillArrayInt(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void printArrayInt(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMinInt(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

int findMaxInt(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void sortArrayInt(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void editValueInt(int arr[], int index, int value) {
    if (index >= 0 && index < 10) {
        arr[index] = value;
    }
}

void fillArrayDouble(double arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 1000) / 10.0;
    }
}

void printArrayDouble(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

double findMinDouble(double arr[], int size) {
    double min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

double findMaxDouble(double arr[], int size) {
    double max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void sortArrayDouble(double arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void editValueDouble(double arr[], int index, double value) {
    if (index >= 0 && index < 10) {
        arr[index] = value;
    }
}

void fillArrayChar(char arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = 'A' + rand() % 26;
    }
}

void printArrayChar(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

char findMinChar(char arr[], int size) {
    char min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

char findMaxChar(char arr[], int size) {
    char max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void sortArrayChar(char arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void editValueChar(char arr[], int index, char value) {
    if (index >= 0 && index < 10) {
        arr[index] = value;
    }
}