/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Definition file for the Player class.
 **         Function descriptions can be found in the implementation file.
 ******************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <map>
#include "Space.hpp"
#include "Menu.hpp"
#include "Item.hpp"

class Player 
{
    private:
        // Location
        Space* currentSpace;
        int    row,
               col;

        // Actions
        void changeLocation(Options::Option);

    public:
        // Setters & Getters
        void setSpace(Space*);
        void setRow(int);
        void setCol(int);
        Space* getSpace();
        int    getRow();
        int    getCol();

        // Actions
        bool move(Options::Option);

        // Constructor & Destructor
        Player();
};

#endif