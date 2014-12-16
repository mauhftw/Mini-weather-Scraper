/*Definicion de funciones*/

#ifndef _FUNCTIONS_H_
	#define _FUNCTIONS_H_

	#include <fcntl.h>
	#include <sys/stat.h>
	#include <sys/types.h>
	#include <unistd.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <curl/curl.h>
	#include <assert.h>
	#include <ctype.h>
	#include <time.h>
	#include <mysql.h>
	#include <my_global.h>
	#include <sys/time.h>
	#include <sys/socket.h>
	#include <arpa/inet.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <pthread.h> 
	#include <semaphore.h>


int checkSql(int sock, char* country, char* state, char* parameter);  
MYSQL_RES* sqlQuery (char* query);                       				
int sockparser(int sock, char* buffer);
void* doprocessing (void* sock);
int serverlog(char* request);
int clientlog(char * addr);
char* filter(char* state);
#endif


