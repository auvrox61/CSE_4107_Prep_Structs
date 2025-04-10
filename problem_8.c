//Implement a program that sorts a list of books based on their price using structures.

#include<stdio.h>

typedef struct{
    char name[50];
    char author[50];
    int price;
}book;

void sortByPrice(book books[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(books[j].price>books[j+1].price){
                book temp=books[j];
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }
}

void displaySortedBooks(book books[],int n){
        printf("Books Sorted on The Basis of Pricing :\n");
        printf("-----------------------------------------------------------------\n");
        printf("%-30s|%-30s|%-5s\n","Book","Author","Price");
        printf("-----------------------------------------------------------------\n");
        for(int i=0;i<n;i++){
            printf("%-30s|%-30s|%-5d\n",books[i].name,books[i].author,books[i].price);
        }
}

int main(){
    int n;
    scanf("%d",&n);
    book books[n];
    for(int i=0;i<n;i++){
        printf("Enter details for the Book #%d\n",i+1);
        printf("Enter The Name of The Book :\n");
        scanf(" %[^\n]",books[i].name);
        printf("Enter The Name of The Author :\n");
        scanf(" %[^\n]",books[i].author);
        printf("Enter The Price of The Book :\n");
        scanf("%d",&books[i].price);
    }
    sortByPrice(books,n);
    displaySortedBooks(books,n);
    return 0;
}