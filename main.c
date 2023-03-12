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
#include <errno.h>

#define DEFAUL_PORT 1738

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "error: command argument missing\n");
        return EXIT_FAILURE;
    }

    int port = (argc == 3) ? strtol(argv[2], NULL, 0) : DEFAUL_PORT;
    int clientSocket;
    const char *message = argv[1];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;
    int result;

    /* Print information message */
    printf("Sending AnyBar command '%s' to port %i...\n", argv[1], port);

    /* Create UDP socket */
    clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

    /* Configure server settings in serverAddr struct */
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    /* Initialize size variable */
    addr_size = sizeof serverAddr;

    /* Send UDP message to AnyBar */
    result = sendto(clientSocket, message, strlen(message), 0, (struct sockaddr *)&serverAddr, addr_size);
    if (result == -1)
    {
        fprintf(stderr, "Send error: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Note: being a stateless protocol, UDP provides no mechanism
    // for checking whether its datagrams arrive.

    return EXIT_SUCCESS;
}
