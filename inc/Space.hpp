/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Definition file for the Space class.
 **         Function descriptions can be found in the implementation file.
 ******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Menu.hpp"
#include "Options.hpp"
#include "Inventory.hpp"

class Space 
{
    protected:
        Item* item;
        bool  isClear;
        int   timeCost;

        // Neighboring Spaces
        Space* up;
        Space* right;
        Space* down;
        Space* left;

        // Menu
        Menu<Options::Option> exploreMenu;

    public:
        // Setters & Getters
        void   setAdjacent(Options::Option, Space*);
        Space* getAdjacent(Options::Option);
        void   setTimeCost(int);
        int    getTimeCost();
        bool   cleared();

        // Actions
        virtual void display() = 0;
        virtual void explore(Inventory&) = 0;
        
        // Constructor and Destructor
        Space();
        virtual ~Space();
};

#endif