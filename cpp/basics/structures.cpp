/*
    Structures in C++

    This file contains examples and explanations of how `struct` works in C++, along with comparisons to C.

    Topics Demonstrated:
    - C-style structure with member functions
    - C++ style structure with constructor and destructor
    - Difference in default access specifier
    - Member functions inside structures
    - Usage of struct like class
*/

/*
    🔹 C++ Struct vs Class:

    In C++, both `class` and `struct` can have:
    - Data members
    - Member functions
    - Constructors & Destructors
    - Access specifiers
    - Inheritance, polymorphism, etc.

    🔸 The only difference:
    - `struct` members are public by default
    - `class` members are private by default
*/

/*
    ========================================
    C-Style Structure: Rectangle
    ========================================
    - Demonstrates traditional structure usage (like in C)
    - No constructor/destructor
    - Uses manual initializer method
    - Contains public member functions
*/
#include<iostream>

using namespace std;

/*
Structure in c++ is same as class
- The main difference is access specifers data members in structures are but default public
- struct Rectangle below is defined like c
- struct Squre next will be defined like cpp
*/
struct Rectangle
{
    int length;
    int breadth;
    int area;
    int parameter;

    // Function to initialize the structure manually (like C-style init)
    void initializeRectangle(int l,int b){
        length = l;
        breadth = b;
    }

    int areaOfRectangle(){
        area = length*breadth;
        return area;
    }

    int parameterOfRectangle(){
        parameter = 2*(length+breadth);
        return parameter;
    }
};

/*
    ========================================
    📘 C++-Style Structure: Squre
    ========================================
    - Demonstrates modern C++ usage of struct
    - Includes constructor and destructor
    - No need for separate initialize function
    - Member functions behave like class methods
*/

struct Square
{
    int length;
    int area;
    int parameter;

    // Constructor
    Square(int l){
        length = l;
    }

    int areaOfSquare(){
        area = 2*length;
        return area;
    }

    int parameterOfSquare(){
        parameter = 4*length;
        return parameter;
    }

    // Destructor: Cleans up resources if any (not needed here, but included for learning)
    ~Square() {
        // No dynamic memory to clean, but shows how destructor is declared
    }

};

/*
    ========================
    🔽 Main Program Starts
    ========================
*/
int main() {
    // ========================
    // 📌 C-style Rectangle usage
    // ========================
    struct Rectangle r = {20, 10};  // Using C-style initialization
    // Alternative (C++ style): Rectangle r; r.initializeRectangle(20, 10);

    cout << "Area of Rectangle: " << r.areaOfRectangle() << endl;

    // ========================
    // C++-style Squre usage
    // ========================
    Square s1(10); // Constructor is automatically called

    cout << "Length of Squre: " << s1.length << endl;
    cout << "Area of Squre: " << s1.areaOfSquare() << endl;
    cout << "Parameter (Perimeter) of Squre: " << s1.parameterOfSquare() << endl;

    return 0;
}