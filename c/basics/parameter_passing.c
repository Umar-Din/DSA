/*
This file contains code related to parameter passing

1. Call By Value
2. Call By Address
3. Call By Refrance

Parameter passing by the above methods will cover for builtin data-types + user defined data-types
Note:
    - Arrays are always passed by address
    - for arrays formal parameter can be written as 
    1. data-type name[]
    2. data-type *name


Note:
    - C language does not support Call By Refrance 
    - Call By Refrance will be illustrated in cpp basics
*/


#include<stdio.h>

struct Rectange
{
    int length;
    int breadth;
    float area;
};





/*
Call by Value
-------------
- swap function takes parameters as call by value
- modification in formal parameters will not effect the actual parameters 
*/
void swapByValue(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void swapByAddress(int *a, int *b){
    // here formal parameters are pointers
    int temp = *a; //defrencing
    *a = *b;
    *b = temp;
}

// Call By Value
void calculateAreaByValue(struct Rectange r){
    float area = r.length * r.breadth;
    r.area = area;
}

// Call By Address
void calculateAreaByAddress(struct Rectange *r){
    float area = r->length*r->breadth;
    r->area = area;
}



int main(){

    // --------- builtin ---------------------------------------------
    int a,b;
    a = 10;
    b = 20;
    printf("Before swaping Value of [a] = %d & value of [b] = %d\n",a,b);
    swapByValue(a,b);//Call By Value
    printf("After swaping Value of [a] = %d & value of [b] = %d\n",a,b);

    printf("Before swaping Value of [a] = %d & value of [b] = %d\n",a,b);
    swapByAddress(&a,&b);//Call By Address
    printf("After swaping Value of [a] = %d & value of [b] = %d\n",a,b);


    // --------- user defined ------------------------------------------

    struct Rectange r = {20,10};

    calculateAreaByValue(r);
    printf(
        "Area Of Rectange When Call By Value [length]=%d & [breadth]=%d > [area]=%.2f\n",
        r.length,r.breadth,r.area
    );
    calculateAreaByAddress(&r);
    printf(
        "Area Of Rectange When Call By Adress [length]=%d & [breadth]=%d > [area]=%.2f\n",
        r.length,r.breadth,r.area
    );

    return 0;
}