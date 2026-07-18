
#include<stdlib.h>
#include<stdio.h>
#include "operations.h"


int validIndex(Array arr, int index){
    if(index < 0 & index >= arr.lenght){
        return -1;
    }
    return 1;
}

Array createArray(int size){
    Array _a;
    _a.array = (int *) malloc(size*sizeof(int));
    _a.size = size;
    _a.lenght = 0;

    return _a;
}

Array createArrayFromValues(int *elements, int size){
    Array _a;
    // here in malloc s2*size is i am just doubling the size of array
    // so if the elements needs to be added new array needs to created so creating little extra

    _a.array = (int *) malloc(2*size * sizeof(int));
    _a.size = 2*size;
    for(int i=0; i<size; i++){
        _a.array[i] = elements[i];
    }
    _a.lenght = size;

    return _a;
}


void displayArrayElements(Array arr){
    printf("Displaying Array Elements:\n");
    if(arr.lenght <= 0){
        printf("No Elements in the array.\n");
    }
    printf("[ ");
    for(int i=0; i<arr.lenght; i++){
        printf(
            "%d ",arr.array[i]
        );
    }
    printf("]\n");
    printf("%d Elements.\n",arr.lenght);
}


int push(Array *arr, int element){
    if(arr->lenght == arr->size){
        return -1;
    }
    arr->array[arr->lenght++] = element;
    return 1;
}

int pop(Array *arr){
    if(arr->lenght == 0){
        return 0;
    }
    int el = arr->array[arr->lenght-1];
    arr->array[--arr->lenght] = 0;
    return el;
}

int insert(Array *arr, int index, int element){
    if(index < 0 & index >= arr->lenght){
        return -1;
    }
    for(int i=arr->lenght; i > index; i--){
        arr->array[i] = arr->array[i-1];
    }
    arr->array[index] = element;
    arr->lenght++;
    return 1;
}
int insertSorted(Array *arr, int element){
    if(arr->lenght == arr->size){
        return -1;
    }
    int i = arr->lenght -1;
    while (arr->array[i] > element)
    {
        arr->array[i+1] = arr->array[i];
        i--;
    }
    
    arr->array[i+1] = element;
    arr->lenght++;
    return 1;
}
int remove(Array *arr, int index){
    if(index < 0 & index >= arr->lenght){
        return -1;
    }
    for(int i=index; i<arr->lenght; i++){
        arr->array[i] = arr->array[i+1];
    }
    arr->lenght--;
    return 1;
}

int get(Array arr, int index){
    if(index < 0 & index >= arr.lenght){
        return -1;
    }
    return arr.array[index];
}
int set(Array *arr, int index, int element){
    if(index < 0 & index >= arr->lenght){
        return -1;
    }
    arr->array[index] = element;

}