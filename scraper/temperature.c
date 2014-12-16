#include "functions.h" 

char* temperature() {
	
	int leido,i,fd;
	char* token;
	char* aux = (char*) malloc (128*sizeof(char));
	char buffer[2048];

	fd = open ("request.txt", O_RDONLY);
  	assert(fd >= 0);
  		if (fd < 0){
      		perror("error en open()");
   		 }

	while((leido = read(fd,buffer,sizeof(buffer))) > 0) { 

			token = strtok(buffer, "< ");                       
        		while (token != NULL) {
				if (strstr(token,"class=\"num\">")) {
					strcpy(aux,token);
					aux = strtok(token, ">");
					  while (aux != NULL) {
						   if (strlen (aux) <= 2) {   
							   return aux;
							}
						aux = strtok(NULL, ">");
						}
				}
  				token=strtok(NULL, "< ");
			}
		}
	
 }





