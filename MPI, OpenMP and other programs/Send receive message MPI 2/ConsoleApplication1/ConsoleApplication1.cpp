#include <iostream>
#include <mpi.h>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	int a[1];
	a[0] = 1;
	int g = 1;
	int n, rank;
	int m;
	int b[1];
	double start_time1;
	double finish_time1;
	double start_time2;
	double finish_time2;
	MPI_Init(&argc, &argv);
	MPI_Status status;
	MPI_Comm_size(MPI_COMM_WORLD, &n);
	int k = n / 2;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	start_time1 = MPI_Wtime();


	//получение и отправка сообщений
	while (k > 0)
	{
		if (rank >= k && rank < k * 2)
		{
			MPI_Send(&a, g, MPI_INT, rank - k, 0, MPI_COMM_WORLD);
		}
		if (rank < k)
		{
			MPI_Recv(&m, g, MPI_INT, rank + k, 0, MPI_COMM_WORLD, &status);
			a[0] += m;
			cout << a[0] << endl;
		}
		k /= 2;
	}


	finish_time1 = MPI_Wtime();
	if (rank == 0)
	{
		cout << "Summa= " << a[0] << endl;
		cout << "Vremya while= " << finish_time1 - start_time1 << " sekund" << endl;
	}
	a[0] = 1;
	start_time2 = MPI_Wtime();
	MPI_Reduce(&a, &b, g, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	finish_time2 = MPI_Wtime();
	if (rank == 0)
	{
		cout << "Summa(Reduce)= " << b[0] << endl;
		cout << "Vremya Reduce= " << finish_time2 - start_time2 << " sekund" << endl;
	}
	MPI_Finalize();
	return 0;
}