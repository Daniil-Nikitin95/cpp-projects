#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <locale.h>
#include <fstream>
using namespace std;


// ����� ��������� ���������
void srkv(double *r, int *x, int size, int M, int n){ 
	ofstream srkv; // �������� �������� ����������
	srkv.open("srkv.txt"); // �������� �����
	int Mn = pow(M,n); //������ ����������
	r[0] = x[0]; //������ r 0-��;
	r[0] /= Mn; //������ r 0-��;
	cout << "r" << "\t" << "x" << "\t" << "M = " << M << "\t" << "n = " << n << endl; //������� �� ������
	srkv << "r" << "\t" << "x" << "\t" << "M = " << M << "\t" << "n = " << n << endl; //������� � �����
	cout << r[0] << "\t" << x[0] << endl; //����� r 0-�� �� �����
	srkv << r[0] << "\t" << x[0] << endl; //������ r 0-�� � ����
	for (int i = 1; i < size; i++){ // ������ � �����
		x[i] = (x[i-1] * x[i-1]) / pow(M,(n/2)); //������ x i-��;
		x[i] %= Mn; //������ x i-��;
		r[i] = x[i]; //������ r i-��;
		r[i] /= Mn; //������ r i-��;
		cout << r[i] << "\t" << x[i] << endl; //����� �� �����
		srkv << r[i] << "\t" << x[i] << endl; //���������� � ����
	}
	srkv.close(); //�������� �����
}


//����� ��������� ������������
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
	srpr.close(); //�������� �����
}


//����� �������������
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
		X1 = (x[i - 1] % MX1) * MX2 + (x[i - 1] / MX1); //�������� �����
		X2 = (x[i - 1] % MX2) * MX1 + (x[i - 1] / MX2); //�������� ������
		x[i] = X1 + X2;
		x[i] %= Mn;
		r[i] = x[i];
		r[i] /= Mn;
		cout << r[i] << "\t" << x[i] << "\t" << X1 << "\t" << X2 << endl;
		perem << r[i] << "\t" << x[i] << endl;
	}
	perem.close(); //�������� �����
}


//�������� ������������ �����
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
		r[i] = ri % M; //������ �� ������������ �������
		cout << r[i] << endl;
		lin << r[i] << endl;
	}
	lin.close(); //�������� �����
}


