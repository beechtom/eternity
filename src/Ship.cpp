/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Implementation file for the Ship class.
 ******************************************************************************/

#include <algorithm>
#include <vector>
#include "Ship.hpp"
#include "Aft.hpp"
#include "Battle.hpp"
#include "Bridge.hpp"
#include "Cipher.hpp"
#include "Cradle.hpp"
#include "Power.hpp"
#include "Vault.hpp"
#include "Utilities.hpp"
#include "Scenes.hpp"

const int SHIP_SPACES  = 24;
const int TIME_BASE    = 128;    // maximum time cost for a space
const int TIME_FACTOR  = 2;      // time cost multiplier for spaces
const int AFT_TIME     = 512;
const int BRIDGE_TIME  = 2048;
const int TIME_ALLOTED = 30000;

/******************************************************************************
 ** Name  : buildSpace
 ** Desc  : Allocates a specified Space type
 ** Args  : space - The type of Space
 ** Return: A pointer to the newly allocated Space
 ******************************************************************************/

Space* Ship::buildSpace(Options::Option space)
{
    switch (space)
    {
        case Options::Battle:   return new Battle();
        case Options::Cipher:   return new Cipher();
        case Options::Power:    return new Power();
        case Options::Vault:    return new Vault();
        default:                return new Cradle();
    }
}

/******************************************************************************
 ** Name  : buildShip
 ** Desc  : Constructs the randomized matrix of Spaces on the ship
 ** Args  :
 ** Return:
 ******************************************************************************/

void Ship::buildShip()
{
    Space* T1 = nullptr;  // Next top-level Space
    Space* T2 = nullptr;  // Prev top-level Space
    Space* M1 = nullptr;  // Next mid-level Space
    Space* M2 = nullptr;  // Prev mid-level Space
    Space* B1 = nullptr;  // Next bot-level Space
    Space* B2 = nullptr;  // Prev bot-level Space

    // List of Spaces to construct
    std::vector<Options::Option> spaces = 
    { Options::Battle, Options::Battle, Options::Battle, Options::Battle, 
      Options::Battle, Options::Battle, Options::Battle, Options::Battle, 
      Options::Battle, Options::Battle, Options::Cipher, Options::Cipher,
      Options::Cipher, Options::Cipher, Options::Power,  Options::Power,  
      Options::Power,  Options::Vault,  Options::Vault,  Options::Vault,  
      Options::Vault };

    std::random_shuffle(spaces.begin(), spaces.end());

    // Add Cradles to the back of the Ship
    spaces.push_back(Options::Cradle);
    spaces.push_back(Options::Cradle);
    spaces.push_back(Options::Cradle);

    // Build the Bridge and Aft, make connection
    bridge = M2 = new Bridge;
             M1 = new Aft;
    
    M1->setAdjacent(Options::Left,  M2);
    M2->setAdjacent(Options::Right, M1);
    M1->setTimeCost(AFT_TIME);
    M2->setTimeCost(BRIDGE_TIME);

    // Construct sequence of general Spaces
    for (int i = 0; i < SHIP_SPACES; i += 3 )
    {
        T2 = T1;
        M2 = M1;
        B2 = B1;

        // Build new Spaces
        T1 = buildSpace(spaces[i]);
        M1 = buildSpace(spaces[i + 1]);
        B1 = buildSpace(spaces[i + 2]);

        T1->setTimeCost(TIME_BASE / (TIME_FACTOR * (i + 1)));
        M1->setTimeCost(TIME_BASE / (TIME_FACTOR * (i + 1)));
        B1->setTimeCost(TIME_BASE / (TIME_FACTOR * (i + 1)));

        // Link new Spaces
        T1->setAdjacent(Options::Left, T2);
        T1->setAdjacent(Options::Down, M1);
        M1->setAdjacent(Options::Up,   T1);
        M1->setAdjacent(Options::Left, M2);
        M1->setAdjacent(Options::Down, B1);
        B1->setAdjacent(Options::Up,   M1);
        B1->setAdjacent(Options::Left, B2);

        // Link old Spaces
        if (T2) { T2->setAdjacent(Options::Right, T1); }
        if (M2) { M2->setAdjacent(Options::Right, M1); }
        if (B2) { B2->setAdjacent(Options::Right, B1); }
    }
}

/******************************************************************************
 ** Name  : destroyShip
 ** Desc  : Deletes the matrix of Spaces on the ship
 ** Args  :
 ** Return:
 ******************************************************************************/

void Ship::destroyShip()
{
    Space* next     = nullptr;
    Space* trailTop = nullptr;
    Space* trailMid = nullptr;
    Space* trailBot = nullptr;

    for (trailMid = bridge; trailMid != nullptr; )
    {
        next = trailMid->getAdjacent(Options::Right);
        trailTop = trailMid->getAdjacent(Options::Up);
        trailBot = trailMid->getAdjacent(Options::Down);

        if (trailMid != nullptr) { delete trailMid; }
        if (trailTop != nullptr) { delete trailTop; }
        if (trailBot != nullptr) { delete trailBot; }

        trailMid = next;
    }
}

