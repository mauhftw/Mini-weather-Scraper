#include "functions.h"

int serverlog (char* request) {

	int fd, n;
	char date[100];
	char buffer[512];
    time_t now = time (0);
    char* token;
    char* saveptr;

    bzero(buffer,512);
    strftime (date, 100, "%d-%m-%Y %H:%M:%S", localtime (&now));
    printf ("%s\n", date);

    token = strtok_r(request,"\n",&saveptr);  

fd = open ("log.txt", O_RDWR|O_CREAT|O_APPEND, 0666);
  	if (fd < 0) {
      	perror("error en open()");
        exit(1);
   	}

   	sprintf(buffer,"Request:%s Date:%s\n",token,date);

n = write(fd,buffer,strlen(buffer));
   	if (n < 0) {
   		perror("error en write()");
      exit(1);
   	}
  close(fd);
  close(n);

return 0;

}