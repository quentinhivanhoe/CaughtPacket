#include "meta_data.h"
#include <stdio.h>

static void print_cast_type(uint8_t cast_type)
{
    if (cast_type & 0x01)
    {
        if (cast_type == 0xff)
            printf("Broadcast");
        else
            printf("Multicast");
    } else
        printf("Unicast");
}

static void print_mac_addr_type(uint8_t mac_type)
{
    if (mac_type & 0x02)
        printf("LAA");
    else
        printf("UAA");
}

void print_mac_addr(uint8_t mac_addr[MAC_ADDR_SIZE])
{
    for (uint8_t i = 0; i  < (MAC_ADDR_SIZE - 1); i++)
        printf("%.2X:", mac_addr[i]);
    printf("%.2X (", mac_addr[MAC_ADDR_SIZE - 1]);
    print_cast_type(mac_addr[0]);
    printf(", ");
    print_mac_addr_type(mac_addr[0]);
    printf(")\n");
}

