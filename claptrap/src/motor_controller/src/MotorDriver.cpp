#include "MotorDriver.h"

MotorDriver::MotorDriver() {
    leftMotor = new Motor("/dev/ttyO2");
    rightMotor = new Motor("/dev/ttyO1");
}

void MotorDriver::forward(int speed) {
    if (speed > 100) {
        speed = 100;
    } else if (speed < -100) {
        speed = -100;
    }
    leftMotor->setSpeed(speed);
    rightMotor->setSpeed(speed);
}

void MotorDriver::turn(int speed) {
    if (speed > 100) {
        speed = 100;
    } else if (speed < -100) {
        speed = -100;
    }
    int leftSpeed = -1*speed;
    leftMotor->setSpeed(leftSpeed);
    rightMotor->setSpeed(speed);
}

void MotorDriver::stop() {
    leftMotor->setSpeed(0);
    rightMotor->setSpeed(0);
}

void MotorDriver::test() {
    forward(100);
    sleep(2);
    turn(100);
    sleep(2);
    turn(-100);
    sleep(2);
    forward(0);
    sleep(1);
    forward(100);
    forward(-100);
    forward(100);
    sleep(1);
    stop();
}

int main() {
    MotorDriver driver = MotorDriver();
    driver.test();
}