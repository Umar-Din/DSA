/*
This file contains the basic of arrays in c
*/

/*
Array:-> Collection of elements of same data type, stored in continious memory location
        and accessed using index numbers.
Note:-> In C programming language index starts from 0. 
*/

#include<stdio.h>

void printArrayElements(int arr[],int length){
    /*int arr[] is pointer to the actual-parameter as in c arrays are passed by address*/
    for(int index = 0; index < length; index++){
        printf("Element at index[%d] = %d \n",index,arr[index]);
    }
}

// -- main entry point of the program --
int main(){

    /*
    Decleration of array

    data-type name-of-your-array[size-of-your-array]
    */
    int array[5];

    /*
    Initialization of array elements with index

    name-of-your-array[index] = value
    */

    array[0] = 1;
    array[1] = 2;

    /*
    Decleration and Initialization

    data-type name-of-array[size] = {element,...}

    Note: Here if [size is not given the compiler will decide the size based on the elements]
    */

    int array2[5] = {1,2,3,4,5};
    
    printArrayElements(array2,5);

    return 0;

}