#include <stdio.h>
#include <stdlib.h>
#include "program1.h"
#include <mpi.h>

void add_vectors(double* A, double* B, double* C, int local_size)
{	/*
	That program takes two vectors B and C of size local_size
	and stores their sum in vector A of the same type and length
	*/

	double* x = B;
    double* y = C;
    double* z = A;
	for (;;) {
        *z = *x + *y;
        if(z == &A[local_size - 1]){
            break;
        }
        x++;
        y++;
        z++;
    }
}