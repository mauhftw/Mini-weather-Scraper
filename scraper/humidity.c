#include "functions.h" 
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* humidity() {
	
	int leido,i,fd;
	char* token;
	char* chunk = (char*) malloc (128*sizeof(char));
	char* buffer = (char*) malloc (512*sizeof(char));

	fd = open ("request.txt", O_RDONLY);
  	assert(fd >= 0);
  		if (fd < 0){
      		perror("error en open()");
   		 }

	while((leido = read(fd,buffer,sizeof(buffer)*2048)) > 0) { 

			token = strtok(buffer, "< ");                      
        		while (token != NULL) {
				
				if (strstr(token,"class=\"value\">")) {
				
					strcpy(chunk,token);			
					chunk = strtok(token, ">");
					  while (chunk != NULL) {
						
						   if (strlen (chunk) <= 4) {   
							  
							   return chunk;
							}
						chunk = strtok(NULL, ">");
						}
				}
  				token=strtok(NULL, "< ");
			}
		}
	
 }





