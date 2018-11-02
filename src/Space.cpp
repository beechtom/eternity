/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Implementation file for the Space class.
 ******************************************************************************/

#include <iostream>
#include "Space.hpp"

/******************************************************************************
 ** SETTERS
 ******************************************************************************/

void Space::setAdjacent(Options::Option direction, Space* neighbor)
{
    switch (direction)
    {
        case Options::Up:    up = neighbor;
                             break;
        case Options::Right: right = neighbor;
                             break;
        case Options::Down:  down = neighbor;
                             break;
        case Options::Left:  left = neighbor;
                             break;
        default:             // DO NOTHING
                             break;
    }
}

void Space::setTimeCost(int timeCost)
{
    this->timeCost = timeCost;
}

/******************************************************************************
 ** GETTERS
 ******************************************************************************/

Space* Space::getAdjacent(Options::Option direction)
{
    switch (direction)
    {
        case Options::Up:    return up;
                             break;
        case Options::Right: return right;
                             break;
        case Options::Down:  return down;
                             break;
        case Options::Left:  return left;
                             break;
        default:             return nullptr;
                             break;
    }
}

int Space::getTimeCost()
{
    return timeCost;
}

bool Space::cleared()
{
    return isClear;
}

/******************************************************************************
 ** CONSTRUCTOR
 ******************************************************************************/

Space::Space() : 
item(nullptr), isClear(false), timeCost(0),
up(nullptr), right(nullptr), down(nullptr), left(nullptr)
{
}

/******************************************************************************
 ** DESTRUCTOR
 ******************************************************************************/

Space::~Space()
{
    if (item) { delete item; }
}