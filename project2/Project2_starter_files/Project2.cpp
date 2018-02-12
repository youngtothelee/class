/* Project2.cpp
 * Young Joon Lee
 * EE312, Spring 2018
 * Project 2, Matrix Multiplication
 */

#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>
#include "MatrixMultiply.h"

void multiplyMatrices(
        double a[],
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[]) {
    // https://en.wikipedia.org/wiki/Row-_and_column-major_order


        uint32_t i=0, j=0, k=0, r=0;
        double sum=0;


        for(i=0;i<a_rows;i++){
            for(j=0;j<b_cols;j++){
                    sum=0;
                    for(k=0;k<a_cols;k++){
                        sum=sum+(a[(i*a_cols)+k]*b[(k*b_cols)+j]);
                        r=(i*b_cols)+j;
                        c[r]=sum;
                    }
            }

        }

}

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {


    uint32_t i,j,k, r;
    double** c = (double**)malloc(a_rows* sizeof(double*));
    for(r=0; r < a_rows; r++){
        c[r] = (double*)malloc(a_cols* sizeof(double));
    }

    i = 0;
    while(i < a_rows)
    {
        j=0;
        while(j < b_cols)
        {
            k=0;
            c[i][j] = 0;
            while(k < a_cols)
            {
                c[i][j] += a[i][k] * b[k][j];
                k++;
            }
            j++;
        }
        i++;
    }
    return c;
}

// https://en.wikipedia.org/wiki/Transpose
double** transposeMatrix(
         double** a,
         const uint32_t a_rows,
         const uint32_t a_cols) {

    uint32_t i,j,r;

    double** transpose = (double**)malloc(a_cols* sizeof(double*));
    for(r=0; r < a_cols; r++){
        transpose[r] = (double*)malloc(a_rows* sizeof(double));
    }
    i=0;
    while(i < a_rows){
        j=0;
        while(j < a_cols){
            transpose[j][i] = a[i][j];
            j++;
        }
        i++;
    }
    return transpose;
}
