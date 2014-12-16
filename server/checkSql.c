#include "functions.h"

int checkSql (int sock, char *country, char* state, char* parameter) {

	MYSQL_RES* res;
	MYSQL_ROW row;
    int i, n;
    char answer[512];
    char consulta[512];
    char symbol[4];
    char color[8];
    char header200[128] = "HTTP/1.1 200 OK\r\n Content-Type: text/html; charset=UTF-8\r\n\r\n";
    char header404[128] = "HTTP/1.1 404 NOT FOUND\r\n Content-Type: text/html; charset=UTF-8\r\n\r\n";
	char error[128] = "<!DOCTYPE html><html><body><h1>Not Found</h1></body></html>\n";

	bzero(answer,sizeof(answer));
	bzero(consulta,sizeof(consulta));
    bzero(symbol,sizeof(symbol));
    bzero(color,sizeof(color));


if(strncmp(parameter,"Temperature",12) == 0) {
	sprintf(consulta,"SELECT temperature FROM weather WHERE state=\'%s\' and country=\'%s\';", state, country);
	printf ("LA CONSULTA: %s \n",consulta);
	strncpy(symbol,"C",1);
	strncpy(color,"red",4);
} 
else if (strncmp(parameter,"Humidity", sizeof(parameter)) == 0) {
	sprintf(consulta,"SELECT humidity FROM weather WHERE state=\'%s\' and country=\'%s\';", state, country);
	printf ("LA CONSULTA: %s \n",consulta);
	strncpy(symbol,"",2);
	strncpy(color,"blue",5);
}
else {
	n = send(sock,header404, strlen(header404),0);						
	n = send(sock,error, strlen(error),0);
	if (n < 0){
        perror("ERROR: writing to socket");
        exit(1);
        }
        
	return 0;
}
/*Check register*/    
res = sqlQuery(consulta); 	


if ((row = mysql_fetch_row(res)) != NULL) {
		
		sprintf(answer,"<!DOCTYPE html><html><body><p>The current %s in %s is:<font color=\'%s\'> %s %s</font></p></body></html>\n",parameter,state,color,row[0],symbol);
		n = send(sock,header200, strlen(header200),0);
		n = send(sock,answer, strlen(answer),0);
		if (n < 0){
                perror("ERROR: writing to socket");
                exit(1);
                }
          return 0;      
		    		
	  }
		
else {
	printf("Register isn't in DB\n");	
	n = send(sock,header404, strlen(header404),0);
	n = send(sock,error, strlen(error),0);
	if (n < 0){
                perror("ERROR: writing to socket");
                exit(1);
                }
      return 0;          
	
  }
}
