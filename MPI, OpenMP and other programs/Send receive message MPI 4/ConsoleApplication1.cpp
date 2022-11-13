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
    int rank, size, max, max0 = 0, max1 = 0, max2 = 0, max3 = 0, i;
    vector<int> vec(100), maxs(4);
    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    //получение сообщений от всех процессов, кроме рутового
    if (rank == 0)
    {
        for (int i = 1; i < size; ++i)
        {
            if (i == 1)
            {
                MPI_Recv(&max0, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
                maxs[0] = max0;
            }
            if (i == 2)
            {
                MPI_Recv(&max1, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);
                maxs[1] = max1;
            }
            if (i == 3)
            {
                MPI_Recv(&max2, 1, MPI_INT, 3, 0, MPI_COMM_WORLD, &status);
                maxs[2] = max2;
            }
            if (i == 4)
            {
                MPI_Recv(&max3, 1, MPI_INT, 4, 0, MPI_COMM_WORLD, &status);
                maxs[3] = max3;
            }
        }
        auto result = max_element(maxs.begin(), maxs.end());
        i = std::distance(maxs.begin(), result);
        max = maxs[i];
        cout << "Max = " << max << endl;
    }


    //отправка сообщений от остальных процессов
    if (rank == 1)
    {
        for (int i = 0; i < 25; ++i)
        {
            vec[i] = rand() % 1001;
        }
        auto result = max_element(vec.begin(), vec.end());
        i = std::distance(vec.begin(), result);
        max0 = vec[i];
        MPI_Send(&max0, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 2)
    {
        for (int i = 25; i < 50; ++i)
        {
            vec[i] = rand() % 1001;
        }
        auto result = max_element(vec.begin(), vec.end());
        i = std::distance(vec.begin(), result);
        max1 = vec[i];
        MPI_Send(&max1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 3)
    {
        for (int i = 50; i < 75; ++i)
        {
            vec[i] = rand() % 1001;
        }
        auto result = max_element(vec.begin(), vec.end());
        i = std::distance(vec.begin(), result);
        max2 = vec[i];
        MPI_Send(&max2, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 4)
    {
        for (int i = 75; i < 100; ++i)
        {
            vec[i] = rand() % 1001;
        }
        auto result = max_element(vec.begin(), vec.end());
        i = std::distance(vec.begin(), result);
        max3 = vec[i];
        MPI_Send(&max3, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }


    MPI_Finalize();
    return 0;
}
