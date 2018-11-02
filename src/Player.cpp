/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Implementation file for the Player class.
 ******************************************************************************/

#include "Player.hpp"

/******************************************************************************
 ** SETTERS
 ******************************************************************************/

void Player::setSpace(Space* nextSpace)
{
    this->currentSpace = nextSpace;
}

void Player::setRow(int row)
{
    this->row = row;
}

void Player::setCol(int col)
{
    this->col = col;
}

/******************************************************************************
 ** GETTERS
 ******************************************************************************/

Space* Player::getSpace()
{
    return currentSpace;
}

int Player::getRow()
{
    return row;
}

int Player::getCol()
{
    return col;
}

/******************************************************************************
 ** Name  : move
 ** Desc  : Attempts to move the user to an adjacent room
 ** Args  : direction - The direction to move in
 ** Return: True if move was successful, false otherwise
 ******************************************************************************/

bool Player::move(Options::Option direction)
{
    Space* adjacent = currentSpace->getAdjacent(direction);

    if (adjacent)
    {
        changeLocation(direction);
        currentSpace = adjacent;
        return true;
    }
    else
    {
        return false;
    }
}

/******************************************************************************
 ** Name  : move
 ** Desc  : Attempts to move the user to an adjacent room
 ** Args  : direction - The direction to move in
 ** Return: True if move was successful, false otherwise
 ******************************************************************************/

void Player::changeLocation(Options::Option direction)
{
    switch (direction)
    {
        case Options::Up:    row--;
                             break;
        case Options::Right: col++;
                             break;
        case Options::Down:  row++;
                             break;
        case Options::Left:  col--;
                             break;
        default:             // DO NOTHING
                             break;
    }
}

/******************************************************************************
 ** CONSTRUCTOR
 ******************************************************************************/

Player::Player() : 
currentSpace(nullptr), row(1), col(1)
{
}