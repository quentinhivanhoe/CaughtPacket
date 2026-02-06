#include "raw_socket.h"
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>

bool running = true;

void sig_handler(int signum)
{
    if (signum == SIGINT)
        running = false;
}

int main(void)
{
    int raw_sockfd = RAW_SOCKET;
    raw_packet_t *packet = NULL;

    while(running)
    {
        packet = raw_recvfrom(raw_sockfd, MAX_PACKET_SIZE, 0);
        if (packet)
        {
            if (packet->data && packet->size > 1)
                printf("packet: \n{\n\tsize: %lu\n\t%s\n}\n", packet->size, packet->data);
            delete_raw_packet(packet);
        }   
        packet = NULL;
    }
    if (packet)
        delete_raw_packet(packet);
    close(raw_sockfd);
    return 0;
}