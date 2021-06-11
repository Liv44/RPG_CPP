#ifndef ENCOUNTER_HPP
#define  ENCOUNTER_HPP
#include "Character.hpp"
#include "stdlib.h"
#include <iostream>
#include <ostream>
#include <iterator>

class Encounter
{
    public:
    Encounter();

    void monsterEncounter(Character &Character);
};

#endif