#include <stdio.h>
#include <stdlib.h>
#include "program1.h"

double* generate_vector(int m, int r){
    /*
    That program takes two parameters
    The first is the size of vector to be created.
    The second is 1 if vector needs to be filled with random values
    and other than 1 otherwise
    */
    double* x =(double *)malloc(m * sizeof(double));
    if (x == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    if (r == 1){
    for (int i = 0; i < m; i++){
        x[i]= (double)rand() / RAND_MAX * max_value;
    }
    }
    return x;
}
