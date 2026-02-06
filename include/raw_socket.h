#ifndef RAW_SOCKET_H_
#define RAW_SOCKET_H_
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>

#define ETH_P_ALL 0x0003
#define MAX_PACKET_SIZE 65535
#define RAW_SOCKET socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))

typedef struct sockaddr sockaddr_t;

typedef struct raw_packet_s
{
    uint8_t *data;
    size_t size;
    sockaddr_t addr;
} raw_packet_t;

raw_packet_t *create_raw_packet(uint8_t *, size_t, sockaddr_t);
void delete_raw_packet(raw_packet_t *);
raw_packet_t *raw_recvfrom(int, size_t, int);
#endif