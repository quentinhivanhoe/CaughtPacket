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
    size_t frame = 0;

    while(running)
    {
        packet = raw_recvfrom(raw_sockfd, MAX_PACKET_SIZE, 0);
        if (packet)
        {
            printf("Packedt number %zu\n", frame);
            memset(&meta_data, 0, sizeof(meta_data_t));
            if (packet->data && packet->size > 1)
            {
                memcpy(&meta_data, packet->data, sizeof(meta_data_t));
                printf("\tMac destination address: ");
                print_mac_addr(meta_data.mac_dst);
                printf("\tMac source address: ");
                print_mac_addr(meta_data.mac_src);
                printf("\tEthernet type: ");
                print_eth_type(htons(meta_data.eth_type));
            }
            delete_raw_packet(packet);
            frame++;
        }
        packet = NULL;
    }
    if (packet)
        delete_raw_packet(packet);
    close(raw_sockfd);
    return 0;
}
