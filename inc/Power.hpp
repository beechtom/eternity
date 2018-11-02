/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Definition file for the Power class.
 **         This class is derived from the Space class.
 **         Function descriptions can be found in the implementation file.
 ******************************************************************************/

#ifndef POWER_HPP
#define POWER_HPP

#include "Space.hpp"
#include "Item.hpp"

class Power : public Space 
{
    private:
        Menu<Options::Option> leverMenu;

        // Actions
        void unlockCell();
        void grabCell(Inventory&);

    public:
        void display();
        void explore(Inventory&);
        
        // Constructor
        Power();
};

#endif