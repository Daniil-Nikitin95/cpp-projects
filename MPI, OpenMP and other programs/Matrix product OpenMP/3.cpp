#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]){
	
	
	//последовательная область
system("chcp 1251");
srand(time(NULL));
//Размер матриц:
int N=atoi(argv[1]);
//Индексные переменные:
int i,j,k;
double start_time, end_time, tick;
double omp_get_wtime(void);
cout << "Kolichestvo elementov v stroke/stolbze " << N << endl;
//Первая матрица:
int A[N][N];
//Вторая матрица:
int B[N][N];
//Третья матрица (результат):
int C[N][N];


//Ввод элементов первой матрицы:
cout<<"Matrix A:\n";
for(i=0; i < N; i++){
 for(j=0; j < N; j++){
 A[i][j] = rand()%10;
}
}


for(int y=0; y<N; y++){
	for(int u=0; u<N; u++){
		//cout << A[y][u] << " ";
	}
	//cout << endl;
}
cout << endl;


//Ввод элементов второй матрицы:
cout << "Matrix B:\n";
for(i=0; i < N; i++){
 for(j=0; j < N; j++){
 B[i][j] = rand()%10;
}
}


for(int y=0; y<N; y++){
	for(int u=0; u<N; u++){
		//cout << B[y][u] << " ";
	}
	//cout << endl;
}
cout << endl;


//Вычисление произведения матриц:
cout << "Matrix C=AB:\n";
for(int g=1; g<11; g++)
{
start_time = omp_get_wtime();


//параллельная область
#pragma omp parallel num_threads(g) private(i, j, k)
#pragma omp for
for(i=0; i < N; i++){
 for(j=0; j < N; j++){
 C[i][j]=0;
 for(k=0; k < N; k++){
 C[i][j]+=A[i][k]*B[k][j];
 //Вывод значения элемента на экран:
}
}
 //cout << endl;
}


//последовательная область
for(int t=0; t<N; t++){
for(int p=0; p<N; p++){
//cout << C[t][p] << " ";
}
//cout << endl;
}
end_time = omp_get_wtime();
cout << "Nomer niti: " << g << endl;
cout << "Vremya dlya "<< g << " nitei= " << end_time-start_time << ", " << endl;
cout << "Tochnost taimera " << tick;
cout << endl;
}
return 0;
}

