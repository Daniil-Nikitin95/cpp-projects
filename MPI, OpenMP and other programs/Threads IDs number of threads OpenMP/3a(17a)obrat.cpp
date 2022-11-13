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
	int count;
	printf("���������������� ������� 1\n");
	
	
	//�������� ������������ �����
    #pragma omp parallel
    {
		count = omp_get_num_threads();
        for (int i = count - 1; i >= 0; i--)
        {
        	
        	
        	//����� ����� ���� �����
            #pragma omp barrier
            {
                if (i == omp_get_thread_num())
                {
                	
                	
                	//�������, � ������� ��� ����������� ����� ������� �� ���
                    #pragma omp critical
                    if(i==0)
                    {
                    	cout << "����� ����� " << count << endl;
					}
					else
					{
						cout << "������������ �������, ����� ���� " << i << endl;
					}
                }
            }
        }
    }
	printf("���������������� ������� 2\n");
}
