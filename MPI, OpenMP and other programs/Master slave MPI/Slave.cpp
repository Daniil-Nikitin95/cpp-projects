#include <iostream>
#include "mpi.h"

using namespace std;

int main(int argc, char* argv[])
{
    int rank, size;
    /*Объявление интеркоммуникатора*/
    MPI_Comm intercomm;
    MPI_Init(&argc, &argv);


    /*Следующая процедура возвращает на динамически порожденных процессах интеркоммуникатор parent для общения с порождающими процессами.*/
    MPI_Comm_get_parent(&intercomm);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    /*Отправляем в породивший процесс/программу master номер ранга порожденного процесса и количество порожденных процессов*/
    MPI_Send(&rank, 1, MPI_INT, 0, rank, intercomm);
    MPI_Send(&size, 1, MPI_INT, 0, size, intercomm);
    MPI_Finalize();
    return 0;
}