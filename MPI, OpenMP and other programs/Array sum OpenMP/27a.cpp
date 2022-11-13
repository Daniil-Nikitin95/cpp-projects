#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	int count = 0;
	#pragma omp parallel
	{
		#pragma omp atomic
		count++;
	}
	printf("Число нитей: %d\n", count);
}
