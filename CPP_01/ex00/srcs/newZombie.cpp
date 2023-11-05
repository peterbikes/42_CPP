#include "../include/Zombie.hpp"
//zombie ptr is heaped -> new is used, and has to be deleted later in main.
 
Zombie* newZombie(std::string name)
{
    Zombie *new_zombie = new Zombie;
    new_zombie->setName(name);
    new_zombie->announce();
    return new_zombie;
}
