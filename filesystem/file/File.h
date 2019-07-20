//
// Created by Alberto on 20/07/2019.
//

#include "../Base.h"

#ifndef ESERCITAZIONE2_FILE_H
#define ESERCITAZIONE2_FILE_H

#endif //ESERCITAZIONE2_FILE_H

class File: public Base {
public:
    uintmax_t getSize() const;
    void Is(int indent = 0) const override;
    File(std::string name, uintmax_t size);
    int mType() const override;
private:
    uintmax_t size;
    int type;
};