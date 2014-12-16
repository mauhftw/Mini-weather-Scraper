#include "functions.h"

int main( int argc, char *argv[] )
{
    int sockfd, newsockfd, portno, clilen;
    extern char *optarg;
    int arg, flag = 0;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int  n, pid;
    int option = 1;
    pthread_t thread_id;
    char port[8];
    char* token;
    char* token2;
    char addr[16];
    int fd, fd2;
    char buffer2[256];

    while ((arg = getopt (argc, argv, "c:"))  >= 0)
      switch (arg) {
    case 'c':
        strcpy(port,optarg);
        flag = 1; 
        break;
    default:        /* ’?’ */
      printf ("Usage: ./server [-c ] port.conf \n");   
      return (-1);
        }
        

    if (flag != 1) {
        printf("-c parameter is missing\n");
        printf ("Usage: ./server [-c ] port.conf\n");
        exit(1);
    }

    /*port config*/
    fd = open(port, O_RDWR|O_CREAT|O_APPEND, 0666);     
    if (fd < 0) {
        perror("error en open()");
    }
    while (fd2 = read(fd,buffer2, sizeof(buffer2)) > 0) {
            token = strtok(buffer2, "=");
            token2 = strtok(NULL, "=");
    }
            portno = atoi(token2);          
            close(fd);


    


    /* Open new ocket*/
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        perror("ERROR opening socket");
        exit(1);
    }
    /* Inicialize Socket */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    //portno = 5001;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
 
  
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
         perror("ERROR on binding");
         exit(1);
    }

    
    if(setsockopt(sockfd,SOL_SOCKET,(SO_REUSEPORT | SO_REUSEADDR),(char*)&option,sizeof(option)) < 0){
        printf("setsockopt failed\n");
        close(sockfd);
        exit(2);
        }

        listen(sockfd,15);
    clilen = sizeof(cli_addr);
    while (1) 
    {
        newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);
        strncpy(addr,inet_ntoa(cli_addr.sin_addr),sizeof(addr));
        //printf("IP CONVERTED: %s\n",addr);
        clientlog(addr);        

        if (newsockfd < 0)
        {
            perror("ERROR on accept");
            exit(1);
        }
        /* Create threads*/
        if( pthread_create( &thread_id , NULL , doprocessing , (void*) &newsockfd) < 0)
        {
            perror("Could not create thread");
            return 1;
        }
         
        //
        pthread_join( thread_id , NULL);
        
    } /* end of while */
}
