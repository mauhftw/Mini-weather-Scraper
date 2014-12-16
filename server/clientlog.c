#include "functions.h"

int clientlog (char* addr) {

	int fd, n;
	char buffer[512];
  bzero(buffer,512);

fd = open ("log.txt", O_RDWR|O_CREAT|O_APPEND, 0666);
  	if (fd < 0) {
      	perror("Error: open()");
        exit(1);
   	}

   	sprintf(buffer,"Connected from address:%s\t",addr);

n = write(fd,buffer,strlen(buffer));
   	if (n < 0) {
   		perror("error en write()");
      exit(1);
   	}
  close(fd);
  close(n);

return 0;

} 