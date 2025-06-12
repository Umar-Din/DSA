/*
This file contains the basic of struct 

A user defined data structure which stores the collection of same/different data types

*/


#include<stdio.h>

// Defination of struct
struct Rectangle
{
    int length;
    int breadth;
};
/*
Note:
- struct Rectangle itself does not consume memory.
- Memory is allocated only when you create variables (objects) of that struct type.
- The total memory used = sum of memory required by each member.
- Example:
    If int takes 4 bytes,
    Then an object of struct Rectangle will take:
        length (4 bytes) + breadth (4 bytes) = 8 bytes
*/


/*
Call By Value
*/
float areaOfRectange(struct Rectangle r){
    int area = r.length * r.breadth;
    return area;
}

int main(){

    // creating the object of struct
    struct Rectangle rect_one;
    // assignig value using dot(.) operator
    rect_one.length = 10;
    rect_one.breadth = 5;

    // create and initialize at same time
    struct Rectangle rect_two = {20,10};

    float area = areaOfRectange(rect_two);
    printf("Area of rectange = %.f\n",area);
    
    return 0;
}