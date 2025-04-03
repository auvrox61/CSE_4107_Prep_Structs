//Write a program that stores and displays student records using structures.

#include<stdio.h>

struct student{
    char name[50];
    int roll;
    double marks;
};

int main(){
    int n;
    printf("Enter the number of students for comparison : \n");
    scanf("%d",&n);
    struct student students[n];
    for(int i=0;i<n;i++){
        printf("Enter the details of Student #%d\n",i+1);
        printf("Enter Name :\n");
        scanf(" %[^\n]",students[i].name);
        printf("Enter roll no. :\n");
        scanf("%d",&students[i].roll);
        printf("Enter Marks :\n");
        scanf("%lf",&students[i].marks);
    }
    printf("--------------------------------------------------------\n");
    printf("Name                          |Roll      |Marks     \n");
    printf("--------------------------------------------------------\n");
    for(int i=0;i<n;i++){
        printf("%-30s|%-10d|%.2lf\n",students[i].name,students[i].roll,students[i].marks);
    }
    return 0;
}