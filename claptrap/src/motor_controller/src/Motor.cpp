#include "Motor.h"

Motor::Motor(const char* device) {
    file = open(device, O_RDWR | O_NOCTTY);
    if (file == -1) {
        std::cout << "Error opening file.\n";
    }
    struct termios options;
    tcgetattr(file, &options);
    options.c_iflag &= ~(INLCR | IGNCR | ICRNL | IXON | IXOFF);
    options.c_oflag &= ~(ONLCR | OCRNL);
    options.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    tcsetattr(file, TCSANOW, &options);

    int response = exitSafeStart();
}


// Sends the Exit Safe Start command, which is required to drive the motor.
// Returns 0 if successful, SERIAL_ERROR if there was an error sending.
// Can use GetVariable with ID 0 to see for safe start errors
int Motor::exitSafeStart() {
    if (::write(file, &MOTOR_SAFE_START, 1) == -1) {
        std::cout << "Error starting motor.";
        return SERIAL_ERROR;
    }
    return 0;
}

// Returns the target speed (-3200 to 3200).
// Returns SERIAL_ERROR if there is an error.
int Motor::getTargetSpeed() {
  int val = getVariable(20);
  return (signed short) val;
}

int Motor::getCurrentSpeed() {
  int val = getVariable(21);
  return (signed short) val;
}


// Reads a variable from the SMC and returns it as number between 0 and 65535.
// Returns SERIAL_ERROR if there was an error.
// The 'variableId' argument must be one of IDs listed in the
// "Controller Variables" section of the user's guide.
// For variables that are actually signed, additional processing is required
// (see smcGetTargetSpeed for an example).
int Motor::getVariable(uint8_t variableId) {
    uint8_t command[] = {MOTOR_GET_VAR, variableId};
    if(write(file, &command, sizeof(command)) == -1) {
        std::cout << "Error writing.";
        return SERIAL_ERROR;
    }
 
    uint8_t response[2];
    if(read(file,response,2) != 2) {
        std::cout << "Error reading.";
        return SERIAL_ERROR;
    }
  return response[0] + 256*response[1];
}
 

// Sets the SMC's target speed (-100).
// Returns 0 if successful, SERIAL_ERROR if there was an error sending.
int Motor::setSpeed(int speed) {
    uint8_t command[3];
    if (speed < 0) {
        command[0] = MOTOR_REV; // Motor Reverse
        speed = -1 * speed;
    } else {
        command[0] = MOTOR_FWD; // Motor Forward
    }
    command[1] = 0x00;
    command[2] = speed;
 
    if (write(file, command, sizeof(command)) == -1)  {
        std::cout << "Error writing.";
        return SERIAL_ERROR;
    }
    return 0;
}

int Motor::setBrake(int brake) {
    int command[2];
    command[0] = MOTOR_BRAKE; // Motor Reverse
    if (brake < 0) {
        brake = 0;
    } else if (brake > 32) {
        brake = 32;
    }
    command[1] = brake;
 
    if (write(file, command, sizeof(command)) == -1)  {
        std::cout << "Error writing.";
        return SERIAL_ERROR;
    }
    return 0;
}

int Motor::getBrake() {
    return getVariable(22);
}