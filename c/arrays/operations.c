
#include<stdlib.h>
#include<stdio.h>
#include "operations.h"


int validIndex(Array arr, int index){
    if(index < 0 && index >= arr.lenght){
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


void swap(int *left, int *right){
    int temp = *left;
    *left = *right;
    *right = temp;

}

void inplaceReverse(Array *arr, int start, int end){
    int i = start, j = end;
    while(i < j){
        swap(&arr->array[i++], &arr->array[j--]);
    }
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
    if(index < 0 && index >= arr->lenght){
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
    if(index < 0 && index >= arr->lenght){
        return -1;
    }
    for(int i=index; i<arr->lenght; i++){
        arr->array[i] = arr->array[i+1];
    }
    arr->lenght--;
    return 1;
}

int get(Array arr, int index){
    if(index < 0 && index >= arr.lenght){
        return -1;
    }
    return arr.array[index];
}
int set(Array *arr, int index, int element){
    if (validIndex(*arr, index) == -1){
        return -1;
    }
    arr->array[index] = element;
    return 1;

}


int linearSearch(Array arr, int element){
    for(int i=0; i<arr.lenght; i++){
        if(arr.array[i] == element){
            return i;
        }
    }
    return -1;
}
int binarySearch(Array arr, int element){
    int left = 0;
    int right = arr.lenght-1;

    while(left<=right){
        int mid = left + (right-left)/2;
        if(element == arr.array[mid]){
            return mid;
        }
        else if (element > arr.array[mid])
        {
            left = mid+1;
        }
        else{
            right = mid -1;
        }
        
    }

    return -1;
}


int inplaceLeftShif(Array *arr){
    if(arr->lenght <= 0){
        return -1;
    }
    for(int i=0; i<arr->lenght-1; i++){
        arr->array[i] = arr->array[i+1];
    }
    arr->array[arr->lenght-1] = 0;
    return 1;
}

int inplaceRightShift(Array *arr){
    if(arr->lenght <= 0){
        return -1;
    }
    for(int i=arr->lenght; i>0; i--){
        arr->array[i] = arr->array[i-1];
    }
    arr->array[0] = 0;

    return 1;
}
int inplaceLeftRotate(Array *arr, int times){
    if(arr->lenght <= 0){
        return -1;
    }
    times = times % arr->lenght;
    if(times <= 0){
        return 1;
    }
    inplaceReverse(arr,0,times-1);
    inplaceReverse(arr,times,arr->lenght-1);
    inplaceReverse(arr,0,arr->lenght-1);
    return 1;
}
int inplaceRightRotate(Array *arr, int times){
    if(arr->lenght <= 0){
        return -1;
    }
    times = times % arr->lenght;
    if(times <= 0){
        return 1;
    }
    inplaceReverse(arr,0,arr->lenght-1);
    inplaceReverse(arr,0,times-1);
    inplaceReverse(arr,times,arr->lenght-1);
    return 1;
}

