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

/** checkConnection
 * @return success whether gyro worked
 *
 */
bool Gyroscope::checkConnection(){
	uint8_t id = wire->read(L3GD20_ADDRESS, GYRO_REGISTER_WHO_AM_I);
	//Serial.println(id, HEX);
	if ((id != L3GD20_ID) && (id != L3GD20H_ID))
	{
		std::cout << "Gyro: Failed read for starting up! ::" << id << "\n";
	}
    std::cout << "Gyro Success!\n";
}

struct gyro* Gyroscope::getGyroData(){
	getRawData();
	return raw_gyro;
}

/*=======================================================================
		Private Methods
 *=======================================================================

/* getRawData 
 *   Fills in the three degree gyroscope 
 *   magnitude 
 */
void Gyroscope::getRawData(){

	uint8_t xlo = wire->read(L3GD20_ADDRESS, GYRO_REGISTER_OUT_X_L);
    uint8_t xhi = wire->read(L3GD20_ADDRESS, GYRO_REGISTER_OUT_X_H);
    uint8_t ylo = wire->read(L3GD20_ADDRESS, GYRO_REGISTER_OUT_Y_L);
    uint8_t yhi = wire->read(L3GD20_ADDRESS, GYRO_REGISTER_OUT_Y_H);
    uint8_t zlo = wire->read(L3GD20_ADDRESS, GYRO_REGISTER_OUT_Z_L);
    uint8_t zhi = wire->read(L3GD20_ADDRESS, GYRO_REGISTER_OUT_Z_H);

    // Shift values to create properly formed integer (low byte first)
    raw_gyro->gyro_x = (int16_t)(xlo | (xhi << 8)) >> 4;
    raw_gyro->gyro_y = (int16_t)(ylo | (yhi << 8)) >> 4;
    raw_gyro->gyro_z = (int16_t)(zlo | (zhi << 8)) >> 4;
}

