/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Implementation file for the Minimap class.
 ******************************************************************************/

#include <iostream>
#include "Minimap.hpp"

// Spaces
const std::string PLAYER = "[X]";
const std::string EMPTY  = "[ ]";

/******************************************************************************
 ** Name  : movePlayer
 ** Desc  : Updates the player's location on the minimap
 ** Args  : row - The player's current row
 **         col - The player's current col
 ** Return:
 ******************************************************************************/

void Minimap::movePlayer(int row, int col)
{
    map[playerRow][playerCol] = EMPTY;
    playerRow = row;
    playerCol = col;
    map[playerRow][playerCol] = PLAYER;
}

/******************************************************************************
 ** Name  : display
 ** Desc  : Displays the minimap to the screen
 ** Args  :
 ** Return:
 ******************************************************************************/

void Minimap::display()
{
    // Position the cursor at the minimap's location
    std::cout << "\033[5;2H";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << map[i][j];
        }

        // Position at next line
        std::cout << "\033[E\033[C";
    }
}

/******************************************************************************
 ** CONSTRUCTOR
 ******************************************************************************/

Minimap::Minimap() : rows(3), cols(10), playerRow(1), playerCol(1)
{
    // Set unique spaces
    map[0][0] = map[0][1] = "   ";
    map[1][0] = EMPTY;
    map[1][1] = PLAYER;
    map[2][0] = map[2][1] = "   ";

    // Populate remaining spaces
    for (int i = 0; i < rows; i++)
    {
        for (int j = 2; j < cols; j++)
        {
            map[i][j] = EMPTY;
        }
    }
}