#include <iostream>
#include <cstdlib>
#include "mpi.h"
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
	srand(time(NULL));
	//Размер матриц:
	const int N = 500;
	//Индексные переменные:
	int i, j, k;
	int size, rank;
	double start_time, finish_time;
	MPI_Init(&argc, &argv);
	MPI_Status status;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	//инициализация матрицы каждым процессом:
	cout << "Kolichestvo elementov v stroke/stolbze " << N << endl;
	//Первая матрица:
	int A[N][N];
	//Вторая матрица:
	int B[N][N];
	//Третья матрица (результат):
	int C[N][N];


	//Ввод элементов первой матрицы:
	cout << "Matrix A:\n";
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			A[i][j] = rand() % 10;
		}
	}
	for (int y = 0; y < N; y++) {
		for (int u = 0; u < N; u++) {
			//cout << A[y][u] << " ";
		}
		//cout << endl;
	}
	cout << endl;


	//Ввод элементов второй матрицы:
	cout << "Matrix B:\n";
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			B[i][j] = rand() % 10;
		}
	}
	for (int y = 0; y < N; y++) {
		for (int u = 0; u < N; u++) {
			//cout << B[y][u] << " ";
		}
		//cout << endl;
	}
	cout << endl;
	MPI_Barrier(MPI_COMM_WORLD); //барьерная синхронизация процессов
	start_time = MPI_Wtime();//начало замера времени для каждого процесса


	//перемножение матриц:
	cout << "Matrix C=AB:\n";
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			C[i][j] = 0;
			for (k = 0; k < N; k++) {
				C[i][j] += A[i][k] * B[k][j];
				//Вывод значения элемента на экран:
			}
		}
		//cout << endl;
	}
	for (int t = 0; t < N; t++) {
		for (int p = 0; p < N; p++) {
			//cout << C[t][p] << " ";
		}
		//cout << endl;
	}
	finish_time = MPI_Wtime();//конец замера времени
	cout << "Vremya vipolnenia peremnojenia matriz na kajdom processe= " << finish_time - start_time << endl;//вывод время выполнения перемножения матриц на каждом процессе
	MPI_Finalize();
}