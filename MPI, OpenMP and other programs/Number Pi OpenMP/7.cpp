#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

double x(int i, int N)
{
	return (i+0.5)*(1/N);
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	double sum = 0.0, pi;
	int count, N = atoi(argv[0]);
	cout << "������� �������� ���������� ����� ��: \n";
	cin >> N;
	double start_time, end_time, tick;
	start_time = omp_get_wtime();
	
	
	//���������� ����� ��
	#pragma omp parallel num_threads(8)
	{
		count = omp_get_num_threads();
		#pragma omp for
		for (int i = 0; i < N; ++i)
		{
			#pragma omp atomic
			sum += 4 / (1 + pow(x(i, N), 2));
		}
	}
	end_time = omp_get_wtime();
	pi = sum * (1.0 / N);
	tick = omp_get_wtick();
	printf("����� �� � ��������� %d: %.8f\n", N, pi);
	printf("���������� ����� = %d\n", count);
	printf("����� �� ����� ������� %lf\n", end_time-start_time);
	printf("�������� ������� %lf\n", tick);
	return 0;
}
