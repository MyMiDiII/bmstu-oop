#ifndef BASECOMMAND_H
#define BASECOMMAND_H


class BaseCommand
{
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;

    virtual void exec() = 0;
};


#endif //BASECOMMAND_H
