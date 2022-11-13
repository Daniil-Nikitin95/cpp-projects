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
    vector<int> vec1(4), vec2(4), sums(25);
    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    double start = MPI_Wtime();


    //получение сообщений
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
            if (i == 11)
            {
                MPI_Recv(&sums[10], 1, MPI_INT, 11, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 12)
            {
                MPI_Recv(&sums[11], 1, MPI_INT, 12, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 13)
            {
                MPI_Recv(&sums[12], 1, MPI_INT, 13, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 14)
            {
                MPI_Recv(&sums[13], 1, MPI_INT, 14, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 15)
            {
                MPI_Recv(&sums[14], 1, MPI_INT, 15, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 16)
            {
                MPI_Recv(&sums[15], 1, MPI_INT, 16, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 17)
            {
                MPI_Recv(&sums[16], 1, MPI_INT, 17, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 18)
            {
                MPI_Recv(&sums[17], 1, MPI_INT, 18, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 19)
            {
                MPI_Recv(&sums[18], 1, MPI_INT, 19, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 20)
            {
                MPI_Recv(&sums[19], 1, MPI_INT, 20, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 21)
            {
                MPI_Recv(&sums[20], 1, MPI_INT, 21, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 22)
            {
                MPI_Recv(&sums[21], 1, MPI_INT, 22, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 23)
            {
                MPI_Recv(&sums[22], 1, MPI_INT, 23, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 24)
            {
                MPI_Recv(&sums[23], 1, MPI_INT, 24, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 25)
            {
                MPI_Recv(&sums[24], 1, MPI_INT, 25, 0, MPI_COMM_WORLD, &status);
            }
        }
        cout << "Sum = " << accumulate(sums.begin(), sums.end(), 0) << endl;
        double end = MPI_Wtime();
        cout << "Program execution time = " << end - start;
    }


    //отправка сообщений
    if (rank == 1)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[0] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[0], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 2)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[1] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[1], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 3)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[2] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[2], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 4)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[3] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[3], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 5)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[4] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[4], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 6)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[5] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[5], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 7)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[6] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[6], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 8)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[7] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[7], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 9)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[8] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[8], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 10)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[9] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[9], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 11)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[10] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[10], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 12)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[11] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[11], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 13)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[12] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[12], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 14)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[13] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[13], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 15)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[14] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[14], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 16)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[15] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[15], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 17)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[16] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[16], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 18)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[17] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[17], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 19)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[18] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[18], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 20)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[19] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[19], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 21)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[20] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[20], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 22)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[21] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[21], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 23)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[22] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[22], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 24)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[23] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[23], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 25)
    {
        for (int i = 0; i < 4; ++i)
        {
            vec1[i] = rand() % 101;
            vec2[i] = rand() % 101;
            sums[24] += vec1[i] * vec2[i];
        }
        MPI_Send(&sums[24], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
