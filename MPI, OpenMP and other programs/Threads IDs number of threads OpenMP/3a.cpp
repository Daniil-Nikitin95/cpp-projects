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
printf("���������������� ������� 1\n");
#pragma omp parallel
{
printf("������������ �������\n");
}
printf("���������������� ������� 2\n");
}
