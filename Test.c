#include <netinet/in.h> //structure for storing address information
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>
#include <pthread.h>
#include "Stack2.h"
int counter = 0;
void *newFunc1(void* txt){
    int curr = *((int*)txt);
    push(curr);
    counter+=curr;
}

void *newFunc2(){
    int poped = pop();
    counter-=poped;
}

int main(int argc, char const* argv[]) {
    initialize();
    int counter = 0;
    for (int i = 1; i <= 100; ++i) {
        pthread_t newThread;
        int *value = malloc(sizeof (int));
        *value = i;
        pthread_create(&newThread,NULL, newFunc1,value);
        free(value);
    }
    for (int i = 1; i <= 100; ++i) {
        pthread_t newThread;
        pthread_create(&newThread,NULL, newFunc2,NULL);
    }
    sleep(3);
    if(counter == 0 ){
        printf("Success!\n");
    }
    else{
        printf("Failure...\n");
    }
    return 0;
}