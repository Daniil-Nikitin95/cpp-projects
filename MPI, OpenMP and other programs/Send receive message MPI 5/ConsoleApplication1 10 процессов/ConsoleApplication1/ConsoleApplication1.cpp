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
    vector<int> vec1(10), vec2(10), sums(10);
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
            if (i == 6)
            {
                MPI_Recv(&sums[5], 1, MPI_INT, 6, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 7)
            {
                MPI_Recv(&sums[6], 1, MPI_INT, 7, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 8)
            {
                MPI_Recv(&sums[7], 1, MPI_INT, 8, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 9)
            {
                MPI_Recv(&sums[8], 1, MPI_INT, 9, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 10)
            {
                MPI_Recv(&sums[9], 1, MPI_INT, 10, 0, MPI_COMM_WORLD, &status);
            }
        }
        cout << "Sum = " << accumulate(sums.begin(), sums.end(), 0) << endl;
        double end = MPI_Wtime();
        cout << "Program execution time = " << end - start;
    }


    //отправка сообщений рутовому процессу
    if (rank == 1)
    {
        for (int i = 0; i < 10; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[0] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[0], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 2)
    {
        for (int i = 0; i < 10; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[1] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[1], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 3)
    {
        for (int i = 0; i < 10; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[2] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[2], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 4)
    {
        for (int i = 0; i < 10; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[3] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[3], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 5)
    {
        for (int i = 0; i < 10; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[4] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[4], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 6)
    {
        for (int i = 0; i < 10; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[5] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[5], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 7)
    {
        for (int i = 0; i < 10; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[6] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[6], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 8)
    {
        for (int i = 0; i < 10; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[7] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[7], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 9)
    {
        for (int i = 0; i < 10; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[8] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[8], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 10)
    {
        for (int i = 0; i < 10; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[9] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[9], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
