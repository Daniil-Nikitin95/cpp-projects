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
	
	
	//����������� ���������� ������������ �����
	#pragma omp parallel reduction (+: count)
	{
		count++;
		printf("������� �������� count: %d\n", count);
	}
	printf("����� �����: %d\n", count);
}

