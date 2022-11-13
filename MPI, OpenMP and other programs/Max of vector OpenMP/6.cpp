#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int *arr, n;
	arr=new int [1000];
	for(int i=0; i<1000; ++i)
	{
		arr[i] = rand()%101;
	}
	int max=arr[0];
	double start_time, end_time, tick;
	start_time = omp_get_wtime();
	
	
	//определение максимального элемента массива
#pragma omp parallel shared(max) private(n)
	{
#pragma omp for
		for(int i=1; i<1000; ++i)
		{
			if(arr[i]>max)
			{
				max=arr[i];
			}
		}
#pragma omp critical
		{
			n=omp_get_thread_num();
			cout<<"Нить "<<n<<", max="<<max<<"\n";
		}
	}
	
	
	end_time = omp_get_wtime();
	tick = omp_get_wtick();
	printf("Время на замер времени %lf\n", end_time-start_time);
	printf("Точность таймера %lf\n", tick);
	delete [] arr;
	return 0;
}
