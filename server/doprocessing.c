#include "functions.h"

void* doprocessing (void* sockfd){
    int n, fd;
    char buffer[512];
    int sock = *(int*)sockfd;
    sem_t mutex;


    bzero(buffer,512);
    sem_init(&mutex, 0, 1);

    while ((n=read(sock,buffer,512)) > 0) { 
    if (n < 0){
        perror("ERROR: reading from socket");
        exit(1);
    }
    printf("Here is the message: %s\n",buffer);
            //sockparser(sock, buffer);   /*Parseo y envio respuestas al cliente*/
    sem_wait(&mutex);          /*Semaforito*/
    
	    fd=sockparser(sock, buffer);
            if (fd == 0) {
                close(sock);
            }

        serverlog(buffer);          /*log de request*/

    sem_post(&mutex);

    }
    close(n);
}   
