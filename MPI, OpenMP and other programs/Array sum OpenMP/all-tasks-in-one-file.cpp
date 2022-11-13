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
	int A[10], i, sum = 0;
	
	
	//заполнение массива
	for (i=0; i<10; ++i)
	{ 
		A[i]=1; 
	}
	
	
	//вычисление суммы элементов массива с помощью команды reduction
	#pragma omp parallel shared(A) private(i) reduction (+: sum)
	{
		#pragma omp for
		for (i=0; i<10; ++i)
		{
			sum+=A[i];
		}
	}
	
	
	//вычисление суммы элементов массива с помощью команды atomic
	printf("sum = %d\n", sum);
	sum = 0;
	#pragma omp parallel
	{
		int local_sum = 0;
		#pragma omp for
		for (int i = 0; i < 10; ++i)
		local_sum += A[i];
//		printf("local sum = %d\n", local_sum);
		#pragma omp atomic
		sum += local_sum;
	}
	cout << "sum = " << sum << "\n";
	sum = 0;
	
	
	//вычисление суммы элементов массива с помощью команды critical
	#pragma omp parallel
	{
		int local_sum = 0;
		#pragma omp for
		for (int i = 0; i < 10; ++i)
		local_sum += A[i];
//		printf("local sum = %d\n", local_sum);
		#pragma omp critical
		{
			sum += local_sum;
		}
	}
	cout << "sum = " << sum << "\n";
}
