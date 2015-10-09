#include "Accelerometer.h"

Accelerometer::Accelerometer(Wire* i2cwire){
	std::cout << "Starting Accelerometer\n";

	wire = i2cwire;
	raw_accel = (struct accel*)malloc(sizeof(struct accel));
	raw_accel->accel_x = 0;
	raw_accel->accel_y = 0;
	raw_accel->accel_z = 0;
	// Enable the accelerometer (100Hz)
  wire->write(LSM303_ADDRESS_ACCEL, LSM303_REGISTER_ACCEL_CTRL_REG1_A, 0x57);
  checkConnection();

}

bool Accelerometer::checkConnection(){
  // LSM303DLHC has no WHOAMI register so read CTRL_REG1_A back to check
  // if we are connected or not
  uint8_t reg1_a = wire->read(LSM303_ADDRESS_ACCEL, LSM303_REGISTER_ACCEL_CTRL_REG1_A);
  if (reg1_a != 0x57)
  {
    std::cout << "Failed to start Accelerometer! " << reg1_a << "\n";
    return false;
  }  
  std::cout << "Success! Accelerometer working. \n";
  return true;
}

struct accel* Accelerometer::getRawData(){
    uint8_t xlo = wire->read(LSM303_ADDRESS_ACCEL, LSM303_REGISTER_ACCEL_OUT_X_L_A);
    uint8_t xhi = wire->read(LSM303_ADDRESS_ACCEL, LSM303_REGISTER_ACCEL_OUT_X_H_A);
    uint8_t ylo = wire->read(LSM303_ADDRESS_ACCEL, LSM303_REGISTER_ACCEL_OUT_Y_L_A);
    uint8_t yhi = wire->read(LSM303_ADDRESS_ACCEL, LSM303_REGISTER_ACCEL_OUT_Y_H_A);
    uint8_t zlo = wire->read(LSM303_ADDRESS_ACCEL, LSM303_REGISTER_ACCEL_OUT_Z_L_A);
    uint8_t zhi = wire->read(LSM303_ADDRESS_ACCEL, LSM303_REGISTER_ACCEL_OUT_Z_H_A);

    // Shift values to create properly formed integer (low byte first)
    raw_accel->accel_x = (int16_t)(xlo | (xhi << 8)) >> 4;
    std::cout << "accelx: " << raw_accel->accel_x << "\n";
    raw_accel->accel_y = (int16_t)(ylo | (yhi << 8)) >> 4;
    raw_accel->accel_z = (int16_t)(zlo | (zhi << 8)) >> 4;

    return raw_accel;
}