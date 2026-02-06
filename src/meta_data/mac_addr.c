#include "meta_data.h"
#include <stdio.h>

void print_mac_addr(uint8_t mac_addr[MAC_ADDR_SIZE])
{
    for (uint8_t i = 0; i  < (MAC_ADDR_SIZE - 1); i++)
        printf("%X:", mac_addr[i]);
    printf("%X\n", mac_addr[MAC_ADDR_SIZE - 1]);
}

