#include <stdint.h>
#include <stdio.h>
#include "utf8.h"

void decode_utf8(const char* s) {
    const unsigned char *s1 = (const unsigned char*)s;
    while(*s1){
        int bytes = 0;
        unsigned int decoder = 0;

        if((*s1 & 0x80) == 0x00){
            decoder = *s1;
            bytes = 1;
        }
        else if((*s1 & 0xE0) == 0xC0){
            decoder = (*s1 & 0x1F) << 6; //extract first byte, shift for second byte
            decoder |= (*(s1 + 1) & 0x3F); //add second byte
            bytes = 2;
        }
        else if((*s1 & 0xF0) == 0xE0){
            decoder = (*s1 & 0x0F) << 12; //extract first byte, shift for second byte
            decoder |= (*(s1 + 1) & 0x3F) << 6; //add second byte
            decoder |= (*(s1 + 2) & 0x3F); //add third byte
            bytes = 3;
        }
        else if ((*s1 & 0xF8) == 0xF0) {
            decoder = (*s1 & 0x07) << 18;
            decoder |= (*(s1 + 1) & 0x3F) << 12;
            decoder |= (*(s1 + 2) & 0x3F) << 6;
            decoder |= (*(s1 + 3) & 0x3F);
            bytes = 4;
        }
        else {
            printf("<li>Unknown byte, 0x%02hhx</li>\n", *(s1));
            s1++;
            continue;
        }
        report_character(decoder, bytes);
        s1 += bytes;
    }
}