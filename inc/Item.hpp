/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Definition file for the Item struct.
 ******************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include "Utilities.hpp"

struct Item 
{
    std::string type;
    std::string id;
    bool        isActive;

    // Set the type and status, generate random ID
    Item(std::string type) : type(type), isActive(false)
    {
        for (int i = 0; i < 5; i++)
        {
            id += std::to_string(Util::getRandom(1, 3));
        }
    }
};

#endif