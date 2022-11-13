#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <mysql.h>
#include <ctime>
using namespace std;

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int main(int argc, char **argv) 
{
  std::srand(std::time(0));
  MYSQL *con = mysql_init(NULL);
  MYSQL_ROW row;
  MYSQL_RES *res;
  int qstate;
  int stmins;
  int sthours;
  int j;
  int zap;
  int success=0;
  int lose=0;

  if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }


//подключение к базе данных DATANDO
  con=mysql_real_connect(con, "ubuntuserv", "daniil2", "d170895", "DATANDO", 0, NULL, 0);


  if (con)
  {
    if(!mysql_autocommit(con,1))
    {
	cout<<"AUTOCOMMIT SUCCESSFULLY SET TO 1"<<endl;
    }
    else
    {
	cout<<"AUTOCOMMIT NOT SET TO 1"<<endl;
    }
    for(int i=1; i<=6; i++)
    {
      if(i==1 || i==3 || i==5)
      {
        if(i==1)
	{
	  j=1;
          zap=100000;
	}
	if(i==3)
	{
	  j=200001;
	  zap=300000;
	}
	if(i==5)
	{
	  j=400001;
	  zap=500000;
	}
        int mins=0;
        
        
    //добавление записей в таблицу SDATA для температурных датчиков
	for(; j<=zap; j++)
	{
          float temp,mint,maxt;
          mint=20.0;
          maxt=39.0;
          char query[260];
          temp=(float)(rand())/RAND_MAX*(maxt-mint)+mint;
          mins+=1+rand()%(7-1);
          sprintf(query, "INSERT INTO SDATA (id,SMC_P_CROSS_FK,DatTime,SensorValue) VALUES(%d,%d,(SELECT DATE_ADD('2021-12-31 10:54:28.000000', INTERVAL %d MINUTE)),%f)", j, i, mins, temp);

          cout<<"query is :" <<query<<endl;
          qstate = mysql_query(con,query);

          if (!qstate)
          {
               cout<<"record inserted successfully"<<endl;
               success++;
          }
          else
          {
               cout<<"query problem"<<mysql_error(con)<<endl;
               lose++;
          }
      	}
      }


      if(i==2 || i==4 || i==6)
      {
        if(i==2)
	{
	  j=100001;
	  zap=200000;
	}
	if(i==4)
	{
	  j=300001;
	  zap=400000;
	}
	if(i==6)
	{
	  j=500001;
	  zap=600000;
	}
        int mins=0;
        
        
    //добавление записей в таблицу SDATA для датчиков электрического напряжения
	for(; j<=zap; j++)
	{
          float volt,minv,maxv;
          minv=207.0;
          maxv=253.0;
          char query[260];
          volt=(float)(rand())/RAND_MAX*(maxv-minv)+minv;
          mins+=1+rand()%(7-1);
          sprintf(query, "INSERT INTO SDATA (id,SMC_P_CROSS_FK,DatTime,SensorValue) VALUES(%d,%d,(SELECT DATE_ADD('2021-12-31 10:54:28.000000', INTERVAL %d MINUTE)),%f)", j, i, mins, volt);

          cout<<"query is :" <<query<<endl;
          qstate = mysql_query(con,query);

          if (!qstate)
          {
               cout<<"record inserted successfully"<<endl;
               success++;
          }
          else
          {
               cout<<"query problem"<<mysql_error(con)<<endl;
               lose++;
          }
      	}
      }
      
      
      //printf("Records added: %ld, mysql_affected_rows(con));
    }
    
    
    //вывод количества записей, добавленных в таблицу SDATA, вывод количества успешно добавленных записей и количества не добавленных записей
    printf("Records added: %ld", mysql_affected_rows(con));
    cout<<"amount of successes= "<<success<<", amount of loses= "<<lose<<endl; 


  }
  mysql_close(con);
  exit(0);
}


