#include <iostream>
#include "mpi.h"

using namespace std;

int main(int argc, char* argv[])
{
    int size, rank1, rank2, rank3;
    MPI_Status status;
    /*Объявление интеркоммуникатора*/
    MPI_Comm intercomm;
    /*Инициализация имени файла slave*/
    char slave[15] = "C:\\slave\\Slave";//Замените на свой путь, второе слово Slave это файл Slave.exe
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    /*Следующая процедура порождает несколько процессов с программой slave и устанавливает с ними связь, возвращая интеркоммуникатор*/
    MPI_Comm_spawn(slave, MPI_ARGV_NULL, 3, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm, MPI_ERRCODES_IGNORE);
    /*Первый аргумент - имя порождаемой программы "slave";
    Второй - отсутствуют параметры запуска программы;
    Третий - максимальное число процессов для запуска = 3;
    Четвертый - не требуется задавать информацию о том, где и как запускать порождаемые процессы;
    Пятый - предыдущие аргументы рассматриваются для рутового(нулевого) процесса программы мастера;
    Шестой - интеркоммуникатор, содержащий группу порожденных процессов (дескриптор);
    Седьмой - интеркоммуникатор между первичной и вновь порожденной группой (дескриптор);
    Восьмой - один код на процесс (массив целых).
    */


    /*Получаем номера первого и второго процессов от программы slave с помощью интеркоммуникатора*/
    MPI_Recv(&rank1, 1, MPI_INT, 0, 0, intercomm, &status);
    MPI_Recv(&rank2, 1, MPI_INT, 1, 1, intercomm, &status);
    MPI_Recv(&size, 1, MPI_INT, 2, 3, intercomm, &status);


    /*Выводим полученные номера процессов на экран*/
    printf("Slaves %d and %d are working, number of running processes = %d", rank1, rank2, size);
    MPI_Finalize();
    return 0;
}