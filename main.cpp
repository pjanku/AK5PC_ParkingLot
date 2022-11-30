#include <iostream>
#include <memory>
#include "include/car.h"
#include "include/parkinglot.h"


/**
 * Tmeplate function for comparison of two numbers.
 * @tparam T1 Data type of return value and first argument
 * @tparam T2 Data type of second argument
 * @param a First element for comparison
 * @param b Second element for comparison
 * @return Smaller element from two provided parameters
 */
template<class T1, class T2 >
T1 minValue(T1 a, T2 b){
    return (a < b)?a:b;
}

/**
 * Specialization of template function minValue using references (for object, which has deleted copy constructor)
 * @sa minValue
 * @tparam T Type of the objects
 * @param a First element for comparison
 * @param b Second element for comparison
 * @return Smaller element from two provided parameters
 */
template<class T>
T& minValue(T& a, T& b){
    return (a < b)?a:b;
}

/**
 * Specialization of template function minValue
 * @sa minValue
 * @param a First pointer for value comparison
 * @param b Second pointer for value comparison
 * @return Pointer to a parameter with smaller value
 */
int *minValue(int* a, int* b){
    return (*a < *b)?a:b;
}

int main() {

    // example of  template function usage
    int a {10};
    int b {5};
    std::cout << "Smaller values from " << a << " and " << b << " is " << minValue(a,b) << std::endl;

    float fA {10.2};
    float fB {10.6};
    std::cout << "Smaller values from " << fA << " and " << fB << " is " << minValue(fA,fB) << std::endl;

    std::cout << "Smaller values from " << a << " and " << b << " is " << *minValue(&a,&b) << std::endl;


    auto yourCar = std::make_shared<Car>("Trabant", 60);
    auto myCar = std::make_shared<Car>("Ferrari", 260);

    std::cout << yourCar <<  std::endl;
    std::cout << myCar << std::endl;
    std::cout << "The slower car is: " << minValue(yourCar,myCar) << std::endl;

    ParkingLot<Car,2> parkingLot;
    parkingLot.parkACar(myCar);
    parkingLot.parkACar(yourCar);

    std::cout << "Already parked cars: " <<   std::endl;
    parkingLot.printParkedCars();

    try {
        parkingLot.parkACar(std::make_shared<Car>("Lamborgini",310));
    }catch(const parking_lot_error& err){
        std::cout << err.what();
    }

    return 0;
}
