#include<iostream>
#include<stdlib.h>
using namespace std;


//class Array
class Array{
    private:
        int* A;
        int length;
        int size;
    public:
        Array():size(0),length(0),A(nullptr){}
        Array(int size):size(size){
            A = new int[size]();
        }
        Array(int size, initializer_list<int> elements): size(size),length(0),A(new int[size]()){
            int i = 0;
            for(int ele:elements){
                A[i++] = ele;
                if(i==size) break;
            }
            
            length=i;
        }
        ~Array(){
            delete[] A;
        }
        
        void display();
        int append(int value);
        int pop();
        int remove(int index);
        void add(int index, int value);
        float sum();
        int min();
        int max();
        float average();
        int getvalue(int index);
        int getindex(int value);
        int search(int value);
        void sort(bool assending = true);
        struct Array sorted(bool assending=true);
        struct Array extend(struct Array arr2);
        void reverse();
};


//global swap function
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}



//display array elements
void Array::display(){
    if(length==0){
        return;
    }
    
    for(int i=0;i<length;i++){
        cout<<A[i]<<endl;
    }
    return;
}

// append the element at end
int Array::append(int value){
    if(size==length){
        return -1;
    }
    A[length] = value;
    length ++;
    return value;
}

//pop the element at last
int Array::pop(){
    if(length==0 && size==0){
        return -1;
    }
    int temp = A[length];
    A[length] = 0;
    length--;
    return temp;
}

//remove at index 
int Array::remove(int index){
    if(index>=length || index>0){
        return -1;
    }
    int temp = A[index];
    int i = index;
    for(i;i<length-1;i++){
        A[i]=A[i+1];
        
    }
    length--;
    return temp;
}

//add at specific index

void Array::add(int index, int value){
    if(index>=size || index>length){
        return;
    }
    int i= length-1;
    for(i;i>=index;i--){
        A[i+1]=A[i]; 
    }
    A[index] = value;
    length++;
    return;
}
//sum of the array elements

float Array::sum(){
    if(length==false){
        return 0;
    }
    float sum = 0;
    for(int i=0; i<length; i++){
        sum+=A[i];
    }
    return sum;
}

//min value in array

int Array::min(){
    if(length==false){
        return 0;
    }
    int min = A[0];
    for(int i=1; i<length;i++){
        if(min>A[i]){
            swap(&min,&A[i]);
        }
    }
    return min;
}

//max value in array

int Array::max(){
    if(length==false){
        return 0;
    }
    int max = A[0];
    for(int i=1; i<length; i++){
        if(max<A[i]){
            swap(&max,&A[i]);
        }
    }
    return max;
}

//average of array elements

float Array::average(){
    if(length==false){
        return 0;
    }
    float avg = 0;
    avg = sum()/length;
    return avg;
}


//get value by index
int Array::getvalue(int index){
    if(length==false){
        return -1;
    }else if (index >= length && index<0){
        return -1;
    }
    return A[index];
}

//get index of value//linear search
int Array::getindex(int value){
    if(length==0){
        return -1;
    }for(int i=0; i<length; i++){
        if(A[i]==value){
            return i;
        }
    }
    return -1;
}

//binary search to find the element 

int Array::search(int value){
    if(length==0){
        return -1;
    }
    int l = 0;
    int h = length-1;
    while(l<=h){
        int mid = (l+h)/2;
        if(A[mid]==value){
            return mid;
        }else if(value>A[mid]){
            l = mid+1;
        }else h = mid-1;
    }
    return -1;
}

// sort the array elements using selection sort
//inplace sorting



//sort elemnts by creating the new array


//merge array//extend array by returning the third array



//reverse the array

void Array::reverse(){
    if(length==0) return;
    int i=0;
    int j = length-1;
    while(i<j){
        swap(&A[i],&A[j]);
        i++;
        j--;
    }
}

// main function
int main(){
    Array arr(10,{1,2,3,4,5,6,7,8});
    Array arr2;
    arr.append(10);
    arr.pop();
    arr.remove(0);
    arr.add(0,1);
    cout<<arr.getindex(8)<<" index of value"<<endl;
    cout<<arr.search(5)<<" searched element"<<endl;
    cout<<arr.average()<<" average of elements"<<endl;
    cout<<arr.sum()<<" sum of elements"<<endl;
    cout<<arr.min()<<" minimum of the element"<<endl;
    cout<<arr.max()<<" maximum of the elements"<<endl;
    
    
    arr2.display();

    arr.display();
    // cout<<"new returned array is"<<endl;
    // display(newarr);

    return 0;
}




