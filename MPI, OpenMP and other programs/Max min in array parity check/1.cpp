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
	int arr[1000];
	
	
	//��������� ������ ������� ��������� ����� �� 0 �� 100
	for(int i=0; i<1000; ++i)
	{
		arr[i] = rand()%101;
	}


	int max = arr[0];
	
	
	//���������� ������������ ����� �� ���� 100 �����
	for(int i=1; i<1000; ++i)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}


	int min = arr[0];
	
	
	//���������� ����������� ����� �� ���� 100 �����
	for(int i=1; i<1000; ++i)
	{
		if(arr[i]<min)
		{
			min=arr[i];
		}
	}
	
	
	//����������, ������������ � ����������� ����� ������ ��� ���
	if(max%2==0)
	{
		cout<<"max= "<<max<<" - ������ �����\n\n";
	}
	else
	{
		cout<<"max= "<<max<<" - �������� �����\n\n";
	}
	if(max%2==0)
	{
		cout<<"min= "<<min<<" - ������ �����\n\n";
	}
	else
	{
		cout<<"min= "<<min<<" - �������� �����\n\n";
	}
	
	
	return 0;
}
