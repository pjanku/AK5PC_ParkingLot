//
// Created by Peter Janků on 30.11.2022.
//

#ifndef AK5PC_PARKNIGLOT_PARKINGLOT_H
#define AK5PC_PARKNIGLOT_PARKINGLOT_H
#include <list>
#include <memory>
#include <iostream>
#include "parkingloterror.h"


template<typename T, int size>
class ParkingLot {
public:
    void parkACar(std::shared_ptr<T> car);
    void printParkedCars();
private:
    std::list<std::shared_ptr<T>> _lots;

};

template<typename T, int size>
void ParkingLot<T, size>::parkACar(std::shared_ptr<T> car) {
    if (_lots.size() < size){
        _lots.push_back(car);
    } else
        throw parking_lot_error("No place in this parking log");
}

template<typename T, int size>
void ParkingLot<T,size>::printParkedCars() {
    for(const auto & car:_lots){
        std::cout << car << std::endl;
    }
}



#endif //AK5PC_PARKNIGLOT_PARKINGLOT_H
