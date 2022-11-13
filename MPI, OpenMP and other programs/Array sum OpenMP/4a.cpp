#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//setlocale(LC_ALL, "rus");

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	int count = 0;
	
	
	//определение количества параллельных нитей
	#pragma omp parallel reduction (+: count)
	{
		count++;
		printf("“екущее значение count: %d\n", count);
	}
	printf("„исло нитей: %d\n", count);
}

