
#include <stdio.h>
#include <omp.h>
#include <math.h>

static long n = 100000;
double yi=-3.0;
double xi=0.0;
double x[100001];
double y[100001];
double f[100001];
double h=0.000000000001;

double fn(double x, double y){
	double tmp;
	tmp= x+0.2*y;
	return tmp;
}

int main ()
{
	int i,j,nprocs;
	x[0]=xi;
	y[0]=yi;
	double sum = 0.0;
	double start_time, run_time;
	nprocs=2*omp_get_num_procs();
	/*start timer */
	start_time = omp_get_wtime();
	for (j=1;j<=nprocs;j++){
		omp_set_num_threads(j);
		sum=0.0;
		start_time = omp_get_wtime();
		#pragma omp parallel
		{
			#pragma omp single
			printf("num_threads = %d",omp_get_num_threads());
			#pragma omp for reduction(+:sum)
			for(i=0;i<n;i++){
				f[i]=fn(x[i],y[i]);
				y[i+1]=y[i] + h*f[i];
				x[i+1]=x[i] + h;
			}
		}


	run_time = omp_get_wtime() - start_time;
	printf("\n y = %f en %f seconds \n",y[n],run_time);
	}
}
