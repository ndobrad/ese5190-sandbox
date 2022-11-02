
//#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

#ifndef _PCF8574_H_
#define _PCF8574_H_


#define PCF8574_BASE_ADDRESS 0x20 //8-bit write address with all address pins low
//#define pcf8574_device_offset 0x02; //amount by which the base addr should be increased for each address pin combination
//#define pcf8574_read_offset 0x01; //offset to the 8-bit read address


typedef struct {
    i2c_inst_t *i2c;
    int addr;
    // something else useful eventually?
} pcf8574;



/*! \brief   Initialise the PCF8574 I2C GPIO expander, obtain a \ref pcf8574 struct 
 * that can be used in other functions
 *
 * \param a0 The state of the address jumper/pin A0 - 0x0 for shorted to ground, 0x1 for shorted to VCC
 * \param a1 The state of the address jumper/pin A1 - 0x0 for shorted to ground, 0x1 for shorted to VCC
 * \param a2 The state of the address jumper/pin A2 - 0x0 for shorted to ground, 0x1 for shorted to VCC
 * \return A \ref pcf8574 struct that is passed to other functions to command the chip
 */
 pcf8574 pcf8574_init(i2c_inst_t *i2c, uint sda, uint scl, int a0, int a1, int a2);


/*! \brief   Read the state of the 8 pins on the PCF8574
 * \param device The \ref pcf8574 struct obtained from \ref pcf8574_init()
 * \param buf The location that the read byte should be written to
 */
void pcf8574_read_inputs(pcf8574 device, uint8_t * buf);


/*! \brief   Set the state of the 8 pins on the PCF8574
 * \param device The \ref pcf8574 struct obtained from \ref pcf8574_init()
 * \param buf Pointer to a byte containing the values that should be written
 */
void pcf8574_set_outputs(pcf8574 device, uint8_t * buf);


#endif 