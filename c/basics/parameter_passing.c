/*
    ===================================================================
    📁 File: parameter_passing_in_c.c
    📚 Topic: Parameter Passing Methods in C
    🧠 Purpose: Demonstrates the following parameter passing mechanisms:
               1. Call by Value
               2. Call by Address (using pointers)

               Also covers parameter passing for:
               - Built-in data types (like int)
               - User-defined data types (like struct)

    ⚠️ Note:
    - Arrays in C are **always passed by address**, even if written as `int arr[]`.
    - C does **not** support Call by Reference directly (as in C++).
      That will be covered in C++ basics.
    ===================================================================
*/

#include <stdio.h>

/*
    ===============================
    🏗️ User-Defined Structure: Rectangle
    ===============================
    Represents a rectangle with:
    - length
    - breadth
    - area (float)
*/
struct Rectangle {
    int length;
    int breadth;
    float area;
};

/*
    ========================================
    🔁 Call by Value: Built-in Data Types
    ========================================
    Swap function that works with **copies** of a and b.
    Changes made here do NOT affect original variables.
*/
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

/*
    ============================================
    🔁 Call by Address: Built-in Data Types
    ============================================
    Uses pointers to swap values at the memory addresses
    of a and b. This will affect the original variables.
*/
void swapByAddress(int *a, int *b) {
    int temp = *a;      // dereferencing
    *a = *b;
    *b = temp;
}

/*
    ========================================
    🧮 Call by Value: User-Defined Data Type
    ========================================
    Accepts a copy of the Rectangle object.
    Any changes made (like updating area) will
    NOT reflect in the original object.
*/
void calculateAreaByValue(struct Rectangle r) {
    float area = r.length * r.breadth;
    r.area = area;  // change won't reflect in caller
}

/*
    =========================================
    🧮 Call by Address: User-Defined Data Type
    =========================================
    Accepts a pointer to the Rectangle object.
    Updates made (like area calculation) will
    directly modify the original object.
*/
void calculateAreaByAddress(struct Rectangle *r) {
    float area = r->length * r->breadth;
    r->area = area;
}


/*
    ========================
    🔽 Main Function
    ========================
    Demonstrates parameter passing for:
    - Built-in types: int
    - User-defined types: struct Rectangle
*/
int main() {

    // ----------------------------------------------------------
    // 🔹 Built-in Data Types
    // ----------------------------------------------------------
    int a = 10;
    int b = 20;

    printf("Before swapping: a = %d, b = %d\n", a, b);
    swapByValue(a, b);  // won't affect a & b
    printf("After swapByValue: a = %d, b = %d\n", a, b);

    printf("Before swapping: a = %d, b = %d\n", a, b);
    swapByAddress(&a, &b);  // will affect a & b
    printf("After swapByAddress: a = %d, b = %d\n", a, b);

    // ----------------------------------------------------------
    // 🔹 User-Defined Data Types
    // ----------------------------------------------------------
    struct Rectangle r = {20, 10};  // initialized object

    calculateAreaByValue(r);  // area will NOT update
    printf(
        "Call by Value → length = %d, breadth = %d, area = %.2f\n",
        r.length, r.breadth, r.area
    );

    calculateAreaByAddress(&r);  // area will update
    printf(
        "Call by Address → length = %d, breadth = %d, area = %.2f\n",
        r.length, r.breadth, r.area
    );

    return 0;
}
