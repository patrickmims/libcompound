#include "compound.h"

#define BUFFER_SIZE 1024
#define PORT 8080

// In C, a "listener" usually refers to either a network socket listener 
// (waiting for incoming TCP/UDP connections) or an event listener 
// (using function pointers/callbacks to react to internal program events).

void listener()
{
    int server_fd;
    int client_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // 1. Create socket file descriptor (IPv4, TCP)
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Configure address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all network interfaces
    address.sin_port = htons(PORT);       // Convert port to network byte order

    // 2. Bind socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) 
    {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // 3. Start listening (backlog of 3 pending connections)
    if (listen(server_fd, 3) < 0) 
    {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    // 4. Accept and handle incoming connections
    while (1) 
    {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) 
        {
            perror("Accept failed");
            continue;
        }

        // Read incoming data
        ssize_t bytes_read = read(client_fd, buffer, BUFFER_SIZE - 1);

        if (bytes_read > 0) 
        {
            buffer[bytes_read] = '\0';
            printf("Received: %s\n", buffer);
        }

        close(client_fd); // Close client connection
    }

    close(server_fd);

    return 0;
}
