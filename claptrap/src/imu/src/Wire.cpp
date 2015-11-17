#include "Wire.h"

TwoWire Wire = TwoWire();

unsigned long millis(){
  return 0;
}

void TwoWire::helloWorld() {
   //printf("Hello World!");
    std::cout << "Hello World from TwoWire universe\n";
}

/* begin
 *   Starts up i2c settings
 */
void TwoWire::begin(){

}

int TwoWire::requestFrom(int address, int quantity){
    if((i2cFile = open(FILE_PATH, O_RDWR)) < 0){
        // ERROR HANDLING
        //   perror(“Failed to open the i2c bus”);
    }
    if (ioctl(i2cFile, I2C_SLAVE, address) < 0) {
      //perror(“i2cSetAddress”);
      //exit(1);
    }
}

/* beginTransmission
 *  Takes in deviceAddress, opens file descriptor
 */
void TwoWire::beginTransmission(int address){
    if((i2cFile = open(FILE_PATH, O_RDWR)) < 0){
    // ERROR HANDLING
     //   perror(“Failed to open the i2c bus”);
    }
    if (ioctl(i2cFile, I2C_SLAVE, address) < 0) {
      //perror(“i2cSetAddress”);
      exit(1);
    }
}

/* endTransmission
 *   close i2cFile
 */
int TwoWire::endTransmission(){
    close(i2cFile);
}

/* write
 *
 */
int TwoWire::write(uint8_t byte){
    if(::write(i2cFile, &byte , 1) != 1) {
        std::cout << "write error\n";
    }
}

/* send
*   NOTE* send is exactly like write, 
 *   however some Arduino code needs
*    write and some needs send so both are here
*/
int TwoWire::send(uint8_t byte){
    return write(byte);
}


int TwoWire::available(){
    struct stat st;
    fstat(i2cFile, &st);
    return st.st_size;
}

uint8_t TwoWire::receive(){
    uint8_t byte = 0x0;
    if(::read(i2cFile, &byte, 1) != 1){
       std::cout << "read error\n";
    }
    return byte;
}

void TwoWire::onReceive(void(*handler) (int)){

} //Unused

void TwoWire::onRequest(void(*handler) (void)){

} //Unused




