#include "raw_socket.h"
#include <stdlib.h>

void delete_raw_packet(raw_packet_t *packet)
{
    if (packet)
    {
        if (packet->data)
            free(packet->data);
        free(packet);
    }
}
