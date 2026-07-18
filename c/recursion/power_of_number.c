/*
The power of a number—also known as an exponent—represents repeated multiplication.
It is written as a base number with a smaller superscript number (the exponent) to its right.
The exponent tells you how many times to multiply the base by itself.


Example:
2³ (two to the power of three) = 2 × 2 × 2 = 8

Rules:
Power of 1: Any number raised to the power of 1 is the number itself.
Power of 0: Any non-zero number raised to the power of 0 is always 1.
Negative Exponents: A negative exponent means to divide. 

*/

//header files
#include<stdio.h>


//recersive function to calculate the power of number
double exponentOfNumber(int number, int power){
    //base condition
    if(power==0){
        return 1;
    }

    return exponentOfNumber(number, power-1) * number;
    
}


double exponetOfNumberOptimise(int number, int power){

    //base condition
    if(power == 0){
        return 1;
    }
    else if(power % 2 == 0){
        return exponetOfNumberOptimise(number*number, power/2);
    }
    return number * exponetOfNumberOptimise(number*number,power/2);
}


//main function
int main(){
    int baseNumber;
    int exponent;
    double result;
    printf("Enter the Base Number:\n");
    scanf("%d",&baseNumber);

    printf("Enter the Exponent:\n");
    scanf("%d",&exponent);

    if (exponent >= 0)
    {
        
        //result = exponentOfNumber(baseNumber, exponent);
        result = exponetOfNumberOptimise(baseNumber, exponent);
    }
    else
    {
        //result = 1.0 / exponentOfNumber(baseNumber, -exponent);
        result = 1.0 / exponetOfNumberOptimise(baseNumber, -exponent);
    }

    printf("%d^%d = %lf\n", baseNumber, exponent, result);
    return 0;
    return 0;
}