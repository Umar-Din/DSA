/*
sparse matrix
*/

#include<stdio.h>
#include<stdlib.h>

struct Element{
    int i;
    int j;
    int value;
};

struct SparseMatrix{
    int m;
    int n;
    int elements;
    struct Element *M;
};

void create(struct SparseMatrix* Matrix, int m, int n, int elements, int list_of_elements[5][5]){
    Matrix->m = m;
    Matrix->n = n;
    Matrix->elements = elements;

    Matrix->M = (struct Element *)malloc((Matrix->elements)*(sizeof(struct Element)));
    int index=0;
    int ii = 0;
    int jj = 0;
    for(index;index<Matrix->elements;index++){
        // Matrix->M[i].list_of_elements[0];
        Matrix->M[index].i = list_of_elements[ii][0];
        Matrix->M[index].j = list_of_elements[ii][1];
        Matrix->M[index].value = list_of_elements[ii][2];
        ii++;
    }
}

//
void display(struct SparseMatrix matrix){
    int i,j,k=0;
    for(i=1; i<matrix.n;i++){
        for(j=1; j<matrix.m;j++){
            if(i==matrix.M[k].i && j== matrix.M[k].j){
                printf("%d  ",matrix.M[k++].value);
            }else{
                printf("0  ");
            }
        }
        printf("\n");
    }
}

void add(struct SparseMatrix matrix1,struct SparseMatrix matrix2, struct SparseMatrix *matrix3){
    matrix3->m = matrix1.m;
    matrix3->n = matrix1.n;
    matrix3->M = (struct SparseMatrix *)malloc((matrix1.elements+matrix2.elements)*sizeof(struct Element));
    int i,j,k=0;
    while(i<matrix1.m && j<matrix2.m){
        if(matrix1.M->i<matrix2.M->i){
            matrix3->M;
        }
    }
    
}

int main(){

    struct SparseMatrix matrix1;
    struct SparseMatrix matrix2;
    struct SparseMatrix matrix3;

    int arr[5][5] = {{1,2,3},{1,3,4},{1,4,8},{2,3,4},{3,4,9}};
    create(&matrix1,10,14,5,arr);
    display(matrix1);
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    int arr[5][5] = {{1,2,3},{1,3,4},{1,4,8},{2,3,4},{3,4,9}};
    create(&matrix2,10,14,5,arr);
    display(matrix2);     
    return 0;
}