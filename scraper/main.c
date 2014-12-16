#include "functions.h"


int main (int argc, char *argv[]) {
	
  int option, cflag = 0, sflag = 0, isstored = 0, queue = 0;
  int flag = 0; 
  extern char *optarg;
  char url[512];
  char urlWoeid[256];
  char country[64];
  char state[64];
  char stateaux[64];

  char woeidFinal[32];
  char* aux = (char*) malloc (64*sizeof(char));
  char* woeid = (char*) malloc (16*sizeof(char)); 
  char* temp = (char*) malloc (sizeof(char));
  char* hum = (char*) malloc (sizeof(char));
  char update[5];
  float finaltemp;

  bzero(url,sizeof(url));
  bzero(url,sizeof(urlWoeid));
  bzero(woeidFinal,sizeof(woeidFinal));
  bzero(country,sizeof(country));
  bzero(state,sizeof(state));
  bzero(update,sizeof(update));
  bzero(stateaux,sizeof(stateaux));

  
  
  while ((option = getopt (argc, argv, "c:s:"))  >= 0)
      switch (option) {
	case 'c':
		cflag=1;
		strcpy(country,optarg); 	
		break;
	case 's':
		sflag=1;
		strcpy(state,optarg); 
		strcpy(stateaux,optarg);	
		printf("state: %s\n",state);
		break;
	default:		/* ’?’ */
	  printf ("Usage: ./weather [-c ] country [-s] state\n");	
	  return (-1);
		}
			
			if (cflag == 0) {
				printf("-c parameter is missing\n");
				printf ("Usage: ./weather [-c ] country [-s] state\n");
				exit(1);
				}
			if (sflag == 0) {
				printf("-s parameter is missing\n");
				printf ("Usage: ./weather [-c ] country [-s] state\n");
				exit(1);
				}


	if (strstr(state,"%20") != NULL) {			
    	aux = filter(state);
    	printf("AUX: %s\n",aux);
    	strcpy(state,aux);						
    	flag = 1;								

    }


	isstored = checkSql(country,state);  
    if (isstored == -1) {


    if (flag = 1) {
    sprintf(urlWoeid,"http://woeid.rosselliot.co.nz/lookup/%s",stateaux); 
    } else {
    sprintf(urlWoeid,"http://woeid.rosselliot.co.nz/lookup/%s",state);
    }
    printf("URL:%s\n",urlWoeid);
	scraper(urlWoeid, "id.txt");


    woeid = locationId(country, state);
    	if (strstr(woeid,"error")){
    		printf("Error: woeid\n");
    		exit(1);	
    	}	
	printf("WOEID %s\n",woeid);
	strncpy(woeidFinal,woeid,strlen(woeid));


	sprintf(url,"https://weather.yahoo.com/%s/province/province-%s/",country,woeidFinal);
	printf("url: %s\n",url);		
	scraper(url, "request.txt"); 

	temp = temperature();   
	finaltemp = toCentigrade(temp); 
	printf("My temp: %.2f\n",finaltemp);  

	hum = humidity();		
	printf("My humidity es: %s\n",hum);
	
	strncpy(update,"yes",4);
	queue = writequeue (country, state, finaltemp, hum, update);
		if (queue <0) {
			printf("Error: queue\n");
			exit(1);
			}

    	}
    else if (isstored == -2) {  

    if (flag = 1) {
	sprintf(urlWoeid,"http://woeid.rosselliot.co.nz/lookup/%s",stateaux); 
  
    } else {
    sprintf(urlWoeid,"http://woeid.rosselliot.co.nz/lookup/%s",state);	
    }

	scraper(urlWoeid, "id.txt"); 
	printf("state:%s\n",state);
	woeid = locationId(country, state);
	    if (strstr(woeid,"error")){
    		printf("Error: woeid\n");
    		exit(1);	
    	}
	printf("WOEID %s\n",woeid);
	strncpy(woeidFinal,woeid,strlen(woeid));

	sprintf(url,"https://weather.yahoo.com/%s/Province/Province-%s/",country,woeidFinal);
	printf("url: %s\n",url);		
	scraper(url, "request.txt"); 

	temp = temperature();  
	finaltemp = toCentigrade(temp);  
	printf("My temp: %.2f\n",finaltemp);  

	hum = humidity();		
	printf("My humidity: %s\n",hum);
	strncpy(update,"no",3);  
	queue = writequeue (country, state, finaltemp, hum, update);
		if (queue <0) {
			printf("Error: queue\n");
			exit(1);
		}


	}
	else {
	}
 return(0); 
}
		