int main(void){
	
	
	//������� �����������
	SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "rus"); 
    
    
	int c=0;
	
	
	//����� ���� ���� ������:
	cout << "0) ����� �� ���������" << endl; 
	cout << "1) ����� ��������� ���������" << endl; 
	cout << "2) ����� ��������� ������������" << endl; 
	cout << "3) ����� �������������" << endl; 
	cout << "4) �������� ������������ �����" << endl; 
	cout << "5) ��������� ���������� ������� random(x)" << endl; 
	do{ 
	cout << "�������� ���� �� �������: ";
	cin >> c;
	
	
	//������ �� ������������� �����
	if (c < 0 || c > 5){ 
			cout << "�������� ����, ��������� �������" << endl;
			continue;
		}
		
		
		// ���������� ����
		switch (c) 
		{
			
			
			//����� ��������� ���������
		case 1: 
		{
			int size;
			do{ 
				cout << "������� ���������� ��������� ������, ������� �� ������ ��������: ";
				cin >> size;
			}while (size < 1); //������ �� ������������� �����
			size++;
			double *r = new double[size];
			int *x = new int[size];
			int M = 10; //���������
			int n; //�����������
			do{ 
				cout << "������� ������ ����������� (�������� 4): ";
				cin >> n;
			}while ((n % 2) != 0); //������ �� ������������� �����
			do{ //������ �� ������������� �����
				cout << "������� ��������� ����� x, ������� ������ ����������� = " << n << " (�������� 2134): ";
				cin >> x[0];
			}while (x[0] < pow(M,n-1) || x[0] >= pow(M,n)); 
			srkv(r, x, size, M, n); //����� �������
			cout << "��������� �������� � ���� srkv.txt" << endl << endl;
			break;
		}
		
		
		//����� ��������� ������������
		case 2:
			{
				int size;
				do{ //������ �� ������������� �����
					cout << "������� ���������� ��������� ������, ������� �� ������ ��������: ";
					cin >> size;
				}while (size < 1); 
				size += 2;
				double *r = new double[size];
				int *x = new int[size];
				int M = 10; //���������
				int n = 4; //�����������
				do{ 
					cout << "������� ������ ����������� (�������� 4): ";
					cin >> n;
				}while ((n % 2) != 0); //������ �� ���������� �����
				do{ 
					cout << "������� ��������� ����� X1, ������� ������ ����������� = " << n << " (�������� 2134): ";
					cin >> x[0];
				}while (x[0] < pow(M,n-1) || x[0] >= pow(M,n)); //������ �� ������������� �����
				do{ 
					cout << "������� ��������� ����� X2, ������� ������ ����������� = " << n << " (�������� 4268): ";
					cin >> x[1];
				}while (x[1] < pow(M,n-1) || x[1] >= pow(M,n)); //������ �� ������������� �����
				srpr(r, x, size, M, n); //����� �������
				cout << "��������� �������� � ���� srpr.txt" << endl << endl;
				break;
			}
			
			
			//����� �������������
		case 3:
			{
				int size;
				do{ //������ �� ������������� �����
					cout << "������� ���������� ��������� ������, ������� �� ������ ��������: ";
					cin >> size;
				}while (size < 1); 
				size++;
				double *r = new double[size];
				int *x = new int[size];
				int M = 10; //���������
				int n = 4; //�����������
				do{ 
					cout << "������� ������ ����������� ������� 4 (�������� 8): ";
					cin >> n;
				}while ((n % 4) != 0); //������ �� ������������� �����
				do{ 
					cout << "������� ��������� ����� X1, ������� ������ �����������: " << n << " (�������� 21344268): ";
					cin >> x[0];
				}while (x[0] < pow(M,n-1) || x[0] >= pow(M,n)); //������ �� ������������� �����
				perem(r, x, size, M, n); //����� �������
				cout << "��������� �������� � ���� perem.txt" << endl << endl;
				break;
			}
			
			
			//�������� ������������ �����
		case 4:
			{
				int M;
				int a, b;
				int size;
				do{ //������ �� ������������� �����
					cout << "������� ���������� ��������� ������, ������� �� ������ ��������: ";
					cin >> size;
				}while (size < 1); 
				size++;
				double *r = new double[size];
				do{ 
					cout << "������� ������� ������� M (������ ���� ���������� �������, M > 1000): ";
					cin >> M;
				}while (M < 1000); //������ �� ������������� �����
				b = 0.21132 * M;
				do{ 
					cout << "������� ������� ������� 'a' �� ��������� �� " << int(M/100) << " �� " << int(M - sqrt(M)) << " � � ��������, ��� (a % 8) == 5: ";
					cin >> a;
				}while ((a <= M/100 || a >= (M - sqrt(M))) && ((a % 8) != 5)); //������ �� ������������� �����
				cout << "������� ��������� ����� r (�������� 1): ";
				cin >> r[0];
				lin(r, size, a, b, M); //����� �������
				cout << "��������� �������� � ���� lin.txt" << endl << endl;
				break;
			}
			
			
			//��������� ���������� ������� random(x)
			case 5: 
			{ 
				int size;
				do{ //������ �� ������������� �����
					cout << "������� ���������� ��������� ������, ������� �� ������ ��������: ";
					cin >> size;
				}while (size < 1); 
				int M;
				do{ 
					cout << "������� ������� ������� M (������ ���� ���������� �������, M > 1000): ";
					cin >> M;
				}while (M < 1000); //������ �� ������������� �����
				ofstream Cgener;
				Cgener.open("Cgener.txt");
				Cgener << "r" << endl;
				int RAND;
				for (int i = 0; i < size; i++){
					RAND = rand() % M;
					cout << RAND << endl;
					Cgener << RAND << endl;
				}
				Cgener.close(); //�������� �����
				cout << "��������� �������� � ���� Cgener.txt" << endl << endl;
				break;
			}
	    }
	}while(c != 0); //������� ������ 
	cout << "��������� ��������� ";
	system("pause"); //�����
	return 0;
}
