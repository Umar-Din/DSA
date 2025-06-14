/*
    What is a Structure?
    ===================
    A `struct` in C is a **user-defined data type** that allows you
    to group variables of **different or same data types** under a single name.

    It is used to represent **real-world entities** like Rectangle, Student, Employee, etc.

    🔸 Syntax:
        struct StructName {
            data_type member1;
            data_type member2;
        };

    🔹 `struct` only defines the layout; memory is allocated only when an object is created.
*/



#include<stdio.h>

/*
    ========================================
    🏗️ Structure Definition: Rectangle
    ========================================

    This defines a blueprint for a rectangle with:
    - length (int)
    - breadth (int)
*/
struct Rectangle
{
    int length;
    int breadth;
};
/*
    🔍 Memory Note:
    ----------------
    - Defining `struct Rectangle` doesn't allocate memory.
    - Memory is allocated **only** when you create a variable of this type.
    - If `int` takes 4 bytes, then:
        length (4 bytes) + breadth (4 bytes) = 8 bytes total per object
*/

/*
    ========================================
    🧮 Function: areaOfRectange
    ========================================

    🔹 Purpose:
        Calculates the area of the rectangle passed to it.

    🔹 Parameter:
        struct Rectangle r → passed **by value**
            (a copy of the struct is created)

    🔹 Return:
        The computed area (as float for flexibility)

    📌 Note:
        Passing by value makes a copy; original struct remains unchanged.
*/
float areaOfRectange(struct Rectangle r){
    int area = r.length * r.breadth;
    return area;
}



typedef struct Square
{
    int length;
} Square;

int areaOfSquare(int l){
    return 2*l;
}



/*
    ========================
    🔽 Main Function
    ========================
    Demonstrates:
    - Declaring structure variables (objects)
    - Assigning values using dot operator
    - Calling function with struct as argument
*/
int main(){

    
    /*
        =====================================
        📌 Method 1: Declare then Assign
        =====================================
    */
    struct Rectangle rect_one;
    // Assign values to members using dot operator
    rect_one.length = 10;
    rect_one.breadth = 5;

     /*
        =====================================
        📌 Method 2: Declare and Initialize
        =====================================
        Using aggregate initialization
    */
    struct Rectangle rect_two = {20,10};

    float area = areaOfRectange(rect_two);
    printf("Area of rectange = %.f\n",area);


    // Square s1;
    Square s1 = {10};
    printf("Area of Square: %d\n",areaOfSquare(s1.length));
    
    return 0;
}