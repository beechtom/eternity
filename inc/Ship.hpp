/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Definition file for the Ship class.
 **         Function descriptions can be found in the implementation file.
 ******************************************************************************/

#ifndef SHIP_HPP
#define SHIP_HPP

#include "Space.hpp"
#include "Minimap.hpp"
#include "Player.hpp"
#include "Inventory.hpp"

class Ship 
{
    private:
        Space* bridge;
        Minimap map;
        Player player;
        Inventory inventory;
        int timeRemaining;
        int cradlesSaved;
        int playthrough;

        // Menus
        Menu<Options::Option> mainMenu;

        // Helper functions
        void   buildShip();
        Space* buildSpace(Options::Option);
        void   destroyShip();
        void   printTime();
        Options::Option runReality();
        void   calculateResults();
        void   reportEndgame();

    public:
        void play();

        // Constructor & Destructor
        Ship();
        ~Ship();
};

#endif