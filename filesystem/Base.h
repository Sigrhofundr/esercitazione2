//
// Created by alber on 20/07/2019.
//

#include <string>

#ifndef ESERCITAZIONE2_BASE_H
#define ESERCITAZIONE2_BASE_H

#endif //ESERCITAZIONE2_BASE_H

class Base {
private:
    std::string name;
public:
    void setName(std::string nametobeset);

    std::string getName() const;

    /* metodo virtuale puro di cui fare override nelle classi derivate; restituisce il tipo
     * dell’istanza (Directory o File) codificato come intero*/
    virtual int mType() const = 0;

    virtual void Is(int indent=0) const = 0;
};