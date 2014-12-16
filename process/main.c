#include "functions.h"

int main (int argc, char *argv[]) {

    struct mq_attr attr;
    char* token;
    mqd_t cola;
    char myqueue[16] = "/myqueue";
    char buffer[256];
    char country[24];
    char state[24];
    char temperature[6];
    char humidity[5];
    char update[4];

    char * aux;

    long int date;
    long int now;
    char query[256];


 	if ((cola = mq_open(myqueue, O_RDONLY)) < 0) {
		perror("mq_open");
	}
		mq_getattr(cola,&attr); 	/*Attributes*/

    	while (mq_receive(cola, buffer, attr.mq_msgsize,0) > 0) {
    		printf("Received: %s\n", buffer); 
         	
			aux = strtok(buffer, "-");
				strcpy(country,aux);
				printf("country:%s \n",country);

			aux = strtok(NULL, "-");
				strcpy(state,aux);
				printf("state:%s \n",state);

			aux = strtok(NULL, "-");
				strcpy(temperature,aux);
				printf("temp:%s \n",temperature);

			aux = strtok(NULL, "-");
				strcpy(humidity,aux);
				printf("humidity:%s \n",humidity);

			aux = strtok(NULL,"-");
				strcpy(update,aux);
				printf("UPDATE = %s\n",update);

        	/*Timestamp*/
			struct timeval tv;
			gettimeofday(&tv, NULL);   
			now = tv.tv_sec;            

			date = now;
			printf("timestamp:%ld \n",date);

			
			if (strstr(update,"yes")) {
			/*Update query*/
			sprintf(query, "UPDATE weather SET temperature=%s, humidity=\"%s\", date=%ld WHERE country=\"%s\" and state=\"%s\";",temperature, humidity, date, country, state);
			printf("CONSULTA: %s\n",query);
			sqlQuery(query);
			}
			else { 
			/*Insert query*/
	 		sprintf(query,"INSERT INTO weather (country, state, temperature, humidity, date) VALUES (\"%s\", \"%s\", %s, \"%s\", %ld);",country, state, temperature, humidity, date);
			printf("CONSULTA: %s\n",query);
			sqlQuery(query);
			}
 		}
    		mq_close(cola);
    		return 0;
}
