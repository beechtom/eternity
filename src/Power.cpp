/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Implementation file for the Power class.
 **         This class is derived from the Space class.
 ******************************************************************************/

#include "Power.hpp"
#include "Scenes.hpp"

/******************************************************************************
 ** Name  : display
 ** Desc  : Displays the space's starting information
 ** Args  :
 ** Return:
 ******************************************************************************/

void Power::display()
{
    Screen::clearSpace();
    Scenes::displayPower();
}

/******************************************************************************
 ** Name  : explore
 ** Desc  : Explore the Space and interact with its contents
 ** Args  :
 ** Return:
 ******************************************************************************/

void Power::explore(Inventory& inv)
{
    bool loopMenu = true;

    while (loopMenu)
    {
        Screen::clearDesc();
        isClear ? Scenes::completePower() : Scenes::incompletePower();
        exploreMenu.displayOptions();
        Options::Option choice = exploreMenu.chooseOption();

        switch (choice)
        {
            case Options::Unlock: unlockCell();
                                  break;
            case Options::Grab:   grabCell(inv);
                                  break;
            case Options::None:   loopMenu = false;
                                  break;
            default:              // DO NOTHING
                                  break;
        }
    }
}

/******************************************************************************
 ** Name  : unlockCell
 ** Desc  : Attempt to unlock the power cell
 ** Args  :
 ** Return:
 ******************************************************************************/

void Power::unlockCell()
{
    std::string code;

    Screen::clearDesc();
    Scenes::rulesPower();
    std::cout << "\033[F\033[55G" << item->id;

    leverMenu.displayOptions();

    // Pull levers to build code
    while (code.length() < 5)
    {  
        Options::Option choice = leverMenu.chooseOption();

        switch (choice)
        {
            case Options::Lever1: code += "1";
                                  break;
            case Options::Lever2: code += "2";
                                  break;
            case Options::Lever3: code += "3";
                                  break;
            default:              // DO NOTHING
                                  break;
        }

        Screen::clearLine();
    }

    item->isActive = item->id == code ? true : false;
    if (item->isActive) { exploreMenu.removeOption('U'); }
}

/******************************************************************************
 ** Name  : unlockCell
 ** Desc  : Attempt to unlock the power cell
 ** Args  :
 ** Return:
 ******************************************************************************/

void Power::grabCell(Inventory& inv)
{
    // Cell has been unlocked
    if (item && item->isActive)
    {
        // Move cell to inventory
        inv.add(Options::PowerCell, item);
        item = nullptr;

        // Modify menu
        exploreMenu.removeOption('G');
        isClear = true;

        // Display success
        Screen::clearDesc();
        std::cout << "You grab the power cell and add it to your pack.";
    }

    // Cell is still locked
    else
    {
        Screen::clearDesc();
        std::cout << "You try to grab the power cell, but it's locked "
                  << "in place.";
    }

    Screen::pause();
}

/******************************************************************************
 ** CONSTRUCTOR
 ******************************************************************************/

Power::Power()
{
    // Create item
    item = new Item("Power Cell");

    // Build explore menu
    exploreMenu.addOption('U', "Unlock Cell", Options::Unlock);
    exploreMenu.addOption('G', "Grab Cell",   Options::Grab);
    exploreMenu.addOption('L', "Leave",       Options::None);

    // Build lever menu
    leverMenu.addOption('1', "Pull Lever 1",    Options::Lever1);
    leverMenu.addOption('2', "Pull Lever 2",    Options::Lever2);
    leverMenu.addOption('3', "Pull Lever 3",    Options::Lever3);
}