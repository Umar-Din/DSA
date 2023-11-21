/*
uper traingular matrix
*/

#include<iostream>
using namespace std;

class UTM{
    public:
        int *M;
        int dimention;
        int len;
        int size;

    UTM(int dimention):dimention(dimention){}
    UTM(int dimention, initializer_list<int> elements):dimention(dimention),len(len=0){

        size = std::distance(elements.begin(),elements.end());
        if(dimention*(dimention+1)/2 !=size){
            cout<<"elements count doesnot match";
        }else{
            M = new int[size];
            std::copy(elements.begin(),elements.end(),M);
            len =  size;
        }
    }

    // member function decleration
    void display();
    void set(int i, int j, int value);
    int get(int i, int j);
};

// member functions
void UTM::display(){
    if(len==0) return;
    for(int i=1; i<=dimention; i++){
        for(int j=1; j<=dimention; j++){
            if(i<=j){
                cout<<M[(i-1)*dimention-((i-1)*(i-2))/2+(j-i)]<<"   ";
            }else{
                cout<<0<<"   ";
            }
        }cout<<endl;
    }
    // for(int i=0;i<15;i++){
    //     cout<<M[i]<<endl;
    // }
}

//set method
void UTM::set(int i, int j, int value){
    if(len==0) return;
    if(i>dimention || j> dimention) return;
    if(i<=j){
        M[(i-1)*dimention - ((i-1)*(i-2))/2+(j-i)] = value;
    }
}
//get method

int UTM::get(int i, int j){
    if(len == 0) return -1;
    if(i>dimention || j>dimention) return -1;
    return M[(i-1)*dimention - ((i-1)*(i-2))/2+(j-i)];
}

int main(){

    UTM matrix(5,{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    matrix.set(3,3, 800);
    cout<<matrix.get(5,6)<<" element"<<endl;
    
    matrix.display();

    // 7300684283


    return 0;
}