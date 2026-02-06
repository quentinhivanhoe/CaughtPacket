#include "raw_socket.h"
#include <stddef.h>

raw_packet_t *raw_recvfrom(int sockfd, size_t len, int flags)
{
    uint8_t buffer[MAX_PACKET_SIZE] = {0};
    sockaddr_t addr = {0};
    socklen_t addr_len = 0;
    ssize_t ret_val = 0;

    if (len > MAX_PACKET_SIZE)
        return NULL;
    if (sockfd == -1)
        return NULL;
    ret_val = recvfrom(sockfd, buffer, len, flags, &addr, &addr_len);
    switch (ret_val)
    {
    case -1:
        perror("raw_recvfrom: ");
        return NULL;
    case 0:
        return create_raw_packet(buffer, 0, addr);
    default:
        return create_raw_packet(buffer, ret_val, addr);
    }
}