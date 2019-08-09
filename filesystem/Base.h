//
// Created by alber on 20/07/2019.
//

#ifndef ESERCITAZIONE2_BASE_H
#define ESERCITAZIONE2_BASE_H

#include <string>

class Base {
private:
    std::string name;
public:
    void setName(std::string nametobeset);

    std::string getName() const;

    /* metodo virtuale puro di cui fare override nelle classi derivate; restituisce il tipo
     * dell’istanza (Directory o File) codificato come intero*/
    virtual int mType() const = 0;

    virtual void ls(int indent=0) const = 0;
};

#endif //ESERCITAZIONE2_BASE_H