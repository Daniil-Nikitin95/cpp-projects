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
    int rank, size;
    vector<int> vec1(20), vec2(20), sums(5);
    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    double start = MPI_Wtime();


    //получение сообщений от всех процессов, кроме рутового
    if (rank == 0)
    {
        for (int i = 1; i < size; ++i)
        {
            if (i == 1)
            {
                MPI_Recv(&sums[0], 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 2)
            {
                MPI_Recv(&sums[1], 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 3)
            {
                MPI_Recv(&sums[2], 1, MPI_INT, 3, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 4)
            {
                MPI_Recv(&sums[3], 1, MPI_INT, 4, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 5)
            {
                MPI_Recv(&sums[4], 1, MPI_INT, 5, 0, MPI_COMM_WORLD, &status);
            }
        }
        cout << "Sum = " << accumulate(sums.begin(), sums.end(), 0) << endl;
        double end = MPI_Wtime();
        cout << "Program execution time = " << end - start;
    }


    //отправка сообщений рутовому процессу
    if (rank == 1)
    {
        for (int i = 0; i < 20; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[0] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[0], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 2)
    {
        for (int i = 0; i < 20; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[1] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[1], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 3)
    {
        for (int i = 0; i < 20; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[2] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[2], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 4)
    {
        for (int i = 0; i < 20; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[3] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[3], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 5)
    {
        for (int i = 0; i < 20; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[4] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[4], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }


    MPI_Finalize();
    return 0;
}
