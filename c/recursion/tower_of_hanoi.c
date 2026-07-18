/*
The Tower of Hanoi is a classic mathematical puzzle invented by French mathematician Édouard Lucas in 1883. 
It consists of three rods and multiple disks of different sizes. 
The objective is to move the entire stack of disks from the starting rod to a target rod, following three strict rules.

Rules:
Only one disk can be moved at a time.
Each move involves taking the upper disk from one of the stacks and placing it on top of another stack or an empty rod.
No larger disk may be placed on top of a smaller disk

*/


#include<stdio.h>



void towerOfHanoi(int nDisks, char t1, char t2, char t3){

    if(nDisks > 0){
        towerOfHanoi(nDisks - 1, t1, t3, t2);
        printf(
            "Moving Disk(%d) from Tower %c -> %c Using %c \n", nDisks, t1,t3,t2
        );
        towerOfHanoi(nDisks-1, t2,t1,t3);
    }
}



int main(){

    int noOfDisks;
    printf("Enter the number of Disks : ");
    scanf("%d",&noOfDisks);
    towerOfHanoi(noOfDisks,'A','B','C');

    return 0;
}