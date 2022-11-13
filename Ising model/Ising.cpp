#include <iostream>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <cmath>
#include <ctime>
using namespace std;


//заполнение массива спинов единицами и вывод их на экран
void array(int n, int **arr)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			arr[i][j]=1;
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
}


//определение соседей у случайно выбранных спинов с учетом граничных условий
void sosedi(int i, int j, int n, int *s, int **arr)
{
	if(i==0)
    {
    	s[0]=arr[n-1][j];
    }
    else
    {
	    s[0]=arr[i-1][j];
    }
    if(i==n-1)
    {
    	s[1]=arr[0][j];
    }
    else
    {
	    s[1]=arr[i+1][j];
    }
    if(j==0)
    {
	    s[2]=arr[i][n-1];
    }
    else
    {
	    s[2]=arr[i][j-1];
    }
    if(j==n-1)
    {
	    s[3]=arr[i][0];
    }
    else
    {
	    s[3]=arr[i][j+1];
    }
}


//вычислить энергию одного спина
double e1sp(int i, int j, int n, int **arr)
{
    double sum=0.0;
    int s[4];
    sosedi(i, j, n, s, arr);
    for(int a=0; a<4; a++)
    {
    	sum+=arr[i][j]*s[a];
    }
    return (-1)*sum;
}


//вычисление полной энергии системы
double poles(int n, int **arr)
{
	double sum=0.0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			sum+=e1sp(i, j, n, arr);
		}
	}
	return sum/(n*n);
}


//вычисление средней энергии на 1 спин
double sreden(int n, int **arr)
{
	return poles(n, arr)/(n*n);
}


//вычисление намагниченности M всей системы
double namag(int n, int **arr)
{
	double sum=0.0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			sum+=arr[i][j];
		}
	}
	return fabs(sum/(n*n));
}


//рассчет теплоемкости системы
double tepl(double Esum1, double Esum2, double T){
	double Esr=0.0, Esrkv=0.0;
    Esr=Esum1/10;
    Esrkv=Esum2/10;
    double t=(Esrkv-(Esr*Esr))/(T*T);
    return t;
}


//рассчет ошибки эксперимента
double er(double *xi, double x){
    double sum=0.0;
    for (int i=0; i<10; i++)
	{
        sum+=(xi[i]-x)*(xi[i]-x);
    }
    double m=sum*0.11111111111;
    return sqrt(m);
}


int main()
{
	int n=0;
	ofstream Ef, Mf, Cf;
	cout<<"Vvedite n:";
	cin>>n;
	cout<<endl;
	int **arr=new int *[n];
	for (int i=0; i<n; i++)
	{
		arr[i]=new int[n];
	}
	array(n, arr);
	cout<<endl;
	int i=rand()%n;
	int j=rand()%n;
	cout<<"Energia vibrannogo spina="<<e1sp(i, j, n, arr)<<endl;
	cout<<"Energia vsey sistemi="<<poles(n, arr)<<endl;
	cout<<"Namagnichennost vsey sistemi="<<namag(n, arr)<<endl;
	sreden(n, arr);
    Ef.open("Efull.txt");
	Mf.open("M.txt");
	Cf.open("C.txt");


//метод Монте-Карло с помощью алгоритма Метрополиса
	for(double T = 0.01; T<4; T+=0.1)
	{
		double Efull=0.0;
		double Esum1=0.0;
		double Esum2=0.0;
		double Msum=0.0;
		double C=0.0;
	    double Est[1000]; 
		double Mst[1000];
		for(int i=0; i<1000; i++)
		{
			for(long int MK=0; MK<100000; MK++)
			{
				double E1=0.0, E2=0.0, p=0.0, slch=0.0;
	        	int i=rand()%n;
	            int j=rand()%n;
	            E1=e1sp(i, j, n, arr);
	            arr[i][j]=(-1)*arr[i][j];
	            E2=e1sp(i, j, n, arr);
	            if(E2>=E1)
	            {
	            	p=exp(((-1)*(E2-E1))/T);
		            slch=(double)rand()/(double)RAND_MAX;
	            	if(slch>p)
	            	{
	            		arr[i][j]=(-1)*arr[i][j];
		    		}
		    	}			 
		    }
		    Efull=poles(n, arr);
            Esum1+=Efull;
            Esum2+=(Efull*Efull);
            Msum+=namag(n, arr);
            Est[i]=Efull;
            Mst[i]=namag(n, arr);
		}
		Esum1/=1000;
		Esum2/=1000;
		Msum/=1000;


//вывод на экран значения температуры, энергии всей системы, намагниченности всей системы и теплоемкости
		cout<<"T="<<T<<endl;
		cout<<"E(T)="<<Esum1<<endl;
		Ef<<T<<"\t"<<Esum1<<"\t"<<er(Est, Esum1)<<endl;
		cout<<"M(T)="<<Msum<<endl;
		Mf<<T<<"\t"<<Msum<<"\t"<<er(Mst, Msum)<<endl;
		C=tepl(Esum1, Esum2, T);
		cout<<"C(T)="<<C<<endl;
		Cf<<T<<"\t"<<C<<endl;
		Esum1=0;
		Esum2=0;
		Msum=0;
	}


    for(int i=0; i<n; i++)
	{
		delete[] arr[i];	
	} 
    delete[] arr;
    Ef.close();
    Mf.close();
    Cf.close();
}
