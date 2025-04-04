//Implement a structure that stores complex numbers and performs addition and 
//multiplication on them.

#include<stdio.h>

typedef struct{
    float real;
    float imaginary;
}complex;

complex add(complex c1,complex c2){
    complex result;
    result.real=c1.real+c2.real;
    result.imaginary=c1.imaginary+c2.imaginary;
    return result;
}

complex multiply(complex c1,complex c2){
    complex result;
    result.real = (c1.real*c2.real) - (c1.imaginary*c2.imaginary);
    result.imaginary = (c1.real*c2.imaginary) + (c1.imaginary*c2.real);
    return result;
}

void printResult(complex c){
    if(c.imaginary<0){
        printf("%.2f-%.2fi\n",c.real,c.imaginary);
    } else{
        printf("%.2f+%.2fi\n",c.real,c.imaginary);
    }
}

int main(){
    complex n1,n2,summation,multiplication;
    printf("Enter the first complex number : (Real,Imaginary)\n");
    scanf("%f %f",&n1.real,&n1.imaginary);
    printf("Enter the second complex number : (Real,Imaginary)\n");
    scanf("%f %f",&n2.real,&n2.imaginary);
    printf("Sum : \n");
    add(n1,n2);
    display(add);
    printf("Multiplied Value : \n");
    multiply(n1,n2);
    display(multiply);
    return 0;
}