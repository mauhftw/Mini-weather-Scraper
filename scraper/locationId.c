#include "functions.h" 	


char* locationId(char* country, char* state){
	
	char buffer[512];
	char search[128];
	char aux[512];
	char aux2[512]; 
	char* foundit = (char*) malloc(16*sizeof(char));
	int leido,fd;
	char* token, *token2, *token3, *token4;
	char *token5 = (char*) malloc(16*sizeof(char));
	char *woeid = (char*) malloc(16*sizeof(char));
	char* error = "error";
	
	bzero(buffer,sizeof(buffer));
	bzero(search,sizeof(search));
	bzero(aux,sizeof(aux));
	bzero(aux2,sizeof(aux2));

	sprintf(search,"<td>%s</td><td>%s</td><td class='woeid'>",state,country); 
   

	fd = open ("id.txt", O_RDONLY);
  		if (fd < 0){
      		perror("error en open()");
   		 }

	while((leido = read(fd,buffer,sizeof(buffer))) > 0){
			
			if (foundit=strstr(buffer,search)) {
				
				token = strtok(foundit,"=");
				token2 = strtok(NULL,"=");
				strncpy(aux,token2,strlen(token2));
				token3 = strtok(aux,"<");
				strncpy(aux2,token3,strlen(token3));
				token4 = strtok(aux2,">");
				token5 = strtok(NULL,"");
				strcpy(woeid,token5);
				close(fd);
				return woeid;


			}
			
	}
		close(fd);
		return error;		
}







	
      
	
