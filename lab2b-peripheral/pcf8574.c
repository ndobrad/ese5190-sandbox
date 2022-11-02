
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "pico/binary_info.h"
#include "pcf8574.h"

// TODO: should we accept a mask of pins to set high/low initially (for use as inputs/outputs, respectively)?
 pcf8574 pcf8574_init(i2c_inst_t *i2c, uint sda, uint scl, int a0, int a1, int a2) {
    pcf8574 ret;
    i2c_init(i2c, 400 * 1000);
    gpio_set_function(sda, GPIO_FUNC_I2C);
    gpio_set_function(scl, GPIO_FUNC_I2C);
    gpio_pull_up(sda);
    gpio_pull_up(scl);
    // Make the I2C pins available to picotool
    //bi_decl(bi_2pins_with_func(sda, scl, GPIO_FUNC_I2C));
    ret.i2c = i2c;
    ret.addr = (PCF8574_BASE_ADDRESS | (a2 & 1u) << 2 | (a1 & 1u) << 1 | (a1 && 1u));
    return ret;
 }



void pcf8574_read_inputs(pcf8574 device, uint8_t * buf) {
    i2c_read_blocking(device.i2c, device.addr, buf, 1, false);
}



void pcf8574_set_outputs(pcf8574 device, uint8_t * buf) {
    i2c_write_blocking(device.i2c, device.addr, buf, 1, false);

}


