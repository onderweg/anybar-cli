/*
 *  AnyBar cli
 *
 *  Copyright © 2016, G. Stevens. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, const char * argv[]) {        
    if (argc < 2) {
        printf("error: command argument missing\n");
        exit(EXIT_FAILURE);
    }    
    
    printf("Sending AnyBar command...\n");
    
    int clientSocket;
    const char* message = argv[1];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;
    
    /* Create UDP socket */
    clientSocket = socket(PF_INET, SOCK_DGRAM, 0);
    
    /* Configure server settings in serverAddr struct */
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(1738);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    
    /* Initialize size variable */
    addr_size = sizeof serverAddr;
    
    /* Send UDP message to AnyBar */
    sendto(clientSocket, message, strlen(message),0,(struct sockaddr *)&serverAddr,addr_size);
    
    return 0;
}
