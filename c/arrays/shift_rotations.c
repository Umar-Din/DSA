#include<stdio.h>
#include "operations.h"


int main(){

    int elements[5] = {1,2,3,4,5};
    Array arr = createArrayFromValues(elements,5);

    displayArrayElements(arr);
    printf("Right Rotate By 2 Elements \n");
    inplaceRightRotate(&arr,2);
    displayArrayElements(arr);


    printf("Left Rotate By 2 Elements \n");
    inplaceLeftRotate(&arr,2);
    displayArrayElements(arr);


    printf("Right Shift By 1 Elements \n");
    inplaceRightShift(&arr);
    displayArrayElements(arr);

    printf("Left By 1 Elements \n");
    inplaceLeftShif(&arr);
    displayArrayElements(arr);


    free(arr.array);
    return 0;
}