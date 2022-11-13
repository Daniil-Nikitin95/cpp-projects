#include <iostream>
#include "mpi.h"
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char* argv[])
{
    srand(time(0));
    int size, rank, i, max;
    double start, end;
    vector<int> vec(1000000);
    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    //заполнение векторов случайными числами
    if (rank == 0)
    {
        start = MPI_Wtime();
        for (int i = 0; i < 1000000; ++i)
        {
            vec[i] = rand() % 101;
        }
    }
    if (rank == 1)
    {
        start = MPI_Wtime();
        for (int i = 0; i < 1000000; ++i)
        {
            vec[i] = rand() % 101;
        }
    }
    if (rank == 2)
    {
        start = MPI_Wtime();
        for (int i = 0; i < 1000000; ++i)
        {
            vec[i] = rand() % 101;
        }
    }
    if (rank == 3)
    {
        start = MPI_Wtime();
        for (int i = 0; i < 1000000; ++i)
        {
            vec[i] = rand() % 101;
        }
    }
    if (rank == 4)
    {
        start = MPI_Wtime();
        for (int i = 0; i < 1000000; ++i)
        {
            vec[i] = rand() % 101;
        }
    }


    MPI_Barrier(MPI_COMM_WORLD);


    //определение максимального элемента вектора в каждом процессе
    if (rank == 0)
    {
        auto result = max_element(vec.begin(), vec.end());
        i = std::distance(vec.begin(), result);
        max = vec[i];
        end = MPI_Wtime();
        cout << "Max = " << max << ", " << "time to search for the maximum element of the vector in process 0 = " << end - start;
    }
    if (rank == 1)
    {
        auto result = max_element(vec.begin(), vec.end());
        i = std::distance(vec.begin(), result);
        max = vec[i];
        end = MPI_Wtime();
        cout << "Max = " << max << ", " << "time to search for the maximum element of the vector in process 1 = " << end - start;
    }
    if (rank == 2)
    {
        auto result = max_element(vec.begin(), vec.end());
        i = std::distance(vec.begin(), result);
        max = vec[i];
        end = MPI_Wtime();
        cout << "Max = " << max << ", " << "time to search for the maximum element of the vector in process 2 = " << end - start;
    }
    if (rank == 3)
    {
        auto result = max_element(vec.begin(), vec.end());
        i = std::distance(vec.begin(), result);
        max = vec[i];
        end = MPI_Wtime();
        cout << "Max = " << max << ", " << "time to search for the maximum element of the vector in process 3 = " << end - start;
    }
    if (rank == 4)
    {
        auto result = max_element(vec.begin(), vec.end());
        i = std::distance(vec.begin(), result);
        max = vec[i];
        end = MPI_Wtime();
        cout << "Max = " << max << ", " << "time to search for the maximum element of the vector in process 4 = " << end - start;
    }


    MPI_Finalize();
    return 0;
}
