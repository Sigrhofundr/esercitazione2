//
// Created by alber on 20/07/2019.
//

#include "Base.h"

void Base::setName(std::string nametobeset) {
    this -> name = nametobeset;
}

std::string Base::getName() const {
    return this->name;
}