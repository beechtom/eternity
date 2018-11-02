/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Definition file for the Cradle class.
 **         This class is derived from the Space class.
 **         Function descriptions can be found in the implementation file.
 ******************************************************************************/

#ifndef CRADLE_HPP
#define CRADLE_HPP

#include "Space.hpp"

class Cradle : public Space 
{
    private:
        // Actions
        void insertCell(Inventory&);

    public:
        // Actions
        void display();
        void explore(Inventory&);
        
        // Constructor & Destructor
        Cradle();
};

#endif