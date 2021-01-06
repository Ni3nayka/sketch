/*
 * dynamixel.h
 *
 * Created: 22.10.2018 19:23:05
 *  Author: potor
 */ 


#ifndef DXLSLZVE_H_
#define DXLSLZVE_H_

#include <stdint.h>

class Dynamixel
{
public:
	Dynamixel (){}
	void begin(void);
	void begin(uint16_t model_number, uint8_t fw_version);
	void set_id (uint8_t id);
	void set_baud (uint8_t baud);
	void set (uint8_t addr, uint8_t val);
	void set16 (uint8_t addr, uint16_t val);
	uint8_t get (uint8_t addr);
	uint16_t get16 (uint8_t addr);
	void set_mode (uint8_t addr, uint8_t mode);
	void set_mode16 (uint8_t addr, uint8_t mode);
	uint8_t  poll();	
	uint8_t  scan();
};

extern Dynamixel DxlSlave;

#endif /* DXLSLZVE_H_ */