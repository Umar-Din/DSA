/*
find the single missing element in the array.

if the array is of ist n natural numbers
*/

#include<iostream>
using namespace std;


class Array{
    public:
        //data members
        int* arr;
        int len;
        int size;
    public:
        //constructors
        Array(int size):size(size),arr(new int[size]()),len(0){}
        Array(int size, initializer_list<int> elements ):size(size),arr(new int[size]()){
            int i=0;
            for(int element : elements){
                if(i==size)break;
                arr[i++] = element;        
            }len=i;
        }
        // ~Array(){
        //     delete[] arr;
        // }

        //member functions
        void append(int value);
        void display();
        int max();
        int min();
        // Array missing_in_array(Array arr);
};
void Array::append(int value){
    if(len==size) return;
    arr[len] = value;
}
void Array::display(){
    if(len==0 || size==0) return;
    int i =0;
    while(i<len){
        cout<<arr[i++]<<endl;
    }
}

int Array::max(){
    /*returns the maximum element of an array
    if the array is empty it will return -1*/
    if(len==0) return -1;
    int max =  arr[0];
    for(int i=1; i<len; i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}

int Array::min(){
    /*returns the minimun element of array
    if empty array passed it will return -1
    if(len==0) return -1;*/
    int min = arr[0];
    for(int i=1; i<len; i++){
        if(min>arr[i]){
            min=arr[i];
        }
    }return min;
}

Array missing_in_array(Array arr){

    /*return the array with the elements that are not in seq. of array*/
    int max = arr.max();
    if(max==-1){
        Array empty(0);
        return empty;
    }

    Array newarr(max+1);
    newarr.len=max+1;
    Array missing(newarr.size/2);
    for(int i=0;i<arr.len;i++){
        newarr.arr[arr.arr[i]] = 1;
    }
    for(int j=1;j<newarr.len;j++){
        if(newarr.arr[j] != 1){
            missing.append(j);
            missing.len++;
        }
    }
    // delete newarr.arr;
    return missing;
    
}

int findMissing(Array a){
    //find single missing element in the array
    //if the array is of ist n natural numbers.
    //sum of n natural numbers is (n*(n+1))/2
    int sumOfNumbers = 0;
    int sumOfArray = 0;
    int missingNumber;
    int n = a.arr[a.len-1];
    sumOfNumbers = (n*(n+1))/2;
    int i=0;
    while(i<a.len){
        sumOfArray+=a.arr[i++];
    }
    if(sumOfNumbers>sumOfArray){
        missingNumber=sumOfNumbers-sumOfArray;
        return missingNumber;
    }return -1;
}

int Missing(Array a){
    //find single missing element in the array
    //if the array is of ist n natural numbers.

    //sum of n natural numbers is (n*(n+1))/2

    int sumOfNumbers = 0;
    int sumOfArray = 0;
    int missingNumber;
    int n = a.arr[a.len-1];
    sumOfNumbers = (n*(n+1))/2;
    int i=0;
    while(i<a.len){
        sumOfArray+=a.arr[i++];
    }
    if(sumOfNumbers>sumOfArray){
        missingNumber=sumOfNumbers-sumOfArray;
        return missingNumber;
    }return -1;
}

int GetMissing(Array &a){
    //if array is sorted and if of n natural numbers
    //by find the difference
    int start = a.arr[0];
    int n = a.arr[a.len-1];
    int i=0;
    int diff = start-i;
    for(i;i<a.len;i++){
        if(a.arr[i]-i != diff){
            int missingElement = i+diff;
            return missingElement;
            break;
        }
    }return 1;
}

Array multipleMissing(Array &a){
    //natural numbers
    int start = a.arr[0];
    int i=0;
    int diff = start-i;
    Array missing(a.size);
    for(i;i<a.len;i++){
        if(a.arr[i]-i != diff){
            while(diff<a.arr[i]-i){
                missing.append(i+diff);
                missing.len++;
                diff++;
            }
        }
    }return missing;
}

int main(){

    Array arr(10,{1,4,6,8,9,13});
    arr.display();
    // cout<<arr.findMissing()<<" is missing mumber"<<endl;
    // cout<<Missing(arr)<<" Missing Element of Array"<<endl;
    // cout<<GetMissing(arr)<<" Missing Element"<<endl;
    // cout<<"Operations perofromed on array are"<<endl;
    // Array missing = multipleMissing(arr);
    // cout<<arr.max()<<" maximum element of array"<<endl;
    Array missing = missing_in_array(arr);

    missing.display();

    return 0;
}