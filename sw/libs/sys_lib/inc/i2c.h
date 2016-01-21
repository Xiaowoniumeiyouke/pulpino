/**
 * @file
 * @brief I2C Peripheral Library.
 *
 * I2C functions for sending and receiving data
 * over an I2C bus.
 *
 * @author Unknown
 *
 * @version 1.0
 *
 * @date 2/10/2015
 *
 */
#ifndef _I2C_H_
#define _I2C_H_

#include <pulpino.h>

#define I2C_START       0x80
#define I2C_STOP        0x40
#define I2C_READ        0x20
#define I2C_WRITE       0x10
#define I2C_CLR_INT     0x01
#define I2C_START_READ  0xA0
#define I2C_STOP_READ   0x60
#define I2C_START_WRITE 0x90
#define I2C_STOP_WRITE  0x50

#define I2C_CTR_EN        0x80 // enable only
#define I2C_CTR_INTEN     0x40 // interupt enable only
#define I2C_CTR_EN_INTEN  0xC0 // enable i2c and interrupts

#define I2C_REG_PRE             ( I2C_BASE_ADDR + 0x00 )
#define I2C_REG_CTR             ( I2C_BASE_ADDR + 0x04 )
#define I2C_REG_RX              ( I2C_BASE_ADDR + 0x08 )
#define I2C_REG_STATUS          ( I2C_BASE_ADDR + 0x0C )
#define I2C_REG_TX              ( I2C_BASE_ADDR + 0x10 )
#define I2C_REG_CMD             ( I2C_BASE_ADDR + 0x14 )

#define I2C_STATUS_RXACK 0x80
#define I2C_STATUS_BUSY  0x40
#define I2C_STATUS_AL    0x20
#define I2C_STATUS_TIP   0x02
#define I2C_STATUS_IF    0x01

/** Confgures I2C with the given prescaler.
 *
 * @param int prescaler - clock divider used to generate I2C clock.
 * @param int enable    - enable I2C peripheral
 *
*/
void i2c_setup(int prescaler,int enable);

/** Sends data via I2C.
 *
 * @param int value - data that sould be transmitted.
 *
*/
void i2c_send_data(int value);

/** Send command to I2C.
 *
 * @param int value - command that should be send.
 *
*/
void i2c_send_command(int value);

/** Get status of the I2C peripheral.
 *
 * @return volatile int - status code
 *
*/
int  i2c_get_status(void);

/** Retrieves data from the I2C bus.
 *
 * @return volatile int - data received.
 *
 */
int  i2c_get_data(void);

/** Wait for acknowledge bit. Use after transmitting data.
 *
 *
 */
int  i2c_get_ack(void);

int i2c_busy(void);

#endif // _I2C_H_
