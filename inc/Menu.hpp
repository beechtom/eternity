/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Definition file for the Menu class.
 **         Function descriptions can be found in the implementation file.
 ******************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <unordered_map>
#include <utility>
#include <string>
#include <iostream>
#include "Utilities.hpp"

template <class T>
class Menu
{
    private:
        std::unordered_map<char, std::pair<std::string, T>> options;
        std::string order;

    public:
        void addOption(char, std::string, T);
        void removeOption(char);
        void displayOptions();
        T    chooseOption(); 
};

/******************************************************************************
 ** Name  : addOption
 ** Desc  : Adds a option to the menu
 ** Args  : text   - The option description
 **         action - The resulting action for the option
 ** Return:
 ******************************************************************************/

template <typename T>
void Menu<T>::addOption(char key, std::string text, T action)
{
    options.insert(std::make_pair(key, std::make_pair(text, action)));
    order += key;
}

/******************************************************************************
 ** Name  : chooseOption
 ** Desc  : Displays all menu options and prompts user to choose one
 ** Args  :
 ** Return: The action for the chosen option
 ******************************************************************************/

template <typename T>
void Menu<T>::displayOptions()
{
    Screen::clearMenu();

    std::cout << "\n\n--------------------------------------------------"
              << "--------------------------------------------------\n";

    for (int i = 0, size = order.size(); i < size; i++)
    {
        auto itr = options.find(order[i]);

        if (itr != options.end())
        {
            std::cout << "[" << itr->first << "] " << itr->second.first 
                      << "     ";        
        }
    }

    std::cout << "\n--------------------------------------------------"
              << "--------------------------------------------------\n\n";
}

/******************************************************************************
 ** Name  : removeOption
 ** Desc  : Removes a specified option from the menu
 ** Args  : key - The menu option to remove
 ** Return:
 ******************************************************************************/

template <typename T>
void Menu<T>::removeOption(char key)
{
    options.erase(key);
}

/******************************************************************************
 ** Name  : chooseOption
 ** Desc  : Prompts the user to choose from the menu options
 ** Args  :
 ** Return: The action for the chosen option
 ******************************************************************************/

template <typename T>
T Menu<T>::chooseOption()
{
    while (true)
    {
        auto search = options.find(Input::getCharLive());

        if (search != options.end())
        {
            return search->second.second;
        }
        else
        {
            Screen::clearLine();
        }
    };
}

#endif