#include "functions.h"
 
int sockparser (int sock, char* buffer){

	int n, i;
    char response[128] = "<!DOCTYPE html><html><body><h1>WELCOME :)</h1></body></html>\n";
    char header200[128] = "HTTP/1.1 200 OK\r\n Content-Type: text/html; charset=UTF-8\r\n\r\n";
    char aux[512];
    char country[64], parameter[16],state[64];
    char* token, *saveptr, *saveptr2, *token2, *token3, *saveptr3;
    char* result;

            bzero(country,sizeof(country));
            bzero(state,sizeof(state));
            bzero(parameter,sizeof(parameter));
           
            bzero(aux,sizeof(aux));
         
            

            strncpy(aux,buffer,strlen(buffer));   

            token = strtok_r(aux, "\n",&saveptr);  
            printf("TOKEN: %s\n",token);
    
            if (strncmp(token, "GET /index HTTP/1.1\r",22) == 0 || strncmp(token, "GET /index HTTP/1.0\r",22) == 0) {     /*Muestro el index, ahora funciona. Habia que agregarle el /r*/
                printf("muestro el index: %s\n",token);				
                n = send(sock,header200, strlen(header200),0);
                n = send(sock,response, strlen(response),0);
                if (n < 0){
                perror("ERROR writing to socket");
                exit(1);
                }
                return 0;
             }

            else if (strncmp(token, "GET / HTTP/1.0\r",17) == 0 || strncmp(token, "GET / HTTP/1.1\r",17) == 0) {     /*Muestro el index, ahora funciona. Habia que agregarle el /r*/
                printf("muestro el index: %s\n",token);
                n = send(sock,header200, strlen(header200),0);
                n = send(sock,response, strlen(response),0);
                if (n < 0){
                perror("ERROR writing to socket");
                exit(1);
                }
                return 0;
            }

            else {

            /*request*/
            token2 = strtok_r(token, " ",&saveptr2);
            printf("TOKEN2: %s\n",token2);              
            token2 = strtok_r(NULL, " ",&saveptr2);    
            printf("TOKEN3: %s\n",token2);              

            for (i=0; i<3; i++) {
                if (i == 0) {
                    token3 = strtok_r(token2, "/",&saveptr3);
                    printf("TOKEN_IF 0: %s\n",token3);              /*COUNTRY*/ 
                    strncpy(country,token3,strlen(token3));    
                }
                else if (i == 1) {
                    token3 = strtok_r(NULL,"/",&saveptr3);
                        if (token3 == NULL) {
                            i+=2;   
                        } 
                    else {
                    printf("TOKEN_IF 1: %s\n",token3);                /*STATE*/
                        //strcpy(space,token3)
                        if (strstr(token3,"%20") != NULL) {          
                             result = filter(token3);
                             printf("SIN_PORCIENTO: %s\n",result);
                             strncpy(state,result,strlen(result));                    
                                                                      
                        } else {
                            strncpy(state,token3,strlen(token3));
                            }
                    }
                }
                else {
                    token3 = strtok_r(NULL,"/",&saveptr3);
                        if (token3 == NULL) {
                            i+=2;   
                        }
                    else {
                    printf("TOKEN_IF 2: %s\n",token3);  /*PARAMETRO*/
                    strncpy(parameter,token3,strlen(token3));
                    }
                }
            }
            if (checkSql(sock,country,state,parameter) == 0) { 
                close(sock);
            } 

        }


}
	
