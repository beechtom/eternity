/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Main menu for the game.
 ******************************************************************************/

#include "Utilities.hpp"
#include "Ship.hpp"

void title()
{
    bool  loopGame = true;
    Ship* eternity = nullptr;

    while (loopGame)
    {
        // Display title
        Screen::clearAll();
        Util::printTextFile("./txt/title.txt");

        // Prompt for choice
        switch (Input::getCharLive())
        {
            case '1': Screen::clearAll();
                      Util::printTextFile("./txt/intro.txt");
                      Screen::pause();
                      eternity = new Ship();
                      eternity->play(); 
                      delete eternity;
                      eternity = nullptr;
                      break;
            case '2': loopGame = false;
                      break;
            default : // DO NOTHING
                      break;
        }
    }
}