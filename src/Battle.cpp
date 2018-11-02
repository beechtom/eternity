/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Implementation file for the Battle class.
 **         This class is derived from the Space class.
 ******************************************************************************/

#include "Battle.hpp"
#include "Scenes.hpp"
#include "Utilities.hpp"

// Initialize static class member
Options::Option Battle::enemy = Options::None;

/******************************************************************************
 ** Name  : display
 ** Desc  : Display the Space's description
 ** Args  :
 ** Return:
 ******************************************************************************/

void Battle::display()
{
    Screen::clearSpace();
    Scenes::battleDisplay(); 
}

/******************************************************************************
 ** Name  : explore
 ** Desc  : Explore the Space and interact with its contents
 ** Args  :
 ** Return:
 ******************************************************************************/

void Battle::explore(Inventory& inv)
{
    Screen::clearDesc();
    Scenes::battleExplore();
    exploreMenu.displayOptions();
    Options::Option choice = exploreMenu.chooseOption();

    if (choice == Options::Fire)
    {
        quickdraw(inv);
    }
}

/******************************************************************************
 ** Name  : quickdraw
 ** Desc  : Prompt the user to fire their phaser at the shadow.
 ** Args  :
 ** Return:
 ******************************************************************************/

void Battle::quickdraw(Inventory& inv)
{
    Options::Option result;
    Screen::clearDesc();
    Scenes::battleQuickdraw();

    // Prompt user to fire phaser until there is a winner
    do
    {
        // Select phaser type
        quickdrawMenu.displayOptions();
        Options::Option choice = quickdrawMenu.chooseOption();

        // Determine outcome of quickdraw
        Screen::clearDesc();
        result = shoot(choice);

        // Set next enemy shot to user's phaser type
        enemy  = choice;  
    } while (result == Options::Draw);

    // If user won and there is an item to collect
    if (item && result == Options::Win)
    {
        Scenes::battleGetItem();

        // Move codec to inventory
        inv.add(Options::Codec, item);
        item = nullptr;
    }

    // If user lost, delete a codec from the inventory
    else if (result == Options::Lose)
    {
        if (inv.check(Options::Codec))
        {
            Scenes::battleLoseItem();
            delete inv.grab(Options::Codec);
        }
    }

    Screen::pause();
}

/******************************************************************************
 ** Name  : shoot
 ** Desc  : Determines the winner of the quickdraw, a la rock, paper, scissors.
 ** Args  : user - The user's phase choice
 ** Return: Whether the user got a Win, Lose, or Draw
 ******************************************************************************/

Options::Option Battle::shoot(Options::Option user)
{
    // Clear the current display
    Screen::clearDesc();

    // Determine winner and display results
    // There was a draw
    if (user == enemy)
    {
        Scenes::battleDraw();
        return Options::Draw;
    }

    // User won
    else if ((user == Options::Compression && enemy == Options::Photon) ||
             (user == Options::Photon      && enemy == Options::Laser)  ||
             (user == Options::Laser       && enemy == Options::Compression))
    {
        Scenes::battleWin();
        return Options::Win;
    }

    // Enemy won
    else
    {
        Scenes::battleLose();
        return Options::Lose;
    }
}

/******************************************************************************
 ** CONSTRUCTOR
 ******************************************************************************/

Battle::Battle()
{
    // Create item
    item = new Item("Codec");

    // Build explore menu
    exploreMenu.addOption('F', "Fire Your Phaser", Options::Fire);
    exploreMenu.addOption('R', "Run Away", Options::None);

    // Build quickdraw menu
    quickdrawMenu.addOption('1', "Laser Pulse", Options::Laser);
    quickdrawMenu.addOption('2', "Photon Pulse", Options::Photon);
    quickdrawMenu.addOption('3', "Pulse Compression Wave", Options::Compression);
}