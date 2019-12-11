#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

int *tempC;

int main(int argc , char *argv[]){
//int **A;
//int **B;
//int **C;
MPI_Init(&argc, &argv);
int rank,size;
int i,j,k,sum=0;
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
//printf("hello1\n");

//if (0){
	int *A;
	int *B;
	int *C;

	A=(int *)malloc(size * size * sizeof(int ));
	B=(int *)malloc(size * size * sizeof(int ));
	C=(int *)malloc(size * size * sizeof(int ));
	//for(i=0;i<size;i++){
	//	A[i]=(int *)malloc(size*sizeof(int));
	//	B[i]=(int *)malloc(size*sizeof(int));
	//	C[i]=(int *)malloc(size*sizeof(int));
	//}
//}
//else{
//	int A[4][4];
//	int B[4][4];
//	int C[4][4];
//}

tempC =(int *)malloc(size*sizeof(int));

//printf("hello2\n");

//printf("hello3\n");

//printf("hello4\n");
if(rank == 0){
	for(i=0;i<size;i++)
		for(j=0;j<size;j++){
			*(A+i*size+j) = i+j ;//A[i][j]=((int)rand())%50;
			*(B+i*size+j) = i*j ;//B[i][j]=((int)rand())%50;
	}
}
double start_time,end_time;
//printf("hello5\n");
MPI_Bcast(A,size*size,MPI_INT,0, MPI_COMM_WORLD);
MPI_Bcast(B,size*size,MPI_INT,0, MPI_COMM_WORLD);
start_time = MPI_Wtime();
//printf("hello6\n");

i= rank;
for(j=0;j<size;j++){
	sum = 0;
	for(k=0;k<size;k++){
		sum = sum + *(A+i*size+k) * *(B+k*size+j); //A[i][k]*B[k][j];
	}
  	tempC[j]=sum;
}

//printf("hello6.5\n");


MPI_Gather(tempC,size,MPI_INT,C,size,MPI_INT,0,MPI_COMM_WORLD);

//printf("hello6.6\n");

MPI_Barrier(MPI_COMM_WORLD);

//printf("hello6.7\n");

end_time = MPI_Wtime();

if (rank == 0){
	//printf("hello7: Master\n");
	for(i=0; i < size; ++i){
		for(j=0;j<size;j++)
			printf("%d,  ",*(C+i*size+j));
		printf("\n");
	}
}
printf("\n\n");
//MPI_Barrier(MPI_COMM_WORLD);
MPI_Finalize();

printf("Parallel Elapsed time: %f seconds\n", end_time - start_time);
}
