//
// Created by Alberto on 20/07/2019.
//

#ifndef ESERCITAZIONE2_FILE_H
#define ESERCITAZIONE2_FILE_H

#include "../Base.h"


class File: public Base {
public:
    uintmax_t getSize() const;
    void ls(int indent = 0) const override;
    File(std::string name, uintmax_t size);
    int mType() const override;
private:
    uintmax_t size;
    int type;
};

#endif //ESERCITAZIONE2_FILE_H