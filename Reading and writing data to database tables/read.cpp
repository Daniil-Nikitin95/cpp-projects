#include <stdio.h>
#include <mysql.h>

void finish_with_error(MYSQL *con) 
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int main(int argc, char **argv) 
{
  printf("Data from DATANDO:");
  for(int i=0; i<6; i++)
  {
    MYSQL *con = mysql_init(NULL);
    if (con == NULL) 
    {
        fprintf(stderr, "mysql_init() failed\n");
    }
    
    
    //����������� � ���� ������ DATANDO
    if (mysql_real_connect(con, "ubuntuserv", "daniil1", "d170895", "DATANDO", 0, NULL, 0) == NULL) 
    {
        finish_with_error(con);
    }
    
    
    //��������� ������ �� ����� �� ����� ���� ������� �� ������� MCU
    if(i==0)
    {
      printf("\n\nMCU:\n");
      if (mysql_query(con, "SELECT * FROM MCU")) 
      {
          finish_with_error(con);
      }
    }
    
    
    //��������� ������ �� ����� �� ����� ���� ������� �� ������� Place
    if(i==1)
    {
      printf("Place:\n");
      if (mysql_query(con, "SELECT * FROM Place")) 
      {
          finish_with_error(con);
      }
    }
    
    
    //��������� ������ �� ����� �� ����� ���� ������� �� ������� SDATA
    if(i==2)
    {
      printf("SDATA:\n");
      if (mysql_query(con, "SELECT * FROM SDATA WHERE id IN (1,2,3)")) 
      {
          finish_with_error(con);
      }
    }
    
    
    //��������� ������ �� ����� �� ����� ���� ������� �� ������� Sensor
    if(i==3)
    {
      printf("Sensor:\n");
      if (mysql_query(con, "SELECT * FROM Sensor")) 
      {
          finish_with_error(con);
      }
    }
    
    
    //��������� ������ �� ����� �� ����� ���� ������� �� ������� SMC_P_CROSS
    if(i==4)
    {
      printf("SMC_P_CROSS:\n");
      if (mysql_query(con, "SELECT * FROM SMC_P_CROSS WHERE id IN (1,2,3)")) 
      {
          finish_with_error(con);
      }
    }
    
    
	//��������� ������ �� ����� �� ����� ���� ������� �� ������� S_M_CROSS
    if(i==5)
    {
      printf("S_M_CROSS:\n");
      if (mysql_query(con, "SELECT * FROM S_M_CROSS WHERE id IN (1,2,3)")) 
      {
          finish_with_error(con);
      }
    }
    
    
    //���� ��������� ����� �������� NULL, �� ������� �� ����� ������
    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) 
    {
       finish_with_error(con);
    }
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    
    
    //����� �� ����� ���� ������
    while ((row = mysql_fetch_row(result))) 
    {
      for(int i = 0; i < num_fields; i++) 
      {
        printf("%s ", row[i] ? row[i] : "NULL");
      }
      printf("\n");
    }
    
    
    printf("\n");
    mysql_free_result(result);
    mysql_close(con);
  }
  exit(0);
}
