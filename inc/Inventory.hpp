/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Definition file for the Inventory class.
 **         Function descriptions can be found in the implementation file.
 ******************************************************************************/

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <map>
#include "Item.hpp"
#include "Options.hpp"

class Inventory 
{
    private:
        std::multimap<Options::Option, Item*> inventory;

    public:
        void  add(Options::Option, Item*);
        Item* grab(Options::Option);
        int   check(Options::Option);
        void  clear();
        void  display();

        ~Inventory();
};

#endif