/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Implementation file for the Vault class.
 **         This class is derived from the Space class.
 ******************************************************************************/

#include <cstdlib>
#include "Vault.hpp"
#include "Scenes.hpp"

const int CORRECT_NEEDED = 5;

/******************************************************************************
 ** Name  : explore
 ** Desc  : Explore the Space and interact with its contents
 ** Args  :
 ** Return:
 ******************************************************************************/

void Vault::display()
{
    Screen::clearSpace();
    Scenes::vaultDisplay();
}

/******************************************************************************
 ** Name  : explore
 ** Desc  : Explore the Space and interact with its contents
 ** Args  :
 ** Return:
 ******************************************************************************/

void Vault::explore(Inventory& inv)
{
    bool loopMenu = true;

    while (loopMenu)
    {
        Screen::clearDesc();
        isClear ? Scenes::vaultComplete() : Scenes::vaultIncomplete();
        exploreMenu.displayOptions();
        Options::Option choice = exploreMenu.chooseOption();

        switch (choice)
        {
            case Options::Unlock:   unlockSafe(inv);
                                    break;
            case Options::None:     loopMenu = false;
            default:                // DO NOTHING
                                    break;
        }
    }
}

/******************************************************************************
 ** Name  : unlockSafe
 ** Desc  :
 ** Args  :
 ** Return:
 ******************************************************************************/

void Vault::unlockSafe(Inventory& inv)
{
    if (validCode())
    {
        // Move master key to inventory
        inv.add(Options::CryptKey, item);
        item = nullptr;

        // Modify menu
        exploreMenu.removeOption('U');
        isClear = true;

        // Display success
        Screen::clearDesc();
        Scenes::vaultSuccess();
    }
    else
    {
        Screen::clearDesc();
        Scenes::vaultFail();
    }

    Screen::pause();
}

/******************************************************************************
 ** Name  : validCode
 ** Desc  :
 ** Args  :
 ** Return:
 ******************************************************************************/

bool Vault::validCode()
{
    int correctGuesses = 0;

    Screen::clearDesc();
    std::cout << "\033[21;43H" << "THE DISPLAY SHOWS";

    for (int i = 0; i < CORRECT_NEEDED; i++)
    {
        // Generate random numbers and calculate answer
        int randomNum1 = Util::getRandom(0, 9);
        int randomNum2 = Util::getRandom(0, 9);
        int randomDiff = abs(randomNum1 - randomNum2);

        // Display random numbers
        std::cout << "\033[22;50H" << randomNum1 << randomNum2;

        // Prompt for solution
        Screen::clearMenu();
        Screen::prompt("Press A Key");
        int guess = Input::getCharLive() - '0';

        if (guess == randomDiff) { correctGuesses++; }
    }

    return correctGuesses == CORRECT_NEEDED;
}

/******************************************************************************
 ** CONSTRUCTOR
 ******************************************************************************/

Vault::Vault()
{
    // Create item
    item = new Item("Encrypted Key");

    // Build explore menu
    exploreMenu.addOption('U', "Unlock Safe", Options::Unlock);
    exploreMenu.addOption('L', "Leave",       Options::None);
}