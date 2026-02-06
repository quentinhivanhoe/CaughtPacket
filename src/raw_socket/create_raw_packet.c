#include "raw_socket.h"
#include <stdlib.h>
#include <string.h>

raw_packet_t *create_raw_packet(uint8_t *buffer, size_t len, sockaddr_t addr)
{
    raw_packet_t *packet = NULL;

    if (!buffer)
        return NULL;
    packet = calloc(1, sizeof(raw_packet_t));
    if (!packet)
        return NULL;
    memset(packet, 0, sizeof(raw_packet_t));
    packet->data = calloc(len + 1, sizeof(uint8_t));
    if (!packet->data)
    {
        free(packet);
        return NULL;
    }
    memset(packet->data, 0, sizeof(raw_packet_t));
    packet->size = len;
    memcpy(packet->data, buffer, len);
    memcpy(&packet->addr, &addr, sizeof(sockaddr_t));
    return packet;
}