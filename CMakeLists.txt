cmake_minimum_required(VERSION 3.23)
project(AK5PC_ParknigLot)

set(CMAKE_CXX_STANDARD 17)

add_executable(AK5PC_ParknigLot main.cpp src/car.cpp include/car.h include/parkinglot.h src/parkingloterror.cpp include/parkingloterror.h)
