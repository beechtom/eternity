/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 04/15/2018
 ** Desc  : Common utility functions, including input validation and data
            generation.
 ******************************************************************************/

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <string>

/******************************************************************************
 ** GENERAL UTILITIES
 ** Functions to generate data
 ******************************************************************************/

namespace Util 
{
    int  getRandom(int, int);
    void printTextFile(std::string);
}

/******************************************************************************
 ** INPUT UTILITIES
 ** Functions to retrieve and validate input from the user
 ******************************************************************************/

namespace Input 
{
    char getCharLive();
}

/******************************************************************************
 ** SCREEN UTILITIES
 ** Functions to manipulate the display on the screen
 ******************************************************************************/

namespace Screen 
{
    void clearAll();
    void clearSpace();
    void clearDesc();
    void clearMenu();
    void clearLine();
    void pause();
    void prompt(std::string);
}

#endif
