/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Definition file for the Battle class.
 **         This class is derived from the Space class.
 **         Function descriptions can be found in the implementation file.
 ******************************************************************************/

#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "Space.hpp"

class Battle : public Space 
{
    private:
        static Options::Option enemy;
        
        // Menu
        Menu<Options::Option> quickdrawMenu;

        // Actions
        void quickdraw(Inventory&);
        Options::Option shoot(Options::Option);

    public:
        // Actions
        void display();
        void explore(Inventory&);
        
        // Constructor
        Battle();
};

#endif