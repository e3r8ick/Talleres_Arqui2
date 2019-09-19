#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <unistd.h>

static long n = 10000;
int x[10000];
int y[10000];
int a=5;

void genArray(){
	int a,b;
	for(a=0;a<n;a++){ //ciclo para escribir el entero en las posiciones del arreglo
    		x[a]= rand() % (RAND_MAX);//se realiza el random para introducir el numero
   	}
	for(b=0;b<n;b++){ //ciclo para escribir el entero en las posiciones del arreglo
    		y[b]= rand() % (RAND_MAX);//se realiza el random para introducir el numero
   	}
}

int main ()
{	srand(time(NULL));
	genArray();
	double sum = 0.0;
	int i, nprocs;
	double start_time, run_time;
	nprocs=2*omp_get_num_procs();
	for (i=1;i<=nprocs;i++){
		sum = 0.0;
		omp_set_num_threads(i);
		start_time = omp_get_wtime();
		#pragma omp parallel
		{
			#pragma omp single
			printf(" num_threads = %d",omp_get_num_threads());
			#pragma omp for reduction(+:sum) private(x)
			for (i = 0; i < n; ++i){
				y[i] = a*x[i] + y[i];
			}

	}
	run_time = omp_get_wtime() - start_time;
	printf("\n %f seconds \n",run_time);
	}
}
