#include "functions.h"

MYSQL_RES* sqlQuery(char* query){

    MYSQL *conn;
	MYSQL_RES* res;
	MYSQL_ROW row;

	char *server = "127.0.0.1";
	char *user = "root";
	char *password = "root"; /* set me first */
	char *database = "weather";
	conn = mysql_init(NULL);
	
 
	/* Connect to database */
	if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0)) {
	fprintf(stderr, "%s\n", mysql_error(conn));
	exit(1);
	}
   
	/* send SQL query */
	if (mysql_query(conn, query)) {
	fprintf(stderr, "%s\n", mysql_error(conn));   //si no encuentro la query
	exit(1);
	}
   
	res=mysql_store_result(conn);
	mysql_close(conn);

 
   return res;
 
}
