//
// Created by Peter Janků on 30.11.2022.
//

#ifndef AK5PC_PARKNIGLOT_CAR_H
#define AK5PC_PARKNIGLOT_CAR_H

#include <string>
#include <array>
#include <unordered_map>
#include <iostream>

/**
 * @brief Structure representing one car wheel
 */
struct Wheel{
    float pressure;     /**< wheal air pressure */
    float treadDepth;   /**< wheal tread depth */
};

/**
 * @brief Enum defining the position of wheel in specific car
 */
enum class WheelPosition{
    FRONT_LEFT = 0,
    FRONT_RIGHT,
    REAR_LEFT,
    REAR_RIGHT
};


/**
 * Class representing one car
 */
class Car {
public:
    Car(const std::string &name, const float &maxSpeed);
    Car(const Car &car) =  delete;              /**< Deleted constructor - don't allow user to simply copy the Car (Car newCar = oldCar) */
    auto operator=(const Car &car) = delete;    /**< Deleted operator "=" - don't allow user to simply copy the Car (Car newCar; newCar = oldCar)*/

    float getMaxSpeed() const;
    void setMaxSpeed(float maxSpeed);
    const std::string &getName() const;
    void setName(const std::string &name);

    bool operator>(const Car& car) const;
    bool operator<(const Car& car) const;

    Wheel &operator[]( const WheelPosition position);

    void printWheelInfo() const;

protected:
    void printWheelPosition( const WheelPosition position) const;
private:
    float _maxSpeed;                /**< max car speed */
    std::string _name;              /**< car name */
    std::unordered_map<WheelPosition, Wheel> _wheels;   /**< array of car wheels */
};

std::ostream &operator<<(std::ostream &stream, const Car& car);
std::ostream &operator<<(std::ostream &stream, const Car *car);

#endif //AK5PC_PARKNIGLOT_CAR_H
