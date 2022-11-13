#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
//	int arr_x[1000000];
//	int arr_y[1000000];
	int *arr_x, *arr_y;
	arr_x = new int [100000000];
	arr_y = new int [100000000];
	int res=0;
	double start_time, end_time, tick;
	start_time = omp_get_wtime();
	
	
	//вычисление произведения двух массивов
	#pragma omp parallel reduction (+: res) num_threads(12)
	{
		#pragma omp for
		for(int i=0; i<100000000; ++i)
		{
			arr_x[i] = rand()%11-10;
			arr_y[i] = rand()%11-10;
//			printf("x = %d, y = %d\n\n", arr_x[i], arr_y[i]);
		}
		#pragma omp for
		for(int i=0; i<100000000; ++i)
		{
			res+=arr_x[i]*arr_y[i];
		}
	}
	
	
	end_time = omp_get_wtime();
	tick = omp_get_wtick();
	cout<<"Результат скалярного произведения массивов = "<<res<<"\n";
	printf("Время на замер времени %lf\n", end_time-start_time);
	printf("Точность таймера %lf\n", tick);
	delete [] arr_x;
	delete [] arr_y;
	return 0;
}
