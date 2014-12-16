#include "functions.h"

int writequeue (char* country, char* state, float temperature, char* humidity, char* update) {

    mqd_t cola;
    int fd;
    char myqueue[16] = "/myqueue";
    char buffer[256];
    struct mq_attr attr;
    bzero(buffer,sizeof(buffer));

    
    printf ("COUNTRY: %s\n",country);
    printf ("STATE: %s\n",state);
    printf ("TEMP: %.2f\n",temperature);
    printf ("HUM: %s\n",humidity);
    printf ("UPDATE ES: %s\n",update);

    sprintf(buffer,"%s-%s-%.2f-%s-%s",country, state, temperature, humidity, update); 
	printf("buffer: %s\n",buffer);

    
    /* Queue's attrs */
    attr.mq_flags = 0;
    attr.mq_maxmsg = 128;
    attr.mq_msgsize = 64;
    attr.mq_curmsgs = 0;

    if((cola = mq_open(myqueue,O_RDWR|O_CREAT,0777,NULL)) < 0) { 
        perror("error mq_open");
        }

    fd = mq_send(cola,buffer,attr.mq_msgsize,0);

    return fd;


}
