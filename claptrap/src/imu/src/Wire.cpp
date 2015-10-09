#include "Wire.h"

Wire::Wire(){
    filei2c = 0;
    if ((filei2c = ::open(FILE_PATH,O_RDWR)) < 0) {
        std::cout << "Error to open file\n";
        exit(1);
    }
    std::cout << "Open file success!\n";
}
void Wire::close(){
	::close(filei2c);
}
     

uint8_t Wire::read(uint8_t addr, uint8_t reg){
  	if (ioctl(filei2c,I2C_SLAVE,addr) < 0) { //Get slave access
        std::cout << "Error to ioctle, bus access when read\n" << addr;
        exit(1);
  	}

	char buf[10]; //Tell slave which register we want
  	buf[0] = (char)reg;
  	
  	if (::write(filei2c,buf,1) != 1) { //We are reading from this register
        std::cout << "Failed to write to the i2c bus.\n";
    }

  	if (::read(filei2c,buf,1) != 1) { //Read from slave
        std::cout << "Failed to read from the i2c bus.\n";
    }
    return (uint8_t)buf[0];
}
int Wire::write(uint8_t addr, uint8_t reg, uint8_t value){
  	if (ioctl(filei2c,I2C_SLAVE,addr) < 0) { //Get slave access
        std::cout << "Error to ioctle, bus access when writing\n" << addr;
        exit(1);
  	}
  	char buf[10]; //Write Register, and value
  	buf[0] = (char)reg;
  	buf[1] = (char)value;
  	
  	if (::write(filei2c,buf,2) != 2) {
        std::cout << "Failed to write to the i2c bus.\n";
    }
}