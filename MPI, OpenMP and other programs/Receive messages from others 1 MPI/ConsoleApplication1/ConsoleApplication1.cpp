#include <iostream>
#include "mpi.h"
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
    int rank, size, i;
    double y = 0.0, a = 0.0, b = 0.0, c = 0.0, d = 0.0, ch1 = 0.0, ch2 = 0.0, zn1 = 0.0, zn2 = 0.0;
    MPI_Init(&argc, &argv);
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    //если номер текущего процесса равен 0, то получение сообщений от остальных процессов
    if (rank == 0)
    {
        for (i = 1; i < size; ++i) 
        {
            if (i == 1)
            {
                MPI_Recv(&a, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 2)
            {
                MPI_Recv(&b, 1, MPI_DOUBLE, 2, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 3)
            {
                MPI_Recv(&c, 1, MPI_DOUBLE, 3, 0, MPI_COMM_WORLD, &status);
            }
            if (i == 4)
            {
                MPI_Recv(&d, 1, MPI_DOUBLE, 4, 0, MPI_COMM_WORLD, &status);
            }
        }
        y = (a / b) + tan(c / d);
        cout << "y = " << y <<endl;
    }


    //отправка сообщений
    if (rank == 1)
    {
        ch1 = sqrt(abs(pow(size, 8) - pow(8, size)));
        MPI_Send(&ch1, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 2)
    {
        zn1 = sqrt(pow(size, 8) + pow(8, size)) + pow(size, (4.0+(size/5.0)));
        MPI_Send(&zn1, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 3)
    {
        ch2 = sqrt(pow(size, 8) + pow(8, size));
        MPI_Send(&ch2, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
    if (rank == 4)
    {
        zn2 = sqrt(pow(size, 8) + pow(8, size)) + 8.0;
        MPI_Send(&zn2, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }


    MPI_Finalize();
    return 0;
}
