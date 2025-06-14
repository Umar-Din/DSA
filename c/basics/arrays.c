/*

    An array is a **collection of elements of the same data type**,
    stored in **contiguous memory locations**, and accessed using **index numbers**.

    🔹 Index in C starts from 0.
    🔹 Once declared, size is fixed.
    🔹 Arrays are passed to functions **by address** (i.e., by reference).

    This file includes:
    - Array declaration (with and without initialization)
    - Element assignment
    - Printing array elements using a function
*/

#include<stdio.h>

void printArrayElements(int arr[],int length){
    /*
    🔹 Purpose: Prints each element of the array with its index
    🔹 Parameters:
        - arr[]: integer array passed by reference (as pointer)
        - length: number of elements to print
    🔹 Note: In C, when you pass an array to a function,
             it decays into a pointer.
    */
    for(int index = 0; index < length; index++){
        printf("Element at index[%d] = %d \n",index,arr[index]);
    }
}

/*
    ========================================
    🟢 Main Function
    ========================================
    This is the entry point of the program.
    Demonstrates different ways to declare, initialize,
    and use arrays in C.
*/

int main(){

    /*
        =====================================
        🧪 Method 1: Declaration Only
        =====================================
        Format: data_type array_name[size];

        Memory is allocated, but values are garbage
        until initialized manually.
    */
    int array[5];
    /*
        =====================================
        🧪 Method 2: Individual Initialization
        =====================================
        Format: array[index] = value;

        Here, we initialize first two elements;
        others remain uninitialized (garbage values).
    */
    array[0] = 1;
    array[1] = 2;

    /*
        =====================================
        🧪 Method 3: Declaration + Initialization
        =====================================
        Format: data_type array_name[size] = {val1, val2, ...};

        ✅ You can also omit size: int arr[] = {1,2,3};

        🔸 Compiler determines size automatically if not specified.
        🔸 Remaining elements (if any) are zero-initialized.
    */

    int array2[5] = {1,2,3,4,5};
    
    printArrayElements(array2,5);

    return 0;

}