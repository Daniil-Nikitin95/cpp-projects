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
	
	
	//Заполняем массив тысечей случайных чисел от 0 до 100
	for(int i=0; i<1000; ++i)
	{
		arr[i] = rand()%101;
	}


	int max = arr[0];
	
	
	//определяем максимальное число из этих 100 чисел
	for(int i=1; i<1000; ++i)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}


	int min = arr[0];
	
	
	//определяем минимальное число из этих 100 чисел
	for(int i=1; i<1000; ++i)
	{
		if(arr[i]<min)
		{
			min=arr[i];
		}
	}
	
	
	//определяем, максимальное и минамальное числа четные или нет
	if(max%2==0)
	{
		cout<<"max= "<<max<<" - четное число\n\n";
	}
	else
	{
		cout<<"max= "<<max<<" - нечетное число\n\n";
	}
	if(max%2==0)
	{
		cout<<"min= "<<min<<" - четное число\n\n";
	}
	else
	{
		cout<<"min= "<<min<<" - нечетное число\n\n";
	}
	
	
	return 0;
}
