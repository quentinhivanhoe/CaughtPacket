#include "raw_socket.h"
#include "meta_data.h"

#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

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
    meta_data_t meta_data = {0};

    while(running)
    {
        packet = raw_recvfrom(raw_sockfd, MAX_PACKET_SIZE, 0);
        if (packet)
        {
            memset(&meta_data, 0, sizeof(meta_data_t));
            if (packet->data && packet->size > 1)
            {
                memcpy(&meta_data, packet->data, sizeof(meta_data_t));
                for (uint8_t i = 0; i < MAC_ADDR_SIZE; i++)
                    printf("%x:", meta_data.mac_dst[i]);
                printf("\n");
                for (uint8_t i = 0; i < MAC_ADDR_SIZE; i++)
                    printf("%x:", meta_data.mac_src[i]);
                printf("\n");
                printf("%x\n", htons(meta_data.eth_type));
            }
            delete_raw_packet(packet);
        }
        packet = NULL;
    }
    if (packet)
        delete_raw_packet(packet);
    close(raw_sockfd);
    return 0;
}
