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
	printf("ѕоследовательна€ область 1\n");
	
	
	//создание параллельных нитей
    #pragma omp parallel
    {
		count = omp_get_num_threads();
        for (int i = count - 1; i >= 0; i--)
        {
        	
        	
        	//точка сбора всех нитей
            #pragma omp barrier
            {
                if (i == omp_get_thread_num())
                {
                	
                	
                	//область, в которой код выполн€етс€ одним потоком за раз
                    #pragma omp critical
                    if(i==0)
                    {
                    	cout << "¬сего нитей " << count << endl;
					}
					else
					{
						cout << "ѕараллельна€ область, номер нити " << i << endl;
					}
                }
            }
        }
    }
	printf("ѕоследовательна€ область 2\n");
}
