#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <ctime>

using namespace std;
 
int main(int argc, char *argv[]) 
{
	
	
	//последовательная область
	srand(time(0));
	int N=atoi(argv[1]);
	int mass[N], max, min;
	double start_time, end_time, tick;
	double omp_get_wtime(void);
	int count = 0;
	cout << "Vvedite massiv iz " << N <<" elementov" << endl;
	
	
	//заполнение масива случайными числами
	for(int r = 0; r<N; r++)
	{
		mass[r] = rand()%99;
	//	cout << mass[r] << " ";
	}
	for(int g=1; g<11; g++)
	{
	cout << "Kolichestvo nitei: ";
	start_time = omp_get_wtime();
	cout << endl;	
	max = mass[0];
	
	
	//параллельная область
#pragma omp parallel num_threads(g) reduction(max:max)
#pragma omp for
	for(int r = 1; r<N; r++)
	{
		if(max < mass[r]) max = mass[r];
	}
	
	
	//последовательная область
	end_time = omp_get_wtime();
	cout << " Max: " << max << endl;
	cout << "Vremya dlya "<< g << " nitei= " << end_time-start_time << ", " << endl;
	cout << "Tochnost taimera " << tick;
}
	return 0;
}
