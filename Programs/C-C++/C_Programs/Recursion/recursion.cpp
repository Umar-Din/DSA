/*
power of the number
*/

#include<iostream>
using namespace std;


//power function

int power(int n, int p){
    if(p==0) return 1;
    return power(n,p-1)*n;
}

int main(){

    cout<<power(2,2)<<endl;


    return 0;
}

