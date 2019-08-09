//
// Created by alber on 20/07/2019.
//

#include <iostream>
#include "File.h"

uintmax_t File::getSize() const { //restituisce la dimensione del file
    return this->size;
}

//implementa il metodo virtuale puro della classe Base; stampa nome e dimensione del file con indentazione appropriata
void File::ls(int indent) const {
    for(int i = 0; i< indent; i++)
        std::cout << "\t";

    std::cout << this->getName()+" "+std::to_string(this->getSize()) << std::endl;
}

File::File(std::string name, uintmax_t size) {
    this->setName(name);
    this->size = size;
}

int File::mType() const {
    return 0;
}
