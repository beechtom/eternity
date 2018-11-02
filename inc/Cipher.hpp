/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Definition file for the Cipher class.
 **         This class is derived from the Space class.
 **         Function descriptions can be found in the implementation file.
 ******************************************************************************/

#ifndef CIPHER_HPP
#define CIPHER_HPP

#include "Space.hpp"

class Cipher : public Space 
{
    private:
        // Actions
        void decrypt(Inventory&);

    public:
        // Actions
        void display();
        void explore(Inventory&);
        
        // Constructor
        Cipher();
};

#endif