/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Definition file for the Scene functions.
 ******************************************************************************/

#ifndef SCENES_HPP
#define SCENES_HPP

namespace Scenes 
{
    // Game
    void gameEnd();
    void gameStart();

    // Aft
    void aftDisplay();
    void aftExplore();
    void aftLogMenu();
    void aftLog1();
    void aftLog2();
    void aftLog3();
    void aftLog4();
    void aftLog5();
    void aftLog6();
    void aftLog7();
    void aftSuccess();
    void aftFail();
    void aftComplete();

    // Living Quarters
    void battleDisplay();
    void battleExplore();
    void battleQuickdraw();
    void battleWin();
    void battleLose();
    void battleDraw();
    void battleGetItem();
    void battleLoseItem();

    // Bridge
    void bridgeDisplay();
    void bridgeIncomplete();
    void bridgeComplete();
    void bridgeSuccess1();
    void bridgeSuccess2();
    void bridgeFail1();
    void bridgeFail2();

    // Data Center
    void cipherDisplay();
    void cipherComplete();
    void cipherIncomplete();
    void cipherSuccess();
    void cipherFail();
    
    // Cradle
    void cradleDisplay();
    void cradleComplete();
    void cradleIncomplete();
    void cradleSuccess();
    void cradleFail();

    // Power Plant
    void displayPower();
    void rulesPower();
    void completePower();
    void incompletePower();

    // Storage Vault
    void vaultDisplay();
    void vaultComplete();
    void vaultIncomplete();
    void vaultSuccess();
    void vaultFail();

    // Titles
    void inventoryTitle();
    void gameTitle();
}

#endif