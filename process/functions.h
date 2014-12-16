/*Function definition*/

#ifndef _FUNCTIONS_H_
	#define _FUNCTIONS_H_

	#include <unistd.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdio.h>
	#include <assert.h>
	#include <time.h>
	#include <mysql.h>
	#include <my_global.h>
	#include <sys/time.h>
	#include <mqueue.h>

														 
int   checkSql(char* country, char* state);              /*Verify register stored in DB*/
MYSQL_RES* sqlQuery (char* query);                       /*Make query*/

#endif


