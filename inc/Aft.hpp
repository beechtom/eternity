/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Definition file for the Aft class.
 **         This class is derived from the Space class.
 **         Function descriptions can be found in the implementation file.
 ******************************************************************************/

#ifndef AFT_HPP
#define AFT_HPP

#include "Space.hpp"

class Aft : public Space 
{
    private:
        int totalDecrypted;

        // Actions
        void readLogs();
        void decryptLog(Inventory&);
        void genEncryptLog();

    public:
        // Actions
        void display();
        void explore(Inventory&);

        // Constructor
        Aft();
};

#endif