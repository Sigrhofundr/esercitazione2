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
    virtual int mType() const = 0;
    virtual void Is(int indent=0) const = 0;
};