/******************************************************************************
 ** Name  : play
 ** Desc  : Runs the game until the user chooses to quit.
 ** Args  :
 ** Return:
 ******************************************************************************/

void Ship::play()
{
    bool endGame = false;
    Screen::clearAll();
    Scenes::gameTitle();

    while (!endGame)
    {
        Options::Option outcome = runReality();

        // End loop if user chooses to quit
        if (outcome == Options::Quit)
        {
            endGame = true;
        }

        else
        {
            // Calculate results
            calculateResults();

            // Prompt to continue playing
            Screen::clearSpace();
            Scenes::gameEnd();
            Screen::prompt("Press Any Key To Continue, or [Q] to Quit");
            
            if (Input::getCharLive() == 'Q') 
            { 
                endGame = true; 
            }

            else
            {
                // Clear the current reality
                destroyShip();
                inventory.clear();

                // Build the new reality
                buildShip();

                // Reset the ship
                player.setSpace(bridge->getAdjacent(Options::Right));
                player.setCol(1);
                player.setRow(1);
                map.movePlayer(player.getRow(), player.getCol());
                timeRemaining = TIME_ALLOTED;
                playthrough++;
            }
        }
    }

    reportEndgame();
}

/******************************************************************************
 ** Name  : runReality
 ** Desc  : Runs the game until the user chooses to quit, loses, or finishes.
 ** Args  :
 ** Return:
 ******************************************************************************/

Options::Option Ship::runReality()
{
    map.display();
    printTime();
    Screen::clearDesc();
    Scenes::gameStart();
    Screen::pause();

    while (timeRemaining > 0 && !bridge->cleared())
    {
        map.display();
        printTime();
        player.getSpace()->display();
        mainMenu.displayOptions();
        Options::Option choice = mainMenu.chooseOption();

        switch (choice)
        {
            case Options::Up:
            case Options::Left:
            case Options::Down:
            case Options::Right:     timeRemaining -= player.getSpace()->getTimeCost();
                                     player.move(choice);
                                     map.movePlayer(player.getRow(), player.getCol());
                                     break;
            case Options::Explore:   player.getSpace()->explore(inventory);
                                     break;
            case Options::Inventory: inventory.display();
                                     break;
            case Options::Quit:      return Options::Quit;
            default:                 // DO NOTHING
                                     break;
        }
    }

    return timeRemaining <= 0 ? Options::Lose : Options::Win;
}/******************************************************************************
 ** Name  : printStatus
 ** Desc  : Print the current status to the screen.
 ** Args  :
 ** Return:
 ******************************************************************************/

void Ship::printTime()
{
    std::cout << "\033[6;58H\033[K"
              << "FUEL REMAINING: " << timeRemaining;
}

/******************************************************************************
 ** Name  : calculateResults
 ** Desc  : Determines the number of cradles saved.
 ** Args  :
 ** Return:
 ******************************************************************************/

void Ship::calculateResults()
{
    // Create temporary pointer
    Space* cradlePointer = bridge;

    // Locate the cradles at the end
    while (cradlePointer->getAdjacent(Options::Right))
    {
        cradlePointer = cradlePointer->getAdjacent(Options::Right);
    }

    // Count number of cradles cleared
    if (bridge->cleared())
    {
        if (cradlePointer->cleared()) { cradlesSaved++; }
        if (cradlePointer->getAdjacent(Options::Up)->cleared()) { cradlesSaved++; }
        if (cradlePointer->getAdjacent(Options::Down)->cleared()) { cradlesSaved++; }
    }
}

/******************************************************************************
 ** Name  : printStatus
 ** Desc  : Print the current status to the screen.
 ** Args  :
 ** Return:
 ******************************************************************************/

void Ship::reportEndgame()
{
    Screen::clearAll();
    Util::printTextFile("./txt/gameover.txt");
    std::cout << "\033[2A\033[22C"
              << "GAME OVER. YOU SUCCESSFULLY SAVED "
              << cradlesSaved << " CRADLES ACROSS "
              << playthrough  << " REALITIES. "
              << "PRESS ANY KEY TO RETURN TO THE MAIN MENU."
              << "\033[3B\r";
    Input::getCharLive();
}

/******************************************************************************
 ** CONSTRUCTOR
 ******************************************************************************/

Ship::Ship() : bridge(nullptr)
{
    // Build main menu
    mainMenu.addOption('W', "Up",        Options::Up);
    mainMenu.addOption('A', "Left",      Options::Left);
    mainMenu.addOption('S', "Down",      Options::Down);
    mainMenu.addOption('D', "Right",     Options::Right);
    mainMenu.addOption('E', "Explore",   Options::Explore);
    mainMenu.addOption('I', "Inventory", Options::Inventory);
    mainMenu.addOption('Q', "Quit",      Options::Quit);

    // Build Spaces
    buildShip();

    // Setup Player information
    player.setSpace(bridge->getAdjacent(Options::Right));

    // Set initial game status
    timeRemaining = TIME_ALLOTED;
    cradlesSaved  = 0;
    playthrough   = 1;
}

/******************************************************************************
 ** DESTRUCTOR
 ******************************************************************************/

Ship::~Ship()
{
    if (bridge) { destroyShip(); }
}