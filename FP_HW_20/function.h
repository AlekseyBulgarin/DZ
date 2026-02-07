#ifndef FUNCTION_H
#define FUNCTION_H

#ifdef INTEGER
#define fillArray fillArrayInt
#define printArray printArrayInt
#define findMin findMinInt
#define findMax findMaxInt
#define sortArray sortArrayInt
#define editValue editValueInt
#endif

#ifdef DOUBLE
#define fillArray fillArrayDouble
#define printArray printArrayDouble
#define findMin findMinDouble
#define findMax findMaxDouble
#define sortArray sortArrayDouble
#define editValue editValueDouble
#endif

#ifdef CHAR
#define fillArray fillArrayChar
#define printArray printArrayChar
#define findMin findMinChar
#define findMax findMaxChar
#define sortArray sortArrayChar
#define editValue editValueChar
#endif

void fillArrayInt(int arr[], int size);
void printArrayInt(int arr[], int size);
int findMinInt(int arr[], int size);
int findMaxInt(int arr[], int size);
void sortArrayInt(int arr[], int size);
void editValueInt(int arr[], int index, int value);

void fillArrayDouble(double arr[], int size);
void printArrayDouble(double arr[], int size);
double findMinDouble(double arr[], int size);
double findMaxDouble(double arr[], int size);
void sortArrayDouble(double arr[], int size);
void editValueDouble(double arr[], int index, double value);

void fillArrayChar(char arr[], int size);
void printArrayChar(char arr[], int size);
char findMinChar(char arr[], int size);
char findMaxChar(char arr[], int size);
void sortArrayChar(char arr[], int size);
void editValueChar(char arr[], int index, char value);

#endif#pragma once
