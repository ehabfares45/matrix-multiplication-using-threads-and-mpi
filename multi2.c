#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

int** first ;
int** second ;
int** multiply;
int n;

void * fillup(void * arg){

first = malloc(n * sizeof(int*));
second = malloc(n * sizeof(int*));
 multiply = malloc(n * sizeof(int*));
for (int i = 0; i < n; i++)
{
	first[i] = (int *)malloc(n * sizeof(int));
	second[i] = (int*)malloc(n * sizeof(int));
	multiply[i] = (int*)malloc(n * sizeof(int));
}
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		first[i][j] = (int)rand() % 10;
		second[i][j] = (int)rand() % 10;
	}


}
}

/////////////////////////////////////////////////////////////////////////////////
void * multi(void * arg)
{
int c =(int *)arg;

int sum = 0;
	for (int d = 0; d < n; d++) {
		for (int k = 0; k < n; k++) {
			sum = (int*)(sum + (first[c][k] * second[k][d]));
		}

		multiply[c][d] = (int*)sum;
		sum = 0;
	}



}
/////////////////////////////////////////////////////////////////////

int main(int argc,char *argv[])
{double total_time;
clock_t start, end;

n = atoi(argv[1]) ;
pthread_t t2;
pthread_t *t1=malloc(n*sizeof(pthread_t ));
pthread_create(&t2,NULL,fillup,NULL);
pthread_join(t2,NULL);

start=clock();
srand(time(NULL));

//sleep(2);
for(int i = 0 ; i < n ; i++)
{
pthread_create(&t1[i],NULL,multi,(void *)i);

}
for(int i = 0 ; i < n ; i++)
{
pthread_join(t1[i],NULL);
}
end = clock();
total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
for (int i = 0; i < n; i++) {
	for (int d = 0; d < n; d++)
		printf("%d\t", multiply[i][d]);

	printf("\n");
}
printf("\n the time is : %f \n", total_time);

return 0;
}
