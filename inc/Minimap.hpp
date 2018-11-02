/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Definition file for the Minimap class.
 **         Function descriptions can be found in the implementation file.
 ******************************************************************************/

#ifndef MINIMAP_HPP
#define MINIMAP_HPP

#include <string>

class Minimap
{
    private:
        std::string map[3][10];
        int rows,
            cols,
            playerRow,
            playerCol;

    public:
        void movePlayer(int, int);
        void display();
        Minimap();
};

#endif