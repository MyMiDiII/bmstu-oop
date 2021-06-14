#include "facade.h"


void Facade::exec(BaseCommand &command)
{
    command.execute();
}
