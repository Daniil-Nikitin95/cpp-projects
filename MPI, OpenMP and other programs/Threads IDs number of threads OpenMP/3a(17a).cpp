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
int count, num;
printf("���������������� ������� 1\n");
#pragma omp parallel
{
count=omp_get_num_threads();//�������� ��������� ������������ �����
num=omp_get_thread_num();	//�������� ����� ������ ����
if (num == 0) printf("����� �����: %d\n", count);
else printf("���� ����� %d\n", num);
}
printf("���������������� ������� 2\n");
}

