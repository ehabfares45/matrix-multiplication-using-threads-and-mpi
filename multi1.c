#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int** first ;
int** second ;
int** multiply;


int main(int argc,char *argv[])
{

double total_time;
clock_t start, end;

int n = atoi(argv[1]) ;
first = malloc(n * sizeof(int*));
second = malloc(n * sizeof(int*));
 multiply = malloc(n * sizeof(int*));



int sum = 0;



for (int i = 0; i < n; i++)
{
	first[i] = (int *)malloc(n * sizeof(int));

}

for (int i = 0; i < n; i++)
{
	second[i] = (int*)malloc(n * sizeof(int));

}

for (int i = 0; i < n; i++)
{
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

start=clock();
srand(time(NULL));
for (int c = 0; c < n; c++) {
	for (int d = 0; d < n; d++) {
		for (int k = 0; k < n; k++) {
			sum = (int*)(sum + first[c][k] * second[k][d]);
		}

		multiply[c][d] = (int*)sum;
		sum = 0;
	}
}
end = clock();
for (int c = 0; c < n; c++) {
	for (int d = 0; d < n; d++)
		printf("%d\t", multiply[c][d]);

	printf("\n");
}

total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("\n the time is : %f \n", total_time);
return 0;
}
