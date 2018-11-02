/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Implementation file for the Cradle class.
 **         This class is derived from the Space class.
 ******************************************************************************/

#include "Cradle.hpp"
#include "Scenes.hpp"

/******************************************************************************
 ** Name  : display
 ** Desc  : Displays the space's starting information
 ** Args  :
 ** Return:
 ******************************************************************************/

void Cradle::display()
{
    Screen::clearSpace();
    Scenes::cradleDisplay();
} 

/******************************************************************************
 ** Name  : explore
 ** Desc  : Explore the Space and interact with its contents
 ** Args  :
 ** Return:
 ******************************************************************************/

void Cradle::explore(Inventory& inv)
{
    bool loopMenu = true;

    while (loopMenu)
    {
        Screen::clearDesc();
        isClear ? Scenes::cradleComplete() : Scenes::cradleIncomplete();
        exploreMenu.displayOptions();
        Options::Option choice = exploreMenu.chooseOption();

        switch (choice)
        {
            case Options::Insert:   insertCell(inv);
                                    break;
            case Options::None:     loopMenu = false;
            default:                // DO NOTHING
                                    break;
        }
    }
}

/******************************************************************************
 ** Name  : insertCell
 ** Desc  : Attempt to insert a Cell into the Cradle's power supply
 ** Args  : inv - The player's inventory
 ** Return:
 ******************************************************************************/

void Cradle::insertCell(Inventory& inv)
{
    item = inv.grab(Options::PowerCell);
    Screen::clearDesc();

    // Player has a power cell
    if (item)
    {
        Scenes::cradleSuccess();
        exploreMenu.removeOption('I');
        isClear = true;
    }

    // Player does not have a power cell
    else
    {
        Scenes::cradleFail();
    }

    Screen::pause();
}

/******************************************************************************
 ** CONSTRUCTOR
 ******************************************************************************/

Cradle::Cradle()
{
    // Build explore menu
    exploreMenu.addOption('I', "Insert Power Cell", Options::Insert);
    exploreMenu.addOption('L', "Leave", Options::None);
}