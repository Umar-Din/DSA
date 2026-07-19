
#ifndef OPERATIONS_H
#define OPERATIONS_H


#include<stdlib.h>

typedef struct 
{
    int *array;
    int lenght;
    int size;
} Array;


Array createArray(int size);
Array createArrayFromValues(int *elements, int size);

void displayArrayElements(Array arr);

int push(Array *arr, int element);
int pop(Array *arr);

int insert(Array *arr, int index, int element);
int insertSorted(Array *arr, int element);
int remove(Array *arr, int index);

int get(Array arr, int index);
int set(Array *arr, int index, int element);

int linearSearch(Array arr, int element);
int binarySearch(Array arr, int element);

int inplaceLeftShif(Array *arr);
int inplaceRightShift(Array *arr);
int inplaceLeftRotate(Array *arr, int times);
int inplaceRightRotate(Array *arr, int times);

int LeftShif(Array arr);
int RightShift(Array arr);
int LeftRotate(Array arr, int times);
int RightRotate(Array arr, int times);

int isSorted(Array arr);




#endif

