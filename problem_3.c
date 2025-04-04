//Write a function that reads and displays BPL Team details using an array of structures.

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char teams[40];
    char captains[50];
    int titles;
}franchise;

int comparebyTitles(const void* a,const void* b){
    return ((*(franchise*)b).titles)-((*(franchise*)a).titles);
}

void printDetails(franchise franchises[],int n){
    printf("-------------------------------------------------------------------------\n");
    printf("%-30s|%-40s|%-3s\n","Teams","Captains","Titles");
    printf("-------------------------------------------------------------------------\n");
    for(int i=0;i<n;i++){
        printf("%-30s|%-40s|%-3d\n",franchises[i].teams,franchises[i].captains,franchises[i].titles);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    franchise franchises[n];
    for(int i=0;i<n;i++){
        printf("Enter Details of team #%d\n",i+1);
        printf("Team Name :\n");
        scanf(" %[^\n]",franchises[i].teams);
        printf("Captain :\n");
        scanf(" %[^\n]",franchises[i].captains);
        printf("Titles :\n");
        scanf("%d",&franchises[i].titles);
    }
    printf("\n");
    printf("Before Sorting By Title : \n");
    printDetails(franchises,n);
    qsort(franchises,n,sizeof(franchise),comparebyTitles);
    printf("\n");
    printf("After Sorting By Title : \n");
    printDetails(franchises,n);
    return 0;
}