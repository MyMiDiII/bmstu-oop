//
// Created by amunra23 on 22.05.2021.
//

#ifndef FACADE_H
#define FACADE_H

#include <memory>
#include "basecommand.h"

class Facade
{
public:
    void exec(BaseCommand &command);
};

#endif //FACADE_H
