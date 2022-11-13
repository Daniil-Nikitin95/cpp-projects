#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <locale.h>
#include <fstream>
using namespace std;


// Метод срединных квадратов
void srkv(double *r, int *x, int size, int M, int n){ 
	ofstream srkv; // создание файловой переменной
	srkv.open("srkv.txt"); // открытие файла
	int Mn = pow(M,n); //расчет переменной
	r[0] = x[0]; //расчет r 0-го;
	r[0] /= Mn; //расчет r 0-го;
	cout << "r" << "\t" << "x" << "\t" << "M = " << M << "\t" << "n = " << n << endl; //столбцы на экране
	srkv << "r" << "\t" << "x" << "\t" << "M = " << M << "\t" << "n = " << n << endl; //столбцы в файле
	cout << r[0] << "\t" << x[0] << endl; //вывод r 0-го на экран
	srkv << r[0] << "\t" << x[0] << endl; //запись r 0-го в файл
	for (int i = 1; i < size; i++){ // расчет в цикле
		x[i] = (x[i-1] * x[i-1]) / pow(M,(n/2)); //расчет x i-го;
		x[i] %= Mn; //расчет x i-го;
		r[i] = x[i]; //расчет r i-го;
		r[i] /= Mn; //расчет r i-го;
		cout << r[i] << "\t" << x[i] << endl; //вывод на экран
		srkv << r[i] << "\t" << x[i] << endl; //сохранение в файл
	}
	srkv.close(); //закрытие файла
}


//Метод срединных произведений
void srpr(double *r, int *x, int size, int M, int n){ 
	ofstream srpr;
	srpr.open("srpr.txt");
	int Mn = pow(M,n);
	r[0] = x[0];
	r[0] /= Mn;
	r[1] = x[1];
	r[1] /= Mn;
	cout << "r" << "\t" << "x" << "\t" << "M = " << M << "\t" << "n = " << n << endl;
	srpr << "r" << "\t" << "x" << "\t" << "M = " << M << "\t" << "n = " << n << endl;
	cout << r[0] << "\t" << x[0] << endl;
	srpr << r[0] << "\t" << x[0] << endl;
	cout << r[1] << "\t" << x[1] << endl;
	srpr << r[1] << "\t" << x[1] << endl;
	for (int i = 2; i < size; i++){
		x[i] = (x[i-1] * x[i-2]) / pow(M,(n/2));
		x[i] %= Mn;
		r[i] = x[i];
		r[i] /= Mn;
		cout << r[i] << "\t" << x[i] << endl;
		srpr << r[i] << "\t" << x[i] << endl;
	}
	srpr.close(); //закрытие файла
}


//Метод перемешивания
void perem(double *r, int *x, int size, int M, int n){ 
	ofstream perem;
	perem.open("perem.txt");
	int Mn = pow(M,n);
	int MX1 = pow(M,((3 * n) / 4));
	int MX2 = pow(M,(n / 4));
	r[0] = x[0];
	r[0] /= Mn;
	cout << "r" << "\t\t" << "x" << "\t\t" << "M = " << M << "\t" << "n = " << n << endl;
	perem << "r" << "\t\t" << "x" << "\t\t" << "M = " << M << "\t" << "n = " << n << endl;
	cout << r[0] << "\t" << x[0] << endl;
	perem << r[0] << "\t" << x[0] << endl;
	int X1, X2;
	for (int i = 1; i < size; i++){
		X1 = (x[i - 1] % MX1) * MX2 + (x[i - 1] / MX1); //смещение влево
		X2 = (x[i - 1] % MX2) * MX1 + (x[i - 1] / MX2); //смещение вправо
		x[i] = X1 + X2;
		x[i] %= Mn;
		r[i] = x[i];
		r[i] /= Mn;
		cout << r[i] << "\t" << x[i] << "\t" << X1 << "\t" << X2 << endl;
		perem << r[i] << "\t" << x[i] << endl;
	}
	perem.close(); //закрытие файла
}


//Линейный конгруэнтный метод
void lin(double *r, int size, int a, int b, int M){ 
	ofstream lin;
	lin.open("lin.txt");
	cout << "r" << "\t" << "a = " << a << "\t" << "b = " << b << "\t" << "M = " << M << endl;
	lin << "r" << "\t" << "a = " << a << "\t" << "b = " << b << "\t" << "M = " << M << endl;
	cout << r[0] << endl;
	lin << r[0] << endl;
	int ri;
	for (int i = 1; i < size; i++){
		ri = a * r[i - 1] + b;
		r[i] = ri % M; //расчет по конгруэнтной формуле
		cout << r[i] << endl;
		lin << r[i] << endl;
	}
	lin.close(); //закрытие файла
}


