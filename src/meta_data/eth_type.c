#include "meta_data.h"
#include <stdio.h>

void print_eth_type(uint16_t eth_type)
{
    switch (eth_type)
    {
    case IPV4:
        printf("IPV4\n");
        break;
    case IPV6:
        printf("IPV6\n");
        break;
    case ARP:
        printf("ARP\n");
        break;
    default:
        fprintf(stderr, "Ethernet type(%X) not recognized\n", eth_type);
        break;
    }
}