/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 04/15/2018
 ** Desc  : A variety of input validation functions.
 ******************************************************************************/

#include <iostream>
#include <cctype>
#include <limits>
#include <fstream>
#include "Utilities.hpp"

/******************************************************************************
 ** Name  : Util::getRandom (int)
 ** Desc  : A function that generates a random integer within a specified range.
 ** Args  : int max - The upper bound of the range.
 **         int min - The lower bound of the range. Default is 0.
 ** Return: A random integer.
 ******************************************************************************/

int Util::getRandom(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

/******************************************************************************
 ** Name  : displayTextFromFile
 ** Desc  : Reads a specified text file and displays it to the screen.
 ** Args  : filename - Name of the file to read.
 ** Return:
 ******************************************************************************/

void Util::printTextFile(std::string filename)
{
    std::ifstream infile;
    std::string   fileline;

    infile.open(filename);

    if (infile)
    {
        while (getline(infile, fileline))
        {
            std::cout << fileline << std::endl;
        }
    }

    infile.close();
}

/******************************************************************************
 ** Name  : Input::getCharLive
 ** Desc  : Reads a character from the input buffer without pressing enter
 ** Args  : 
 ** Return: The character that was input
 ******************************************************************************/

char Input::getCharLive()
{
    char input = '?';
    system("stty raw");
    std::cout << ">> ";
    std::cin.get(input);
    input = toupper(input);
    system("stty cooked");
    return input;
}

/******************************************************************************
 ** Name  : Screen::clear
 ** Desc  : Clears the screen and returns the cursor to the top left
 ******************************************************************************/

void Screen::clearAll()
{
    std::cout << "\033[H\033[J";
}

/******************************************************************************
 ** Name  : Screen::clearSpace
 ** Desc  : Clears the screen of the current room & the menu
 ******************************************************************************/

void Screen::clearSpace()
{
    std::cout << "\033[9H\033[J";
}

/******************************************************************************
 ** Name  : Screen::clearDesc
 ** Desc  : Clears the description of the current room & the menu
 ******************************************************************************/

void Screen::clearDesc()
{
    std::cout << "\033[12H\033[J\033[B";
}

/******************************************************************************
 ** Name  : Screen::clearMenu
 ** Desc  : Clears the screen of the current menu
 ******************************************************************************/

void Screen::clearMenu()
{
    std::cout << "\033[36H\033[J";
}

/******************************************************************************
 ** Name  : Screen::clearLine
 ** Desc  : Clears the line
 ******************************************************************************/

void Screen::clearLine()
{
    std::cout << "\r\033[K";
}

/******************************************************************************
 ** Name  : Screen::pause
 ** Desc  : Clears the line
 ******************************************************************************/

void Screen::pause()
{
    Screen::clearMenu();

    std::cout << "\n\n--------------------------------------------------"
              << "--------------------------------------------------\n"
              << "Press Any Key To Continue"
              << "\n--------------------------------------------------"
              << "--------------------------------------------------\n"
              << std::endl;

    Input::getCharLive();
}

/******************************************************************************
 ** Name  : Screen::prompt
 ** Desc  : Displays a prompt to the screen
 ******************************************************************************/

void Screen::prompt(std::string text)
{
    Screen::clearMenu();

    std::cout << "\n\n--------------------------------------------------"
              << "--------------------------------------------------\n"
              << text
              << "\n--------------------------------------------------"
              << "--------------------------------------------------\n"
              << std::endl;
}