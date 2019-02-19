#include "twi.h"

void twi_init(){
	TWI0->FREQUENCY = 0x01980000;
	TWI0->PSELSCL = SCL_PIN;
	TWI0->PSELSDA = SDA_PIN;
}

void twi_multi_read(uint8_t slave_address, uint8_t start_register, int registers_to_read, uint8_t *data_buffer) {
	TWI0->ADDRESS = (uint32_t)slave_address;
	
}