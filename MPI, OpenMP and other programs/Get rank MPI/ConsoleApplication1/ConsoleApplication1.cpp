#include <iostream>
#include <stdio.h>
#include <mpi.h>

using namespace std;

int main(int argc, char* argv[]) {
	MPI_Init(&argc, &argv);
	int rank, n, i, message;
	double time_start, time_finish;
	MPI_Status status;
	MPI_Comm_size(MPI_COMM_WORLD, &n);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	time_start = MPI_Wtime();


	//получить и вывести на экран сообщение, полученное от другого процесса, если ранг текущего процесса = 7
	if (rank == 7)
	{
		cout << "Hello from process " << rank << "\n";
		for (i = 0; i < n - 1; i++) {
			MPI_Recv(&message, 1, MPI_INT, MPI_ANY_SOURCE,
				MPI_ANY_TAG, MPI_COMM_WORLD, &status);
			cout << "Hello from process " << message << " " << message * message << endl;
		}
	}


	else MPI_Send(&rank, 1, MPI_INT, 7, 7, MPI_COMM_WORLD);
	time_finish = MPI_Wtime();
	MPI_Finalize();
	return 0;
}
