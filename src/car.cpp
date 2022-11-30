//
// Created by Peter Janků on 30.11.2022.
//

#include "../include/car.h"

/**
 * @brief Default constructor
 * @param name Name of the car
 * @param maxSpeed Maximal speed of the car
 */
Car::Car(const std::string &name, const float &maxSpeed):_maxSpeed(maxSpeed),_name(name){
    _wheels.emplace(WheelPosition::FRONT_LEFT, Wheel{2.1,6});
    _wheels.emplace(WheelPosition::FRONT_RIGHT, Wheel{2.1,6});
    _wheels.emplace(WheelPosition::REAR_LEFT, Wheel{2.4,6});
    _wheels.emplace(WheelPosition::REAR_RIGHT, Wheel{2.4,6});

}


float Car::getMaxSpeed() const {
    return _maxSpeed;
}

void Car::setMaxSpeed(float maxSpeed) {
    _maxSpeed = maxSpeed;
}

const std::string &Car::getName() const {
    return _name;
}

void Car::setName(const std::string &name) {
    _name = name;
}

bool Car::operator>(const Car &car) const {
    return this->_maxSpeed > car._maxSpeed;
}

bool Car::operator<(const Car &car) const {
    return this->_maxSpeed < car._maxSpeed;
}

Wheel &Car::operator[](const WheelPosition position) {
    return _wheels[position];
}

/**
 * @brief Print out information about all car wheels
 */
void Car::printWheelInfo() const {
    for (const auto &[position, wheel]: _wheels){
        std::cout << "Wheel:" << std::endl;
        std::cout << "\tPosition: ";
        printWheelPosition(position);
        std::cout << std::endl;
        std::cout << "\tPressure: " << wheel.pressure << std::endl;
        std::cout << "\tTread depth: " << wheel.treadDepth << std::endl;
    }
}

/**
 * @brief Print out position based on provided parameter
 * @param position Wheel position
 */
void Car::printWheelPosition(const WheelPosition position) const {
    switch (position) {
        case WheelPosition::FRONT_LEFT:
            std::cout << "Front left";
            break;
        case WheelPosition::FRONT_RIGHT:
            std::cout << "Front right";
            break;
        case WheelPosition::REAR_LEFT:
            std::cout << "Rear left";
            break;
        case WheelPosition::REAR_RIGHT:
            std::cout << "Rear right";
            break;
    }
}

/**
 * @brief Overloading of stream operator in order to be able print out basic Car info by using std::cout
 * @param stream Output stream
 * @param car Reference to a car to be printed out
 * @return The original stream to be able to use it in chain
 */
std::ostream &operator<<(std::ostream &stream, const Car &car) {
    stream << "Car with name: " << car.getName() << " and max speed: " << car.getMaxSpeed();
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const Car *car) {
    stream << *car;
    return stream;
}
