#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
	
	
	//���������������� �������
	setlocale(LC_ALL, "rus");
	int n, count = 0;
	
	
	//������������ �������
	#pragma omp parallel
	{
		
		
		//�������, � ������� ���, ������� ������ ����������� ����� ������� �� ���
		#pragma omp critical
		{
			++count;
			n=omp_get_thread_num();
			printf("���� %d\n", n);
		}
		
		
	}
	printf("����� �����: %d\n", count);
}
