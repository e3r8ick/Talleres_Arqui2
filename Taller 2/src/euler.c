
#include <stdio.h>
#include <omp.h>
#include <math.h>

static long n = 100000;
double yi=-3.0;
double xi=0.0;
double h=0.000000000001;

double fn(double x, double y){
	double tmp;
	tmp= x+0.2*y;
	return tmp;
}

int main ()
{
	int i;
	double f;
	double start_time, run_time;
	/*start timer */
	start_time = omp_get_wtime();

	for(i=0;i<n;i++){
		f=fn(xi,yi);
		yi=yi + h*f;
		xi=xi + h;
	}
	run_time = omp_get_wtime() - start_time;
	printf("\n y = %f en %f seconds \n",yi,run_time);
}
