// Write a function that finds the student with the highest marks using structures.

#include<stdio.h>

typedef struct{
    char name[50];
    int roll;
    float marks;
}student;

student findTopper(student students[],int n){
    student topper=students[0];
    for(int i=1;i<n;i++){
        if(students[i].marks>students[0].marks){
            topper=students[i];
        }
    }
    return topper;
}

void displayTopper(student topper){
    printf("Topper Details\n");
    printf("------------------------------------------------------------\n");
    printf("%-40s|%-10s|%-10s\n","Name","Roll No.","Marks");
    printf("------------------------------------------------------------\n");
    printf("%-40s|%-10d|%-10f\n",topper.name,topper.roll,topper.marks);
}

int main(){
    int n;
    scanf("%d",&n);
    student students[n];
    for(int i=0;i<n;i++){
        printf("Enter Student #%d Details\n",i+1);
        printf("Enter Name :\n");
        scanf(" %[^\n]",students[i].name);
        printf("Enter Roll : \n");
        scanf("%d",&students[i].roll);
        printf("Enter Your Marks :\n");
        scanf("%f",&students[i].marks);
    }
    student topper=findTopper(students,n);
    displayTopper(topper);
    return 0;
}