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
	int i;
	double start_time, run_time;

	/*start timer */
	start_time = omp_get_wtime();

	for (i = 0; i < n; ++i){
		y[i] = a*x[i] + y[i];
	}

	run_time = omp_get_wtime() - start_time;
	printf("\n 10000000 ----%f seconds \n",  run_time);

}
