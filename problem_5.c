//Write a function that calculates the average marks of a student using structures.

#include<stdio.h>

typedef struct{
    char name[40];
    int roll;
    float marks[5];
}student;

float average(float arr[],int n){
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    float avg=sum/n;
    return avg;
}

void printDetails(student s){
    float avrg=average(s.marks,5);
    printf("------------------------------------------\n");
    printf("%-30s|%-5s|%-7s\n","Name","Roll","Average");
    printf("------------------------------------------\n");
    printf("%-30s|%-5d|%.2f\n",s.name,s.roll,avrg);
}

int main(){
    student s;
    printf("Enter the Student Name :\n");
    scanf(" %[^\n]",s.name);
    printf("Enter roll no. : \n");
    scanf("%d",&s.roll);
    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Mark %d: ", i + 1);
        scanf("%f", &s.marks[i]);
    }
    printDetails(s);
    return 0;
}