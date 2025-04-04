//Implement a function that sorts an array of structures based on a specific field

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char name[50];
    int roll;
    char university[10];
}student;

int comparebyRoll(const void* a,const void* b){
    return ((*(student*)a).roll)-((*(student*)b).roll);
}

void printStudentUniDetails(student students[],int n){
    printf("---------------------------------------------\n");
    printf("%-30s|%-5s|%-10s\n","Name","Roll","University");
    printf("---------------------------------------------\n");
    for(int i=0;i<n;i++){
        printf("%-30s|%-5d|%-10s\n",students[i].name,students[i].roll,students[i].university);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    student students[n];
    for(int i=0;i<n;i++){
        printf("Details of Student #%d\n",i+1);
        printf("Enter name : \n");
        scanf(" %[^\n]",students[i].name);
        printf("Enter roll no. :\n");
        scanf("%d",&students[i].roll);
        printf("Enter University Name : \n");
        scanf(" %[^\n]",students[i].university);
    }
    printf("Before sorting WRT rolls :\n");
    printStudentUniDetails(students,n);
    printf("\n");
    printf("After sorting :\n");
    qsort(students,n,sizeof(student),comparebyRoll);
    printStudentUniDetails(students,n);
    return 0;
}