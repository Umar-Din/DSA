/*
Sum of N Natural Numbers.

The sum of n natural numbers can be found as
1+2+3+4+5+.....+n = n(n+1)/2

The sum of n natural numbers using recursion
*/

//header files
#include<stdio.h>


//resurcive function to calculate the sum of n natural numbers
int sumOfNNaturalNumbers(int n){

    //base condition
    if(n<=0){
        return 0;
    }
    return sumOfNNaturalNumbers(n-1) + n;
}


//main function
int main(){

    int nthNumber;
    int sum;
    printf("Enter the nth number:\n");
    scanf("%d",&nthNumber);
    printf("Calculating sum using Recursion ... \n");
    sum = sumOfNNaturalNumbers(nthNumber);
    printf("Sum = %d\n",sum);
    return 0;
}