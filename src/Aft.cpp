/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Implementation file for the Aft class.
 **         This class is derived from the Space class.
 ******************************************************************************/

#include "Aft.hpp"
#include "Scenes.hpp"

// Constants
const int ENCRYPT_ROWS = 10;
const int ENCRYPT_COLS = 100;

/******************************************************************************
 ** Name  : explore
 ** Desc  : Explore the Space and interact with its contents
 ** Args  :
 ** Return:
 ******************************************************************************/

void Aft::display()
{
    Screen::clearSpace();
    Scenes::aftDisplay();
}

/******************************************************************************
 ** Name  : explore
 ** Desc  : Explore the Space and interact with its contents
 ** Args  :
 ** Return:
 ******************************************************************************/

void Aft::explore(Inventory& inv)
{
    bool loopMenu = true;

    while (loopMenu)
    {
        Screen::clearDesc();
        Scenes::aftExplore();
        exploreMenu.displayOptions();
        Options::Option choice = exploreMenu.chooseOption();

        switch (choice)
        {
            case Options::Read:     readLogs();
                                    break;
            case Options::Decrypt:  decryptLog(inv);
                                    break;
            case Options::None:     loopMenu = false;
            default:                // DO NOTHING
                                    break;
        }
    }
}

/******************************************************************************
 ** Name  : readLogs
 ** Desc  : Displays a menu of the ship's logs and prompts the user to read one
 ** Args  :
 ** Return:
 ******************************************************************************/

void Aft::readLogs()
{
    bool loopMenu = true;

    while (loopMenu)
    {
        Screen::clearDesc();
        Scenes::aftLogMenu();
        Screen::prompt("Select An Option");

        switch (Input::getCharLive())
        {
            case '1': Screen::clearDesc();
                      Scenes::aftLog1();
                      Screen::pause();
                      break;
            case '2': Screen::clearDesc();
                      totalDecrypted > 0 ? Scenes::aftLog2() : genEncryptLog();
                      Screen::pause();
                      break;
            case '3': Screen::clearDesc();
                      totalDecrypted > 1 ? Scenes::aftLog3() : genEncryptLog();
                      Screen::pause();
                      break;
            case '4': Screen::clearDesc();
                      totalDecrypted > 2 ? Scenes::aftLog4() : genEncryptLog();
                      Screen::pause();
                      break;
            case '5': Screen::clearDesc();
                      totalDecrypted > 3 ? Scenes::aftLog5() : genEncryptLog();
                      Screen::pause();
                      break;
            case '6': Screen::clearDesc();
                      totalDecrypted > 4 ? Scenes::aftLog6() : genEncryptLog();
                      Screen::pause();
                      break;
            case '7': Screen::clearDesc();
                      totalDecrypted > 5 ? Scenes::aftLog7() : genEncryptLog();
                      Screen::pause();
                      break;
            case '8': loopMenu = false;
            default:  // DO NOTHING
                      break;
        }
    }
}

/******************************************************************************
 ** Name  : decryptLog
 ** Desc  : Decrypts the next log
 ** Args  : inv - The user's inventory
 ** Return:
 ******************************************************************************/

void Aft::decryptLog(Inventory& inv)
{
    Screen::clearDesc();

    // Check if user has any codecs
    if (inv.check(Options::Codec))
    {
        // 'Decrypt' 2 logs and destroy codec
        totalDecrypted += 2;
        delete inv.grab(Options::Codec);

        // Report success
        Scenes::aftSuccess();
    }
    else
    {
        Scenes::aftFail();
    }

    // Check if all logs have been decrypted
    if (totalDecrypted >= 6)
    {
        Scenes::aftComplete();

        // Remove decrypt option from menu
        exploreMenu.removeOption('D');
    }

    Screen::pause();
}

/******************************************************************************
 ** Name  : decryptLog
 ** Desc  : Decrypts the next log
 ** Args  :
 ** Return:
 ******************************************************************************/

void Aft::genEncryptLog()
{
    Screen::clearDesc();

    // Generate random 'encrypted' text
    for (int i = 0; i < ENCRYPT_ROWS; i++)
    {
        for (int j = 0; j < ENCRYPT_COLS; j++)
        {
            std::cout << (char)Util::getRandom(32, 122);
        }

        std::cout << std::endl;
    }

    std::cout << "\n\n\n\n\n"
              << "Ah, yes, that makes a lot of sense. It looks like the log "
              << "is still encrypted." 
              << std::endl;
}

/******************************************************************************
 ** Constructor
 ******************************************************************************/

Aft::Aft() : totalDecrypted(0)
{
    // Build explore menu
    exploreMenu.addOption('R', "Read Ship Logs", Options::Read);
    exploreMenu.addOption('D', "Decrypt Ships Log", Options::Decrypt);
    exploreMenu.addOption('L', "Leave", Options::None);
}