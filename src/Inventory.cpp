/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Implementation file for the Inventory class.
 ******************************************************************************/

#include <iostream>
#include "Inventory.hpp"
#include "Scenes.hpp"

/******************************************************************************
 ** Name  : add
 ** Desc  : Adds an item to the inventory
 ** Args  : type - The type of item
 **         item - A pointer to the item
 ** Return: 
 ******************************************************************************/

void Inventory::add(Options::Option type, Item* item)
{
    inventory.emplace(std::make_pair(type, item));
} 

/******************************************************************************
 ** Name  : grab
 ** Desc  : 'Grabs' an item by removing it from the inventory and returning its
 **         pointer
 ** Args  : type - The item type
 ** Return: A pointer to the item
 ******************************************************************************/

Item* Inventory::grab(Options::Option type)
{
    Item* item = nullptr;
    auto itr   = inventory.find(type);

    // Item type is in inventory
    if (itr != inventory.end())
    {
        item = itr->second;
        inventory.erase(itr);
    }

    return item;
} 

/******************************************************************************
 ** Name  : check
 ** Desc  : Checks if there are any items of a specific type in the inventory
 ** Args  : type - The item type
 ** Return: The number of items of that type
 ******************************************************************************/

int Inventory::check(Options::Option type)
{
    return inventory.count(type);
}

/******************************************************************************
 ** Name  : clear
 ** Desc  : Clears all items from the inventory
 ** Args  :
 ** Return: 
 ******************************************************************************/

void Inventory::clear()
{
    for (auto itr = inventory.begin(); itr != inventory.end(); itr++)
    {
        if (itr->second) { delete itr->second; }
    }
}

/******************************************************************************
 ** Name  : display
 ** Desc  : Displays the contents of the inventory
 ** Args  :
 ** Return: 
 ******************************************************************************/

void Inventory::display()
{
    int count = 1;

    Screen::clearSpace();
    Scenes::inventoryTitle();

    if (inventory.empty())
    {
        std::cout << "Your inventory is empty." << std::endl;
    }

    for (auto itr = inventory.begin(); itr != inventory.end(); itr++)
    {
        if (itr->second)
        {
            std::cout << "[" << count << "] "
                      << itr->second->type << " " << itr->second->id
                      << std::endl;
        }

        count++;
    }

    Screen::pause();
}

/******************************************************************************
 ** DESTRUCTOR
 ******************************************************************************/

Inventory::~Inventory()
{
    clear();
}