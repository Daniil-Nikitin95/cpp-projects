#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <ctime>
using namespace std;


//заполнение массива спинов единицами и вывод их на экран
double array(int n, double **arr, double Pi)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			arr[i][j]=(double(rand())/RAND_MAX)*(2*Pi)-Pi;
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
}


//определение соседей у случайно выбранных спинов с учетом граничных условий
double sosedi(int i, int j, int n, double *s, double **arr)
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
double e1sp(int i, int j, int n, double *s, double **arr)
{
    double sum=0.0;
    sosedi(i, j, n, s, arr);
    for(int a=0; a<4; a++)
    {
    	sum+=cos(arr[i][j]-s[a]);
    }
    return (-1)*sum;
}


//вычисление полной энергии системы
double poles(int n, double *s, double **arr)
{
	double sum=0.0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			sum+=e1sp(i, j, n, s, arr);
		}
	}
	return sum/(n*n);
}


//вычисление средней энергии на 1 спин
double sreden(int n, double *s, double **arr)
{
	return poles(n, s, arr)/(n*n);
}


//вычисление среднеквадратичной намагниченности M всей системы
double srkvmag(int n, double **arr)
{
	double sum1=0.0;
	double sum2=0.0;
	double kvs1=0.0;
	double kvs2=0.0;
	double skv=0.0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			sum1+=sin(arr[i][j]);
			sum2+=cos(arr[i][j]);
		}
	    kvs1=sum1*sum1;
	    kvs2=sum2*sum2;
	    skv=kvs1+kvs2;
	}
	return fabs(skv/(n*n*n*n));
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

//вывод в файл координат спина; расчет и вывод в файл компонентов вектора спина
void Fillf(int n, double **arr, int dec) {
	int bin = 0;
	double t1, t2;
	bin = dec + 1000;
	ostringstream ostr; //output string stream
	ostr << bin;
	string s = ostr.str();
	ofstream ofs("conf-" + s + ".txt");
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			t1 = cos(arr[x][y]);
			t2 = sin(arr[x][y]);
			ofs << x << "\t" << y << "\t" << "0" << "\t" << t1 << "\t" << t2 << "\t" << "0" << endl;
		}
	}
	ofs.close();
}

int main()
{
	int n=0, g=0;
	double Pi=3.141592;
	ofstream Ef, Mf, Cf;
	cout<<"Vvedite n:";
	cin>>n;
	cout<<endl;
	double **arr=new double *[n];
	for (int i=0; i<n; i++)
	{
		arr[i]=new double[n];
	}
	array(n, arr, Pi);
	cout<<endl;
	int i=rand()%n;
	int j=rand()%n;
	double s[4];
	cout<<"Energia vibrannogo spina="<<e1sp(i, j, n, s, arr)<<endl;
	cout<<"Energia vsey sistemi="<<poles(n, s, arr)<<endl;
	cout<<"Namagnichennost vsey sistemi="<<srkvmag(n, arr)<<endl;
	sreden(n, s, arr);
    Ef.open("Efull.txt");
	Mf.open("M.txt");
	Cf.open("C.txt");
	
	
	//Метод Монте-Карло
	for(double T = 0.01; T<4; T+=0.1)
	{
		double Efull=0.0;
		double Esum1=0.0;
		double Esum2=0.0;
		double Msum=0.0;
		int null=0;
		double C=0.0;
	    double Est[10]; 
		double Mst[10];
		g++;
		for(int step=0; step<10; step++)
		{
			for(long int MK=0; MK<1000000; MK++)
			{
				double E1=0.0, E2=0.0, p=0.0, slch=0.0;
	        	int i=rand()%n;
	            int j=rand()%n;
	            E1=e1sp(i, j, n, s, arr);
	            arr[i][j]=(-1)*arr[i][j];
	            E2=e1sp(i, j, n, s, arr);
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
		    Efull=poles(n, s, arr);
            Esum1+=Efull;
            Esum2+=(Efull*Efull);
            Msum+=srkvmag(n, arr);
            Est[step]=Efull;
            Mst[step]=srkvmag(n, arr);
		}
		Esum1/=10;
		Esum2/=10;
		Msum/=10;
		
		
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
		Fillf(n, arr, g);
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
