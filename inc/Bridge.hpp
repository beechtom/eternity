/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Definition file for the Bridge class.
 **         This class is derived from the Space class.
 **         Function descriptions can be found in the implementation file.
 ******************************************************************************/

#ifndef BRIDGE_HPP
#define BRIDGE_HPP

#include "Space.hpp"

class Bridge : public Space 
{
    private:
        // Flag
        bool isActive;

        // Actions
        void insertKeys(Inventory&);
        void detachCradles();

    public:
        // Actions
       void display();
       void explore(Inventory&);
        
        // Constructor
        Bridge();
};

#endif