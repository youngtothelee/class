#include <stdio.h>

void printMultTableInt(int n);
void printMultTableFrac(int n);

int main(void){

    // You can change this to test your code
    int size = 10;

    printMultTableInt(size);
    printMultTableFrac(size);

    return 0;

}

// Prints multiplication table of integers from 1 to n
void printMultTableInt(int n){
    int i=0, j=0;
    for(i=1;i<n;i++)
    {
        printf("%4d", i);
    }
    printf("\n");
    
    for(i=2;i<n;i++)
    {
        printf("%4d", i);
        for(j=2;j<n;j++)
        {
            printf("%4d", i*j);
        }
        printf("\n");
    }
}

// Prints multiplication table for fractions from 1, 1/2, 1/3 to 1/n
void printMultTableFrac(int n){
    puts("\n");
    float i=0, j=0;
    float myfloat=0;
    for(i=1;i<n;i++)
    {   
        printf(" %.2f ", 1/i);
    }
        printf("\n");

    for(i=2;i<n;i++)
    {
        printf(" %.2f ", 1/i);
        for(j=2;j<n;j++)
        {
            printf(" %.2f ", (1/i)*(1/j));
        }
        printf("\n");
    }

}