int main(void){
	
	
	//русская локализация
	SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "rus"); 
    
    
	int c=0;
	
	
	//Далее идет меню команд:
	cout << "0) Выход из программы" << endl; 
	cout << "1) Метод срединных квадратов" << endl; 
	cout << "2) Метод срединных произведений" << endl; 
	cout << "3) Метод перемешивания" << endl; 
	cout << "4) Линейный конгруэнтный метод" << endl; 
	cout << "5) Генератор встроенной функции random(x)" << endl; 
	do{ 
	cout << "Выберите один из методов: ";
	cin >> c;
	
	
	//защита от неправильного ввода
	if (c < 0 || c > 5){ 
			cout << "Неверный ввод, повторите попытку" << endl;
			continue;
		}
		
		
		// реализация меню
		switch (c) 
		{
			
			
			//Метод срединных квадратов
		case 1: 
		{
			int size;
			do{ 
				cout << "Введите количество случайных числел, которое вы хотите получить: ";
				cin >> size;
			}while (size < 1); //защита от неправильного ввода
			size++;
			double *r = new double[size];
			int *x = new int[size];
			int M = 10; //основание
			int n; //разрядность
			do{ 
				cout << "Введите четную разрядность (например 4): ";
				cin >> n;
			}while ((n % 2) != 0); //защита от неправильного ввода
			do{ //защита от неправильного ввода
				cout << "Введите случайное число x, имеющее четную разрядность = " << n << " (например 2134): ";
				cin >> x[0];
			}while (x[0] < pow(M,n-1) || x[0] >= pow(M,n)); 
			srkv(r, x, size, M, n); //вызов функции
			cout << "Результат сохранен в файл srkv.txt" << endl << endl;
			break;
		}
		
		
		//Метод срединных произведений
		case 2:
			{
				int size;
				do{ //защита от неправильного ввода
					cout << "Введите количество случайных числел, которое вы хотите получить: ";
					cin >> size;
				}while (size < 1); 
				size += 2;
				double *r = new double[size];
				int *x = new int[size];
				int M = 10; //основание
				int n = 4; //разрядность
				do{ 
					cout << "Введите четную разрядность (например 4): ";
					cin >> n;
				}while ((n % 2) != 0); //защита от ошибочного ввода
				do{ 
					cout << "Введите случайное число X1, имеющее четную разрядность = " << n << " (например 2134): ";
					cin >> x[0];
				}while (x[0] < pow(M,n-1) || x[0] >= pow(M,n)); //защита от неправильного ввода
				do{ 
					cout << "Введите случайное число X2, имеющее четную разрядность = " << n << " (например 4268): ";
					cin >> x[1];
				}while (x[1] < pow(M,n-1) || x[1] >= pow(M,n)); //защита от неправильного ввода
				srpr(r, x, size, M, n); //вызов функции
				cout << "Результат сохранен в файл srpr.txt" << endl << endl;
				break;
			}
			
			
			//Метод перемешивания
		case 3:
			{
				int size;
				do{ //защита от неправильного ввода
					cout << "Введите количество случайных числел, которое вы хотите получить: ";
					cin >> size;
				}while (size < 1); 
				size++;
				double *r = new double[size];
				int *x = new int[size];
				int M = 10; //основание
				int n = 4; //разрядность
				do{ 
					cout << "Введите четную разрядность кратную 4 (например 8): ";
					cin >> n;
				}while ((n % 4) != 0); //защита от неправильного ввода
				do{ 
					cout << "Введите случайное число X1, имеющее четную разрядность: " << n << " (например 21344268): ";
					cin >> x[0];
				}while (x[0] < pow(M,n-1) || x[0] >= pow(M,n)); //защита от неправильного ввода
				perem(r, x, size, M, n); //вызов функции
				cout << "Результат сохранен в файл perem.txt" << endl << endl;
				break;
			}
			
			
			//Линейный конгруэнтный метод
		case 4:
			{
				int M;
				int a, b;
				int size;
				do{ //защита от неправильного ввода
					cout << "Введите количество случайных числел, которое вы хотите получить: ";
					cin >> size;
				}while (size < 1); 
				size++;
				double *r = new double[size];
				do{ 
					cout << "Введите верхнюю границу M (должен быть достаточно большим, M > 1000): ";
					cin >> M;
				}while (M < 1000); //защита от неправильного ввода
				b = 0.21132 * M;
				do{ 
					cout << "Введите верхнюю границу 'a' из интервала от " << int(M/100) << " до " << int(M - sqrt(M)) << " и с условием, что (a % 8) == 5: ";
					cin >> a;
				}while ((a <= M/100 || a >= (M - sqrt(M))) && ((a % 8) != 5)); //защита от неправильного ввода
				cout << "Введите случайное число r (например 1): ";
				cin >> r[0];
				lin(r, size, a, b, M); //вызов функции
				cout << "Результат сохранен в файл lin.txt" << endl << endl;
				break;
			}
			
			
			//Генератор встроенной функции random(x)
			case 5: 
			{ 
				int size;
				do{ //защита от неправильного ввода
					cout << "Введите количество случайных числел, которое вы хотите получить: ";
					cin >> size;
				}while (size < 1); 
				int M;
				do{ 
					cout << "Введите верхнюю границу M (должен быть достаточно большим, M > 1000): ";
					cin >> M;
				}while (M < 1000); //защита от неправильного ввода
				ofstream Cgener;
				Cgener.open("Cgener.txt");
				Cgener << "r" << endl;
				int RAND;
				for (int i = 0; i < size; i++){
					RAND = rand() % M;
					cout << RAND << endl;
					Cgener << RAND << endl;
				}
				Cgener.close(); //закрытие файла
				cout << "Результат сохранен в файл Cgener.txt" << endl << endl;
				break;
			}
	    }
	}while(c != 0); //условие выхода 
	cout << "Программа завершена ";
	system("pause"); //пауза
	return 0;
}
