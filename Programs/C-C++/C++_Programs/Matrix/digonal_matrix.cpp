/*
digonal matrix is the squre matrix where all the non digonal elements are 0

A [i,j] = if i!=j  formullah
*/

#include<iostream>
using namespace std;

class SqureMatrix{
    public:
    // data memberes
        int *M;
        int dimention;
        int len;
    // constructor
    SqureMatrix(int dimention):dimention(dimention),len(len=0),M(new int[dimention]()){}

    //constructor with elements.
    SqureMatrix(int dimention,initializer_list<int> elements):dimention(dimention),len(len=0),M(new int[dimention]()){
        int i=0;
        for(int ele:elements){
            if(i==dimention) break;
            M[i++] = ele;
            len++;
        }
    }
    // member functions
        void display();
        void set(int row, int column, int value);
        void append(int value);
        int get(int i, int j);
};

void SqureMatrix::display(){
            if(len==0) return;
            for(int i=0;i<len;i++){
                for(int j=0;j<len;j++){
                    if(i==j){
                        cout<<M[i]<<"   ";
                    }else{
                        cout<<0<<"   ";
                    }
                }cout<<endl;
            }
        }
void SqureMatrix::set(int row, int column, int value){
    if(row>=dimention || row>len+1) return;
    if(row == column){
        M[row-1] = value;
        len++;
    }
}

void SqureMatrix::append(int value){
    if(len == dimention) return;
    M[len] = value;
    len++;
}

int SqureMatrix::get(int i, int j){
    if(i>dimention || j> dimention){
        return -1.000;
    }else if(i==j){
        return M[i-1];
    }return 0;
}

int main(){
    SqureMatrix digonal(4,{1,2,3,4});
    SqureMatrix digonal2(10,{21,31,41,51});
    // SqureMatrix emptydigonal(10);
    // emptydigonal.set(1,1,10);
    // emptydigonal.append(300);
    // emptydigonal.append(300);
    // emptydigonal.append(300);
    // emptydigonal.append(300);
    // emptydigonal.set(3,3,20);
    // emptydigonal.display();
    cout<<digonal.get(4,3)<<endl;
    // digonal2.display();
    digonal.display();

    return 0;
}