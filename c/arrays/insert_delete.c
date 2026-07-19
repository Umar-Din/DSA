#include<stdio.h>
#include "operations.h"




int main(){


    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    Array arr = createArrayFromValues(
        a,10
    );
    displayArrayElements(arr);


    printf("Pushing Element in array\n");
    push(&arr,11);
    displayArrayElements(arr);


    printf("Poping Element in array\n");
    pop(&arr);
    displayArrayElements(arr);

    printf("Inserting 101 at index 1\n");
    insert(&arr,1,101);
    displayArrayElements(arr);


    printf("Inserting 102 at index 0\n");
    insert(&arr,0,102);
    displayArrayElements(arr);


    printf("Removing Element at index 2\n");
    remove(&arr,2);
    displayArrayElements(arr);


    printf("Removing Element at index 0\n");
    remove(&arr,0);
    displayArrayElements(arr);


    printf("Removing Element at index 2\n");
    remove(&arr,2);
    displayArrayElements(arr);


    printf("Inserting Element 3 in sorted array\n");
    insertSorted(&arr,3);
    displayArrayElements(arr);


    printf("Getting Element at index 1\n");
    printf("%d\n",get(arr, 1));
    

    printf("Setting 88 at index 0\n");
    set(&arr,0,88);
    displayArrayElements(arr);


    printf("Setting 99 at index 100\n");
    set(&arr,100,998);
    displayArrayElements(arr);

    free(arr.array);

    return 0;
}