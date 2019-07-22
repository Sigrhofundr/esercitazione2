//
// Created by alber on 20/07/2019.
//

#include "File.h"

uintmax_t File::getSize() const { //restituisce la dimensione del file
    return 0;
}

//implementa il metodo virtuale puro della classe Base; stampa nome e dimensione del file con indentazione appropriata
void File::Is(int indent = 0) const override{

}

File::File(std::string name, uintmax_t size) {

}

int File::mType() const {
    return 0;
}
