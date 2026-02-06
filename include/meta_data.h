#ifndef META_DATA_H_
    #define META_DATA_H_
    #include <stdint.h>

    #define MAC_ADDR_SIZE 6

    typedef struct __attribute__((packed)) meta_data_s {
        uint8_t mac_dst[MAC_ADDR_SIZE];
        uint8_t mac_src[MAC_ADDR_SIZE];
        uint16_t eth_type;
    } meta_data_t;

    typedef enum eth_type_e {
        NONE = 0,
        IPV4 = 0x800,
        IPV6 = 0x806,
        ARP = 0x86DD
    } eth_type_t;

void print_mac_addr(uint8_t mac_addr[MAC_ADDR_SIZE]);
// char *mac_addr_str(uint8_t mac_addr[MAC_ADDR_SIZE]);

void print_eth_type(uint16_t eth_type);
// const char *eth_type_str(uint64_t eth_type);

// const char *cast_type(uint8_t cast_type);
#endif