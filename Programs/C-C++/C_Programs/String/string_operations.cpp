/*
string operations in cpp
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

//function to get the length of the string
int length(char str[]){
    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

//upper case to lower case returning new string
char* lower(char str[]){
    int i=0;
    while(str[i] != '\0'){i++;}
    char* string = (char *)malloc((i+1)*sizeof(char));
    int j=0;
    while (str[j] != '\0')
    {
        if(str[j] >= 65 && str[j] <= 90){
            string[j] = str[j]+32;
        }else if(str[j]>=97 && str[j]<=122){
            string[j] = str[j];
        }else{
            string[j] = str[j];
        }
        j++;
    }
    string[j] = '\0';
    return string;
    
}
//inplace uper case to lower
void inPlaceLower(char* str){
    int i=0;
    while(str[i] != '\0'){
        if(str[i]>=65 && str[i]<=90){
            str[i] = str[i]+32;
        }
        i++;
    }
}

int Words(char str[]){
    int i=0;
    int words = 1;
    while(str[i] !='\0'){
        if(str[i-1]==' '){
            words++;
        }
        i++;
    }
    return words;
    
}

//capatilize case

char* captilize(char str[]){
    int i=0;
    while(str[i] != '\0'){i++;}
    char* string = (char *)malloc((i+1)*sizeof(str[0]));
    int character = 0;
    while(str[character] != '\0'){
        if((str[character] >=97 && str[character] <= 122) && (str[character-1]==' ')){
            string[character] = str[character]-32;
        }else if((str[character]>=97 && str[character]<=122)){
            string[character] = str[character];
        }else if((str[character]>=65 && str[character]<=90)&&(str[character-1]!= ' ')){
            string[character] = str[character]+32;
        }else{
            string[character] = str[character];
        }
        character++;
    }
    if(str[0]>=97 && str[0]<=122){
        string[0] = str[0]-32;
    }
    string[character] = '\0';
    return string;
}

void show(char *str){
    int i=0;
    while(str[i] != '\0'){
        cout<<str[i++];
    }
}

void sentance(char* str){
    int i=0;
    while(str[i] != '\0'){
        if((str[i]>=65 && str[i]<=90)&&(str[i-2]=='.')){

        }else if(str[i]>=65 && str[i]<=90){
            str[i]+=32;
        }else if((str[i]>=97 && str[i]<=122)&&(str[i-2]=='.')){
            str[i]-=32;
        }
        i++;
    }
    if(str[0]>=97 && str[i]<=122){
        str[0]-=32;
    }
}


int main(){
    char stringone[] = "hello woRLd welOcMe To WorlD of StriNg. today we se. And thiIs";
    cout<<stringone<<endl;
    cout<<length(stringone)<<endl;
    // char* stringtwo = lower(stringone);
    // show(stringtwo);
    // cout<<stringtwo<<endl; 
    // inPlaceLower(stringone);
    // cout<<stringone;
    // char* stringtwo = captilize(stringone);
    // cout<<stringtwo;
    // cout<<Words(stringone);
       sentance(stringone);
       cout<<stringone;

    return 0;
}