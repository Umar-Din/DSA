/*
Lower Triangular Martix

*/

#include<iostream>
using namespace std;

class LTM{
    public:
        int *M;
        int dimention;
        int len;
        int size;

        // constructors
        LTM(int dimention): dimention(dimention),len(len=0),size((dimention*(dimention+1))/2),M(new int[(dimention*(dimention+1))/2]()){};

        LTM(int dimention, initializer_list<int> elements):dimention(dimention){
            size = std::distance(elements.begin(),elements.end());
            if((dimention*(dimention+1)/2)!=size){
                cout<<"elements count doenot match the size"<<endl;
            }else{
                len = size;
                M = new int[size];
                std::copy(elements.begin(), elements.end(), M);
            }
        }
        // member functions declerations
        void display();
        void set(int i, int j, int value);
        int get(int i, int j);
};

// class member functions
// display function
void LTM::display(){
    if(len==0) return;
    int i=1;
    for(i;i<=dimention;i++){
        int j=1;
        for(j;j<=dimention;j++){
            if(i>=j){
                cout<<M[(i*(i-1)/2)+(j-1)]<<"   ";
            }else{
                cout<<0<<"   ";
            }
        }cout<<endl;
    }
}

// set function
void LTM::set(int i, int j, int value){
    if(len==0) return;
    if(i>=j){
        M[i*(i-1)/2+(j-1)] = value;
    }else return;
}
// get function
int LTM::get(int i, int j){
    if(len==0) return -1;
    if(i>dimention ||j>dimention) return -1;
    if(i>=j){
        return M[i*(i-1)/2+(j-1)];
    }else{
        return 0;
    }
}





int main(){

    LTM ltm(3,{1,2,3,4,5,6});
    ltm.display();
    ltm.set(2,2,7);
    ltm.display();
    cout<<ltm.get(4,4)<<"  get element"<<endl;
    

    return 0;
}


