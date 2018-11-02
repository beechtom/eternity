/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Definition file for the Vault class.
 **         This class is derived from the Space class.
 **         Function descriptions can be found in the implementation file.
 ******************************************************************************/

#ifndef VAULT_HPP
#define VAULT_HPP

#include "Space.hpp"

class Vault : public Space 
{
    private:
        // Menus

        // Actions
        void unlockSafe(Inventory&);
        bool validCode();

    public:
        // Actions
        void display();
        void explore(Inventory&);
        
        // Constructor
        Vault();
};

#endif