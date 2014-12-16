#include "functions.h"

char* filter(char* state){

char* ptr;
char* token, *token2, *token3;
char newstate[64];
char* final;

bzero (newstate,sizeof(newstate));

	printf("%s\n",state);

	if (ptr = strstr(state,"%20")) {

		token=strtok(state,"%20");
	
		strncat(newstate,token,strlen(token));	
		strncat(newstate," ",1);				
		
		token2=strtok(NULL,"%20");
		strncat(newstate,token2,strlen(token2));
		
		printf("FINAL:%s\n",newstate);
		token3 = strtok(NULL,"%20");	

		if (token3 != NULL) {
				
			strncat(newstate," ",1);
			strncat(newstate,token3,strlen(token3));
			printf("FINAL3:%s\n",newstate);

			final = newstate;
			return final;

		} else {

			final = newstate;
			return final;
		}
	}



}





//misiones province
//buenos aires province
//santa cruz province
//chaco province
