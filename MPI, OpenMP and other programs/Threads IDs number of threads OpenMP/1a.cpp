#include "omp.h"
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//setlocale(LC_ALL, "rus");

int main(){
	
	
	//�������� ����������� OpenMP
#ifdef _OPENMP
printf("OpenMP is supported!\n");
#endif
}
