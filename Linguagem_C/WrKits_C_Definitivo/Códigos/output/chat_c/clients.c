#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<pthread.h>

#define MAX_MSG 1000
#define PORT 8888


void* handleMessages(void* arg);

int main(){

    int client_fd;
    struct sockaddr_in sockaddr;
    pthread_t listener;
    char msg[MAX_MSG];


    client_fd = socket(AF_INET, SOCK_STREAM,0);
    sockaddr.sin_family=AF_INET;
    sockaddr.sin_port=htons(PORT);
    sockaddr.sin_addr.s_addr=inet_addr("127.0.0.1");



    connect(client_fd, (struct sockaddr*)&sockaddr, sizeof(sockaddr));


    printf("Connected to server!\n");

    pthread_create(&listener,NULL, handleMessages, &client_fd);


    while (fgets(msg,MAX_MSG, stdin))
    {
        send(client_fd,msg,strlen(msg),0);
    }


    close(client_fd);
    





    return 0;
}





void* handleMessages(void* arg){
    int client_fd=*(int*)arg;
    char buffer[MAX_MSG];
    ssize_t size;

    while ((size=recv(client_fd,buffer,MAX_MSG,0)>0))
    {
        printf(">%s\n", buffer);
    }
    

    return NULL;
}