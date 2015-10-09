#include "Gyroscope.h"

/* Initial setup of the sensor
 *  What it does is:
 *    1. Check if I2C is connected properly
 *	  2. 
 */
Gyroscope::Gyroscope(Wire* i2c_wire){
	std::cout << "Starting Gyroscope\n";
	wire = i2c_wire;
	bool success = checkConnection();

}

bool Gyroscope::checkConnection(){
	uint8_t id = wire->read(L3GD20_ADDRESS, GYRO_REGISTER_WHO_AM_I);
	//Serial.println(id, HEX);
	if ((id != L3GD20_ID) && (id != L3GD20H_ID))
	{
		std::cout << "Gyro: Failed read for starting up! ::" << id << "\n";
	}
    std::cout << "Gyro Success!\n";
}

/* getRawData 
 *   Fills in the three degree gyroscope 
 *   magnitude 
 */
void Gyroscope::getRawData(){

}