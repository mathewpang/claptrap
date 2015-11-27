#include "MotorDriver.h"

MotorDriver::MotorDriver() {
    leftMotor = new Motor("/dev/ttyO2");
    rightMotor = new Motor("/dev/ttyO1");
}

int main() {
    MotorDriver driver = MotorDriver();
    driver.leftMotor->setSpeed(100);
    driver.rightMotor->setSpeed(100);
    sleep(4);
    driver.leftMotor->setSpeed(0);
    driver.rightMotor->setSpeed(0);
}