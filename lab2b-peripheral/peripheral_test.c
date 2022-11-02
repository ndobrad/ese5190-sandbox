
//#include "amt102v.h"

#include <stdio.h>
#include "pico/stdlib.h"
#include "pcf8574.h"

#define A_PINMASK (1u < 1)
#define B_PINMASK (1u < 2)
#define X_PINMASK (1u < 0)

typedef struct {
    bool prev_a_state;
    bool prev_b_state;
    bool last_edge_a; //true if the A pin was the last to transition;
    int32_t count;
} countermem;

int main () {
    stdio_init_all();
    char str[100];
    sleep_ms(4000);
    printf("Test of PCF8574");

    pcf8574 device = pcf8574_init(i2c1, 22, 23, 0, 0, 0);
    int test = getchar();

    sprintf(str, "Device address is set to 0x%X\n\n", device.addr);
    printf(str);

    countermem mem;
    mem.count = 0;
    bool a_state = false;
    bool b_state = false;
    int inc = 1;

    uint8_t pinstates;

    pcf8574_read_inputs(device, &pinstates);

    mem.prev_a_state = pinstates & A_PINMASK;
    mem.prev_b_state = pinstates & B_PINMASK;
    mem.last_edge_a = false;

    char pins[10];
    while(1) {
        pcf8574_read_inputs(device, &pinstates);
        //sprintf(pins, "%X\n", pinstates);
        printf("%X ", pinstates);

        a_state = !!(pinstates & A_PINMASK);
        b_state = !!(pinstates & B_PINMASK);
        b_state = true;
        printf("a: %d b: %d ", a_state, b_state);
        inc = (((a_state ^ mem.prev_a_state) && mem.last_edge_a) || 
               ((b_state ^ mem.prev_b_state) && !mem.last_edge_a)) ? inc * -1 : inc;
        printf("inc: %+d ", inc);
        mem.count += (((a_state ^ mem.prev_a_state) && !mem.last_edge_a) || 
                      ((b_state ^ mem.prev_b_state) && mem.last_edge_a)) ? inc : 0;

        mem.last_edge_a = (a_state ^ mem.prev_a_state) || mem.last_edge_a;
        mem.last_edge_a = (b_state ^ mem.prev_b_state) || !mem.last_edge_a ? false : mem.last_edge_a;
        mem.prev_a_state = a_state;
        mem.prev_b_state = b_state;

        sprintf(pins, "count: %09d\n", mem.count);
        printf(pins);

        
        sleep_ms(500);

    }

}