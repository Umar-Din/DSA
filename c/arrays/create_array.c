#include<stdio.h>
#include "operations.h"




int main(){

    int _fixed_size = 10;

    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    Array arr = createArrayFromValues(
        a,10
    );
    displayArrayElements(arr);
    return 0;
}