#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

const 
double dotProduct(double *x, double *y, int n) {
  int i;
  double sum = 0.0;

  for (i = 0; i < n; i++) {
    sum += x[i] * y[i];
  }

  return sum;
}

int main(int argc, char *argv[]) {
  int i, n, my_n;
  double *a, *b, local_sum, result;
  int my_rank, num_procs;
 
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  
  my_n = n / num_procs;
  for(i = 0; i < my_n; i++) {
    a[i] = i;
    b[i] = i * 2;
  }

  local_sum = dotProduct(a, b, my_n);
  MPI_Reduce(&local_sum, &result, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  if (my_rank == 0) {
    printf("dotProduct = %f\n", result);
  }  

  MPI_Finalize();

  return 0;
}
