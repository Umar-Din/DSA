/*
What is factorial is product of an interger and all the positive intergers below it
Denoted by an exclamation mark (!)

How to calculate factorial

n! = n * (n-1) * (n-2) * ... * 1

Rules:
0! = 1
Nagative numbers = Factorial for nagative numbers is undefined

*/

//header files
#include<stdio.h>


//recersive function to calculate the factorial of number
int factorialOfNumber(int n){

    //base condition
    if(n<=0){
        return 1;
    }

    return factorialOfNumber(n-1) * n;
}


//main function
int main(){
    int nthNumber;
    int factorial;
    printf("Enter the nth number:\n");
    scanf("%d",&nthNumber);
    printf("Calculating factorial using Recursion ... \n");
    factorial = factorialOfNumber(nthNumber);
    printf("%d! = %d\n",nthNumber,factorial);
    return 0;
    return 0;
}