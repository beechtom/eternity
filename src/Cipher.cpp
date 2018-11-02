/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Implementation file for the Cipher class.
 **         This class is derived from the Space class.
 ******************************************************************************/

#include "Cipher.hpp"
#include "Scenes.hpp"

/******************************************************************************
 ** Name  : explore
 ** Desc  : Explore the Space and interact with its contents
 ** Args  :
 ** Return:
 ******************************************************************************/

void Cipher::display()
{
    Screen::clearSpace();
    Scenes::cipherDisplay();
}

/******************************************************************************
 ** Name  : explore
 ** Desc  : Explore the Space and interact with its contents
 ** Args  :
 ** Return:
 ******************************************************************************/

void Cipher::explore(Inventory& inv)
{
    bool loopMenu = true;

    while (loopMenu)
    {
        Screen::clearDesc();
        isClear ? Scenes::cipherComplete() : Scenes::cipherIncomplete();
        exploreMenu.displayOptions();
        Options::Option choice = exploreMenu.chooseOption();

        switch (choice)
        {
            case Options::DecryptKey: decrypt(inv);
                                      break;
            case Options::None:       loopMenu = false;
            default:                  // DO NOTHING
                                      break;
        }
    }
}

/******************************************************************************
 ** Name  : explore
 ** Desc  : Explore the Space and interact with its contents
 ** Args  :
 ** Return:
 ******************************************************************************/

void Cipher::decrypt(Inventory& inv)
{
    Screen::clearDesc();

    // If user has an encrypted key and a codec
    if (inv.check(Options::CryptKey) && inv.check(Options::Codec))
    {
        // 'Decrypt' a key
        item = inv.grab(Options::CryptKey);
        item->type = "Decrypted Key";
        inv.add(Options::DecryptKey, item);
        item = nullptr;

        // Destroy a codec
        delete inv.grab(Options::Codec);

        // Report success & clear room
        Scenes::cipherSuccess();
        exploreMenu.removeOption('D');
        isClear = true;
    }
    else
    {
        Scenes::cipherFail();
    }

    Screen::pause();
}

/******************************************************************************
 ** CONSTRUCTOR
 ******************************************************************************/

Cipher::Cipher()
{
    // Build explore menu
    exploreMenu.addOption('D', "Decrypt Master Key", Options::DecryptKey);
    exploreMenu.addOption('L', "Leave", Options::None);
}