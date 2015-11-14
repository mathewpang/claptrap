#include "Wire.h"

void Wire::helloWorld() {
   //printf("Hello World!");
    std::cout << "Hello World from Wire universe\n";
}

/* begin
 *   Starts up i2c settings
 */
void Wire::begin(){

}

int Wire::requestFrom(int address, int quantity){
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
void Wire::beginTransmission(int address){
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
int Wire::endTransmission(){
    close(i2cFile);
}

/* write
 *
 */
int Wire::write(uint8_t byte){
    if(::write(i2cFile, &byte , 1) != 1) {
        std::cout << "write error\n";
    }
}

int Wire::available(){
    struct stat st;
    fstat(i2cFile, &st);
    return st.st_size;
}

uint8_t Wire::read(){
    uint8_t byte = 0x0;
    if(::read(i2cFile, &byte, 1) != 1){
       std::cout << "read error\n";
    }
    return byte;
}

void Wire::onReceive(void(*handler) (int)){

} //Unused

void Wire::onRequest(void(*handler) (void)){

} //Unused




