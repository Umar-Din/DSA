/*
A Taylor series is an infinite sum of terms that represents a mathematical function as an infinite polynomial.
Centered around a specific point, the terms are calculated from the function's derivatives at that point.
It allows complex functions to be accurately approximated locally


ex = 1 + x + x*2/2!...

*/

//header files
#include<stdio.h>


//recersive function to calculate the taylors series
double taylorsSeries(int x, int n){

    static p,f = 1;
    //base condition
    if(p==0){
        return 1;
    }

    int r = taylorsSeries(x, n-1);
    p = p*x;
    f = f*n;
    return r + p/f ;

    
}



//main function
int main(){
    
    return 0;
}