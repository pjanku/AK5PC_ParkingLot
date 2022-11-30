//
// Created by Peter Janků on 30.11.2022.
//

#ifndef AK5PC_PARKNIGLOT_PARKINGLOTERROR_H
#define AK5PC_PARKNIGLOT_PARKINGLOTERROR_H

#include <stdexcept>
#include <string>

class parking_lot_error: public std::range_error {
public:
    explicit parking_lot_error(const std::string &msg): std::range_error(msg){}
};


#endif //AK5PC_PARKNIGLOT_PARKINGLOTERROR_H
