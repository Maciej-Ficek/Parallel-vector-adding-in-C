#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
#include "program1.h"

int main(int argc, char** argv){
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int local_size = N / size;
    srand(time(NULL));
    double* A = generate_vector(N, 0);
    double* B = generate_vector(N, 1);
    double* C = generate_vector(N, 1);
    MPI_Barrier(MPI_COMM_WORLD);
    double start_time = MPI_Wtime();
    MPI_Scatter(B, local_size, MPI_DOUBLE, B, local_size, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Scatter(C, local_size, MPI_DOUBLE, C, local_size, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    add_vectors(A, B, C, local_size);
    MPI_Gather(A, local_size, MPI_DOUBLE, A, local_size, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    // wypisanie wyników oraz czasu pracy programu
    if (rank == 0){
    printf("%f\n%f\n", A[0], A[N-1]);
    printf("%f\n%f\n", B[0], B[N-1]);
    printf("%f\n%f\n", C[0], C[N-1]);
    double end_time = MPI_Wtime();
    printf("%f\n", end_time - start_time);
}
free(A);
free(B);
free(C);
MPI_Finalize();
return 0;
}
