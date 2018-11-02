/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Implementation file for the Bridge class.
 **         This class is derived from the Space class.
 ******************************************************************************/

#include "Bridge.hpp"
#include "Scenes.hpp"

/******************************************************************************
 ** Name  : display
 ** Desc  : Displays the space's starting information
 ** Args  :
 ** Return:
 ******************************************************************************/

void Bridge::display()
{
    Screen::clearSpace();
    Scenes::bridgeDisplay();
}

/******************************************************************************
 ** Name  : explore
 ** Desc  : Explore the Space and interact with its contents
 ** Args  : inv - The player's inventory
 ** Return:
 ******************************************************************************/

void Bridge::explore(Inventory& inv)
{
    bool loopMenu = true;

    while (loopMenu)
    {
        Screen::clearDesc();
        isClear ? Scenes::bridgeComplete() : Scenes::bridgeIncomplete();
        exploreMenu.displayOptions();
        Options::Option choice = exploreMenu.chooseOption();

        switch (choice)
        {
            case Options::Insert:   insertKeys(inv);
                                    break;
            case Options::Start:    detachCradles();
                                    break;
            case Options::None:     loopMenu = false;
            default:                // DO NOTHING
                                    break;
        }
    }
    Screen::clearDesc();
}

/******************************************************************************
 ** Name  : insertKeys
 ** Desc  : Insert the decrypted master keys into the sub-command stations
 ** Args  : inv - The player's inventory
 ** Return:
 ******************************************************************************/

void Bridge::insertKeys(Inventory& inv)
{
    if (inv.check(Options::DecryptKey) == 4) // CHANGE TO DECRYPT AFTER TESTING
    {
        // Remove all the keys from the inventory
        while (inv.check(Options::DecryptKey))
        {
            Item* key = inv.grab(Options::DecryptKey);
            if (key) { delete key; }
        }

        // Report success
        Screen::clearDesc();
        Scenes::bridgeSuccess1();
        exploreMenu.removeOption('I');
        isActive = true;
    }
    else
    {
        Screen::clearDesc();
        Scenes::bridgeFail1();
    }

    Screen::pause();
}

/******************************************************************************
 ** Name  : detachCradles
 ** Desc  : Trigger the Cradle detachment sequence
 ** Args  :
 ** Return:
 ******************************************************************************/

void Bridge::detachCradles()
{
    Screen::clearDesc();

    if (isActive)
    {
        Scenes::bridgeSuccess2();
        exploreMenu.removeOption('T');
        isClear = true;
    }
    else
    {
        Scenes::bridgeFail2();
    }

    Screen::pause();
}


/******************************************************************************
 ** CONSTRUCTOR
 ******************************************************************************/

Bridge::Bridge() : isActive(false)
{
    // Build explore menu
    exploreMenu.addOption('I', "Insert Keys", Options::Insert);
    exploreMenu.addOption('T', "Trigger Detach Sequence", Options::Start);
    exploreMenu.addOption('L', "Leave", Options::None);
}