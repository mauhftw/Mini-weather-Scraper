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
#include <mqueue.h>


void  scraper(const char* url, const char* filename);    /*scrap data from yahoo*/
char* locationId(char* country, char* state);			 /*search WOEID*/
char* temperature();                                     /*search temperature*/
char* humidity();										 /*search humidity*/
int   checkSql(char* country, char* state);              
float toCentigrade(char*);                              
int   writequeue(char* country, char* state, float temperature, char* humidity, char* update); /*Writing to queue*/  
MYSQL_RES* sqlQuery (char* query);                       
char* filter(char* state);

#endif


