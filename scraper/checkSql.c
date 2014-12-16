#include "functions.h"


int checkSql (char *country, char* state) {

	MYSQL_RES* res;
	MYSQL_ROW row;
    int i;
	long int now;
	int dbtime;


	char consulta[512];
	bzero(consulta,sizeof(consulta));
	sprintf(consulta,"SELECT * FROM weather WHERE state=\'%s\' and country=\'%s\';", state, country);
	printf ("LA CONSULTA: %s \n",consulta);

/*Timestamp*/
	struct timeval tv;
    gettimeofday(&tv, NULL);    
    now = tv.tv_sec;            
   
    
res = sqlQuery(consulta); 	


if ((row = mysql_fetch_row(res)) != NULL) {
		
		dbtime=atoi(row[5]);     
		/*Checks if register is older than 1 hour*/
			if ((now - dbtime) >= 3600) {      
 				printf ("Old register, need to update\n");
 				return -1;

			} 
			else {
				printf ("The stored register is valid\n");	
				return 0;
			}

	  }
		
else {
	printf("Can't find register!\n");	
	return -2;
  }

}
