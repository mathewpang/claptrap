#include "Wire.h"

TwoWire Wire = TwoWire();

unsigned long millis(){
  return 0;
}

TwoWire::TwoWire(){
    i2cFile = 0;
    std::cout << "Opening file\n";
    if((i2cFile = open(FILE_PATH, O_RDWR)) < 0){
    // ERROR HANDLING
      std::cout << "file open error\n";
      //printf(“Failed to open the i2c bus”);
    }

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

int TwoWire::requestFrom(int address, int quantity) {
    //if (ioctl(i2cFile, I2C_SLAVE, address) < 0) {
    //  printf(“i2cSetAddress”);
    //  std::cout << "bus access error\n";
    //}
    std::cout << "ioctl-ed";
    int read_pointer = 0;
    int read_max = quantity;
    int count = 0;
    while(count < quantity) {
        int error = read(i2cFile, read_buffer+count, 1 * sizeof(char));
        if(error != -1) {
            count++;
            std::cout << "Read: " << read_buffer[0] << "Error: " << error << "\n";
        }
        sleep(1);
        if(error != 0 && error != 1){
            std::cout << strerror(errno) << "Error: " << errno << "\n";
            std::cout << "\n";
        }

    }
    std::cout << "Read: " << read_buffer[0] << "\n";

    return quantity;

}

/* beginTransmission
 *  Takes in deviceAddress, opens file descriptor
 */
void TwoWire::beginTransmission(int address){
  if (ioctl(i2cFile, I2C_SLAVE, address) < 0) {
      //printf(“i2cSetAddress”);
      std::cout << "bus access error\n";
  }
  std::cout << "ioctled";
}

/* endTransmission
 *   close i2cFile
 */
int TwoWire::endTransmission(){

    //close(i2cFile);
    std::cout << "end Transmission\n";
}

/* write
 *
 */
int TwoWire::write(uint8_t byte){
    if(::write(i2cFile, &byte , 1) != 1) {
        std::cout << "write error\n";
        return 0;
    }
    std::cout << "Writing succeess\n";
    return 1;
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
    return read_max - read_pointer;
}

uint8_t TwoWire::receive(){
    if(read_pointer > read_max){
      return 0;
    }
    char byte = read_buffer[read_pointer];
    read_pointer ++;
    return byte;
}

void TwoWire::onReceive(void(*handler) (int)){

} //Unused

void TwoWire::onRequest(void(*handler) (void)){

} //Unused




