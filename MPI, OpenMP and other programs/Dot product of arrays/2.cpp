#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arr_x[1000];
	int arr_y[1000];
	int res=0;
	
	
	//��������� 2 ������� ���������� �������
	for(int i=0; i<1000; ++i)
	{
		arr_x[i] = rand()%11-10;
		arr_y[i] = rand()%11-10;
	}
	
	
	//����������� ��� 2 �������
	for(int i=1; i<1000; ++i)
	{
		res+=arr_x[i]*arr_y[i];
	}
	
	
	cout<<"��������� ���������� ������������ �������� = "<<res;
	return 0;
}
