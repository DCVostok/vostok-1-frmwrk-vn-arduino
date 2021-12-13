#include<bitFlip.h>
static uint8_t lookup[16] = {
0x0, 0x8, 0x4, 0xc, 0x2, 0xa, 0x6, 0xe,
0x1, 0x9, 0x5, 0xd, 0x3, 0xb, 0x7, 0xf, };

uint8_t bitFlip(uint8_t n) {
   // Reverse the top and bottom nibble then swap them.
   return (lookup[n&0b1111] << 4) | lookup[n>>4];
}

// static inline uint8_t bitFlip(uint8_t n) {
//     n = ((n>>1)&0x55)|((n<<1)&0xAA);
//     n = ((n>>2)&0x33)|((n<<2)&0xCC);
//     n = (n>>4) | (n<<4) ;
//     return n;
// }

