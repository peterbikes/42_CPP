#include "../include/Zombie.hpp"

//random chump is stacked, creates a new zombie locally, anounces it, kills it.

void    randomChump(std::string name)
{
    Zombie local_zombie;
    local_zombie.setName(name);
    local_zombie.announce();
}
