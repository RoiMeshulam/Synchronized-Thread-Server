#include <netinet/in.h> //structure for storing address information
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>
#include <pthread.h>
#include "Stack.h"
#define TRUE 1


/*
 * This is the function we are giving to the new thread
 */
void *newFunc(void *sock){
    int sockId = *((int*)sock);
    free(sock);
    char clientData[1024];
    int numOfBytes;
    numOfBytes = recv(sockId, clientData, 1024, 0);
    clientData[numOfBytes] = '\0';
    if (!strncmp(clientData, "PUSH",4)){
        char* substring = clientData + 5;
        push(substring);
    }
    else if (!strcmp(clientData, "POP")){
        char* curr = pop();
        printf("%s\n",curr);
        send(sockId, curr, strlen(curr), 0);
    }
    else if (!strcmp(clientData, "PEEK")){
        char* curr = peek();
        send(sockId, curr, strlen(curr), 0);
    }
    else{
        printf("Invalid command was entered\n");
    }
    close(sockId);
}

int main(int argc, char const* argv[]){
    initialize();
    int servSockD = socket(AF_INET, SOCK_STREAM, 0);
    // define server address
    struct sockaddr_in servAddr;

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(3490);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    // bind socket to the specified IP and port
    bind(servSockD, (struct sockaddr*)&servAddr,sizeof(servAddr));

    // listen for connections
    listen(servSockD, 10);
    while (TRUE){
        // integer to hold client socket.
        int clientSocket = accept(servSockD, NULL, NULL);
        pthread_t newThread;
        int *newSock = malloc(sizeof (int));
        *newSock = clientSocket;
        pthread_create(&newThread,NULL, newFunc,newSock);
    }
    return 0;
}