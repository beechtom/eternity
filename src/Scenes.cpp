/******************************************************************************
 ** Author: Thomas Beech
 ** Date  : 06/12/2018
 ** Desc  : Implementation file for the the various Scene functions.
 ******************************************************************************/

#include <iostream>
#include "Scenes.hpp"

/******************************************************************************
 ** GAME
 ** Functions to display Game text
 ******************************************************************************/

void Scenes::gameEnd()
{
    std::cout
    << "----------------------------------------------------------------------------------------------------\n"
    << "???\n"
    << "----------------------------------------------------------------------------------------------------\n\n"
    << "For a split second you feel an unbelievably strong shaking. Time itself seems to come to come to a\n"
    << "standstill before tearing at the seams. Everything turns to black."
    << std::endl;
}

void Scenes::gameStart()
{
    std::cout
    << "\033[9H"
    << "----------------------------------------------------------------------------------------------------\n"
    << "???\n"
    << "----------------------------------------------------------------------------------------------------\n\n"
    << "A bang and a flash of white light. You blink your eyes repeatedly as your vision begins to clear. \n"
    << "You look around, unsure of how you got here. What's going on?"
    << std::endl;
}

/******************************************************************************
 ** AFT
 ** Functions to display Aft text
 ******************************************************************************/

void Scenes::aftDisplay()
{
    std::cout
    << "----------------------------------------------------------------------------------------------------\n"
    << "AFT\n"
    << "----------------------------------------------------------------------------------------------------\n\n"
    << "You are in a room flooded with red light.\n\n"
    << "In the center of the room is the ship's primary aft station. Surrounding each side of the primary\n"
    << "station are several substations. Each station has a specific purpose - such as analyzing the\n"
    << "outside environment, managing crew missions, and monitoring life support systems.\n\n"
    << "Maybe one of these stations can provide more information..."
    << std::endl;
}

void Scenes::aftExplore()
{
    std::cout
    << "You walk toward the primary station. The control panel in front of it has dozens of blinking red\n"
    << "lights on it, each vying for your attention. That can't be good. As you near the station, a short\n"
    << "message appears on the display.\n\n"
    << "                       CRITICAL SYSTEMS FAILURE\n"
    << "                       Multiple critical systems failures have been detected.\n"
    << "                       All systems logs have been encrypted for security.\n"
    << "                       To decrypt logs, authorized crew members shall load a\n"
    << "                       codec into the station's data port."
<< std::endl;
}

void Scenes::aftLogMenu()
{
    std::cout
    << "COLONY SHIP ETERNITY SYSTEM LOGS\n\n"
    << "[1] Error  Log 0x0000-1\n"
    << "[2] System Log 0xA0EB-2\n"
    << "[3] System Log 0xC46E-3\n"
    << "[4] System Log 0xA89F-4\n"
    << "[5] System Log 0xDD33-5\n"
    << "[6] System Log 0x1992-6\n"
    << "[7] System Log 0x42AZ-7\n"
    << "[8] Exit"
    << std::endl;
}

void Scenes::aftLog1()
{
    std::cout
    << "ERROR LOG [0x0000-1]\n\n"
    << "HULL INTEGRITY COMPROMISED [12%]\n"
    << "System has detected increased stress to the ship's hull.\n\n"
    << "FUEL RESERVES CRITICAL [3%]\n"
    << "System has detected low fuel reserves.\n\n"
    << "NETWORK COMPROMISED [ENCRYPTED]\n"
    << "System has detected electrical fluctations in the network. All systems logs have been encrypted.\n\n"
    << "LIFE SUPPORT BACKUP POWER SUPPLY [0%]\n"
    << "System has detected no backup power supply to ship's Cradles.\n"
    << "Backup power supply must be intsalled prior to cradle detachment.\n\n"
    << "UNRECOVERABLE CRITICAL SYSTEM FAILURE\n"
    << "Systems cannot be restored. Access Critical System Failure Protocol from Main Command Station."
    << std::endl;
}

void Scenes::aftLog2()
{
    std::cout
    << "SYSTEM LOG [0xA0EB-2]\n"
    << "LOGGED BY : LA\n\n"
    << "During the past several weeks the ship's instruments have begun to notice gravitational fluctuations\n"
    << "from a nearby star system. Additional observations the crew have conducted prove promising -\n"
    << "by all accounts the star system is host to several potentially habitable planets. However, it's\n"
    << "difficult to know for sure without gathering more data, which requires a closer visit.\n\n"
    << "Admiral Adama has since set the ship's course for this star system. The navigation system shows\n"
    << "that we should arrive to the outer limits of the system in about 4 1/2 years' time. Until then,\n"
    << "the crew will rejoin the passengers in cryogenic sleep as the ship guides us to what will hopefully\n"
    << "be our new home.\n\n"
    << "SYSTEM MODIFICATIONS\n"
    << "Network security system updated. In the event of a network system failure, all system logs will be\n"
    << "encrypted. System logs can be decrypted using 1 of the 10 codecs aboard the ship."
    << std::endl;
}

void Scenes::aftLog3()
{
    std::cout
    << "SYSTEM LOG [0xC46E-3]\n"
    << "LOGGED BY : LA\n\n"
    << "The unthinkable has happened. It has been nearly 10 years since the ship was set on course for a\n"
    << "nearby star system and the crew entered cryogenic sleep. As far as we are aware, the journey to the\n"
    << "system went smoothly. However, we did not anticipate what lied lurking at our destination.\n\n"
    << "Our previous attempts to fully observe the star system had been impeded by various factors - light\n"
    << "clouding our sight, gravitational fluctuations messing with our equipment... What we had been able\n"
    << "to observe was a binary star system. The two stars were caught in a dance, circling around one\n"
    << "another at a relatively close distance. Had we known what these two stars were dancing around, we\n"
    << "never would have approached the system."
    << std::endl;
}

void Scenes::aftLog4()
{
    std::cout
    << "SYSTEM LOG [0xA89F-4]\n"
    << "LOGGED BY : LA\n\n"
    << "What we had thought was a binary star system ended up being a ternary system. Unlike the other two\n"
    << "bodies we had already observed in the system, however, the third was a black hole. What we once\n"
    << "assumed were innocuous gravitational fluctuations turned out to be the outer edges of the black\n"
    << "hole's strong gravitational pull.\n\n"
    << "Unfortunately, not much is known about black holes. How could we have anticipated the damage our\n"
    << "electrical systems would take in such close proximity to this monster? From what we can gather from\n"
    << "the fragmented file systems in the ship's data centers, the gravitational field of the black hole\n"
    << "began to pull us off course just a scant few weeks before we were due to come out of cryogenic\n"
    << "sleep.\n\n"
    << "Once our ship approached closer to the black hole's event horizon, the ship's systems began\n"
    << "to fail en masse. It was only until recently that the Cradle's mechanical failsafe triggered, and\n"
    << "awoke the crew from sleep after 10 years. We quickly discovered that our ship was trapped at the\n"
    << "edge of the black hole's event horizon, with the engines desparately trying to pull us away as our\n"
    << "fuel reserves deplete."
    << std::endl;
}

void Scenes::aftLog5()
{
    std::cout
    << "SYSTEM LOG [0xDD33-5]\n"
    << "LOGGED BY : LA\n\n"
    << "The likeliehood of the ship escaping the black hole's gravitational field is looking slimmer by the\n"
    << "day. Only a handful of the crew know of the position we are in - the bridge of the ship is nearly\n"
    << "touching the event horizon. One fascinating, yet truly terrifying, effect of being so close to a\n"
    << "black hole is time dilation. As we move closer to the bridge, time moves slower relative to the\n"
    << "Cradles and the ship's engines... this poses a problem as our feel reserves appear to deplete\n"
    << "more quickly as we approach the bridge.\n\n"
    << "Because of this we have been careful in how we prepare for the Cradle Detachment Sequence. Most of\n"
    << "the crew has been sent back to cryogenic sleep to simplify preparations. The rest of us have since\n"
    << "been working on locating the ship's Codecs and Master Keys which will be necessary for initiating\n"
    << "the sequence from the Bridge. Each of the Codecs is entrusted to a senior crew member, and should be\n"
    << "located in their living quarters. Each Master Key is in a storage vault, which are sealed behind a\n"
    << "logic lock. Admiral Adama informed us that each vault has a randomly generated, 5-digit passcode,\n"
    << "where each digit is determined by finding the difference of the digits on the vault's display..."
    << std::endl;
}

void Scenes::aftLog6()
{
    std::cout
    << "SYSTEM LOG [0x1992-6]\n"
    << "LOGGED BY : LA\n\n"
    << "We've begun to notice that the effects of a black hole are more far-reaching than we had realized.\n"
    << "Not only does the black hole seem to bend spacetime and interfere with our electrical equipment, but\n"
    << "it seems to almost... tear spacetime. We aren't 100% certain yet, but we believe these tears open\n"
    << "up windows into parallel realities.\n\n"
    << "We began to suspect this after searching for the senior crew's codecs in vain. Some of the crew\n"
    << "reported running into shadowy figures that lurked within the ship's living quarters. They would\n"
    << "appear suddenly out of a shimmer in the air. While most of the crew ran from these apparitions, some\n"
    << "stood their ground and fired their phase guns at them. Upon doing so, the shadow would disappear\n"
    << "and sometimes leave behind an object. These objects ranged from codecs to power cells. We are\n"
    << "starting to suspect that these intruders may also be stealing the items we seek, as we have been\n"
    << "unable to locate the objects we seek."
    << std::endl;
}

void Scenes::aftLog7()
{
    std::cout
    << "SYSTEM LOG [0x42AZ-7]\n"
    << "LOGGED BY : LA\n\n"
    << "Last night things took a turn for the worse. A gravitational pulse from the black hole fried nearly\n"
    << "all of the ship's remaining systems, including the Cradles' backup power supplies. The crew has\n"
    << "begun to lose hope as the realization sinks in that our even if we were to detach the Cradles they\n"
    << "would not be able to survive without power.\n\n"
    << "I must admit that I am also beginning to look at our situation bleakly, but for different reasons\n"
    << "altogether. I had been sending the crew back to their cryogenic chambers - offering them what little\n"
    << "hope of ignorance of their fate I could - when one of our physicists approached me. They had come to\n"
    << "inform me that were we to successfully detach the cradles, everyone on the bridge at the time would\n"
    << "perish instantly.\n\n"
    << "You see, once the sequence is initiated, a 30-minute timer countsdown to the Cradles' detachment -\n"
    << "and with them the ship's engines. Time dilation is so strong near the bridge that the Cradles and\n"
    << "engines will have separated long since, leaving the remainder of the ship to hurtle towards the\n"
    << "black hole. But in an act of bravery I did not expect, this physicist volunteered to stay behind and\n"
    << "initiate the Cradle Detachment Sequence on their own - giving their own life to save the rest of us.\n\n"
    << "This is what I expect to be my last log before I head to the Cradle. To this lone crew member who\n"
    << "chose to stay behind - thank you. May you be remembered for Eternity."
    << std::endl;
}

void Scenes::aftSuccess()
{
    std::cout
    << "You take a codec from your comm device and insert it into the station's data port. After a few\n"
    << "seconds the display shows a message.\n\n"
    << "                             CODEC HAS BEEN CLEARED\n"
    << "                             SYSTEMS LOG SUCCESSFULLY DECRYPTED"
    << std::endl;
}

void Scenes::aftFail()
{
    std::cout
    << "You start to reach towards your comm device, but stop when you realize you don't have a codec yet.\n\n"
    << "Maybe you should work on that..."
    << std::endl;
}

void Scenes::aftComplete()
{
    std::cout
    << "                             ALL LOGS ARE NOW DECRYPTED"
    << std::endl;
}

/******************************************************************************
 ** LIVING QUARTERS
 ** Functions to display Living Quarters text
 ******************************************************************************/

void Scenes::battleDisplay()
{
    std::cout
    << "----------------------------------------------------------------------------------------------------\n"
    << "LIVING QUARTERS\n"
    << "----------------------------------------------------------------------------------------------------\n\n"
    << "You walk into an empty corridor. Some of the lights are randomly flickering and forgotten belongings\n"
    << "litter the ground. You feel a profound sense of despair.\n\n"
    << "You're in one of the ship's living quarters, designed to support a few hundred families. Behind the\n"
    << "doors in the corridor are various spaces - people's homes, leisure spaces, classrooms... everything\n"
    << "needed to support a small community.\n\n"
    << "You might be able to find something helpful here..."
    << std::endl;
}

void Scenes::battleExplore()
{
    std::cout
    << "You walk into one of the rooms off the corridor. It's dark, so you turn on your comm device's\n"
    << "light to guide your way. As you sweep the light across the room, you see a slight shimmer in the\n"
    << "air, almost like a heat haze.\n\n"
    << "A shadowy figure steps forth from the shimmer. It looks vaguely human, but it's hard to tell, as\n"
    << "the edges of its body fade into nothing. The hairs on the back of your neck stand on end, and\n"
    << "you feel a slight unease. The shadowy figure begins to raise one of its limbs, and it seems like\n"
    << "it's holding a weapon of some sort.\n\n"
    << "You clutch the phase gun holstered to your side. You need to make a decision quickly on whether to\n"
    << "stand your ground and fight, or run away from this creature..."
    << std::endl;
}

void Scenes::battleQuickdraw()
{
    std::cout
    << "You quickly rip your phase gun from its holster. Muscle memory kicks in as you set your phase gun\n"
    << "and fire a..."
    << std::endl;
}

void Scenes::battleWin()
{
    std::cout
    << "Your pulse fires out of your phase gun and hits the shadowy figure's raised limb. It vanishes from\n"
    << "sight as suddenly as it had first appeared.\n"
    << std::endl;
}

void Scenes::battleLose()
{
    std::cout
    << "Your finger begins to squeeze the trigger when you hear a click. Before you have time to process\n"
    << "what the noise was, a pulse hits your comm device and the shadowy figure disappears from sight. You\n"
    << "take a step back, shocked at how quickly the figure had fired at you and thankful that you didn't\n"
    << "take a direct hit.\n"
    << std::endl;
}

void Scenes::battleDraw()
{
    std::cout
    << "You and the shadowy figure fire pulses at each other in unison. A bright white light flashes and a\n"
    << "loud crack echos around the room as the two pulses collide. As the light begins to fade you think\n"
    << "quickly and decide to fire a..."
    << std::endl;
}

void Scenes::battleGetItem()
{
    std::cout
    << "A small flash of light appears where the apparition once stood. You hear a sharp crack and then\n"
    << "a sound of somethingan object dropping on the floor.\n\n"
    << "You walk over to inspect the object, realizing that it's one of the ship's codecs. Bemused, you\n"
    << "pick it up and slip it into one of the data ports on your comm device for safe-keeping."
    << std::endl;
}

void Scenes::battleLoseItem()
{
    std::cout
    << "As you leave the now-empty room, you look down at your comm device. The pulse must have hit one of\n"
    << "the codecs, as the data port is now empty..."
    << std::endl;
}

/******************************************************************************
 ** BRIDGE
 ** Functions to display Bridge text
 ******************************************************************************/

void Scenes::bridgeDisplay()
{
    std::cout
    << "----------------------------------------------------------------------------------------------------\n"
    << "BRIDGE\n"
    << "----------------------------------------------------------------------------------------------------\n\n"
    << "The door opens - you see nothing but darkness. You feel a deep foreboding as you step into the room.\n\n"
    << "You switch on your comm device's flashlight, which provides a dim light for you to see by. Standing\n"
    << "quietly in the center of the room is the Command Station, flanked on either side by two Sub-Command\n"
    << "stations.\n\n"
    << "You remember the ship's Emergency Protocols Manual mentioning that each of the stations must be\n"
    << "activated at the same time to detach the Cradles..."
    << std::endl;
}

void Scenes::bridgeIncomplete()
{
    std::cout
    << "You approach the Command Station and boot the control system. After a few moments, the display turns\n"
    << "on and you navigate to the emergency protocol subsystem. A set of instructions appears on the\n"
    << "display.\n\n"
    << "                    CRITICAL SYSTEM FAILURE - CRADLE DETACHMENT PROTOCOL\n"
    << "                    In the event of system-wide failures, the crew should detach\n"
    << "                    the ship's Cradles. To ensure security of the cradles, all 4\n"
    << "                    lieutenants must insert decrypted master keys into each of\n"
    << "                    the sub-command stations. After inserting all 4 keys, the\n"
    << "                    detach sequence may be triggered from the main command\n"
    << "                    station.\n\n"
    << "Before you initiate the detach sequence, you'll need to make sure the Cradles' life-support systems\n"
    << "are secured and locate the 4 master keys..."
    << std::endl;
}

void Scenes::bridgeComplete()
{
    std::cout
    << "The Command Station's display shows a countdown in large, bold numbers. You realize you should\n"
    << "probably get to one of the Cradles as soon as you can.\n\n\n\n\n\n\n"
    << "Unless you want to experience spaghettification first-hand..."
    << std::endl;
}

void Scenes::bridgeSuccess1()
{
    std::cout
    << "You grab each of the 4 master keys from your pack, insert them into their respective receptacles at\n"
    << "each station, and lock them into place with a quick twist and a satisfying click.\n\n"
    << "All that's left is to trigger the detach sequence..."
    << std::endl;
}

void Scenes::bridgeSuccess2()
{
    std::cout
    << "You reach down to the keyboard in front of the command station's display and navigate to the\n"
    << "Cradle Detachment Protocol. After entering your passcode, the display shows a short instruction.\n\n"
    << "                              IDENTITY VERIFIED . . .\n"
    << "                              MASTER KEYS DETECTED . . .\n"
    << "                              INITIATING CRADLE DETACHMENT SEQUENCE . . .\n\n"
    << "                              TO ABORT, REMOVE ANY OF THE MASTER KEYS\n"
    << "                              OR PRESS ANY KEY TO CONTINUE"
    << std::endl;
}

void Scenes::bridgeFail1()
{
    std::cout
    << "You begin to reach into your pack but realize you still haven't found all 4 decrypted master keys.\n\n"
    << "Maybe you should work on that..."
    << std::endl;
}

void Scenes::bridgeFail2()
{
    std::cout
    << "You can't start the detachment sequence until you have inserted all 4 decrypted master keys into\n"
    << "the sub-command stations.\n\n"
    << "Maybe you should work on that..."
    << std::endl;
}

/******************************************************************************
 ** DATA CENTER
 ** Functions to display Data Center text
 ******************************************************************************/

void Scenes::cipherDisplay()
{
    std::cout
    << "----------------------------------------------------------------------------------------------------\n"
    << "DATA CENTER\n"
    << "----------------------------------------------------------------------------------------------------\n\n"
    << "The door opens and you walk into a wall of hot air. It looks like you're in one of the ship's data\n"
    << "centers.\n\n"
    << "Filling the room are hundreds of racks of equipment. Each of the data centers serves a different\n"
    << "purpose - from managing the navigation systems to storing the history of humankind. You're not sure\n"
    << "which is which, but that doesn't matter right now. It looks like most of the equiment has failed.\n\n"
    << "There might be something here to help you detach the Cradles..."
    << std::endl;
}

void Scenes::cipherComplete()
{
    std::cout
    << "You walk up and down the racks of equipment, checking if any of it is still functional. After an\n"
    << "exhaustive search, you find nothing that you can use."
    << std::endl;
}

void Scenes::cipherIncomplete()
{
    std::cout
    << "You walk the perimeter of the room, checking if any of the equipment is still functioning. After a\n"
    << "couple of minutes, you come across a work station that looks like it's still powered on. The station\n"
    << "should have a program installed that can decrypt the master keys.\n\n"
    << "You tap the display, which flickers on and shows a prompt asking you to enter your credentials. Once\n"
    << "you enter your credentials, you navigate through the system's menus and launch the decrypter.\n\n"
    << "MASTER DECRYPTION STATION\n"
    << "TO DECRYPT MASTER KEY, PLACE KEY IN RECEPTACLE\n"
    << "AND INSERT CODEC INTO DATA PORT"
    << std::endl;
}

void Scenes::cipherSuccess()
{
    std::cout
    << "You reach into your pack to grab a key and place it into the work station's receptacle. A short\n"
    << "message appears on the display, confirming that the key was inserted properly.  You then remove a\n"
    << "codec from your comm device and insert it into the station's data port.\n\n"
    << "Another short message appears on the screen, along with a button that reads 'DECRYPT'. You\n"
    << "press it. After a couple of seconds, the work station emits three rapid beeps.\n\n"
    << "MASTER KEY SUCCESSFULLY DECRYPTED\n"
    << "CODEC HAS BEEN DESTROYED\n\n"
    << "You remove the key from the receptacle. As you place it in your pack, the work station suddenly\n"
    << "turns off. You attempt to turn it back on, but it looks like decrypting the key used up what little\n"
    << "life it had left in it."
    << std::endl;
}

void Scenes::cipherFail()
{
    std::cout
    << "You start to reach towards your pack, but stop when you realize you don't have both a master key\n"
    << "and a codec yet.\n\n"
    << "Maybe you should work on that..."
    << std::endl;
}

/******************************************************************************
 ** CRADLE
 ** Functions to display Cradle text
 ******************************************************************************/

void Scenes::cradleDisplay()
{
    std::cout
    << "----------------------------------------------------------------------------------------------------\n"
    << "CRADLE\n"
    << "----------------------------------------------------------------------------------------------------\n\n"
    << "You step into a small airlock and the door seals shut behind you. A kind voice speaks from somewhere\n"
    << "near you.\n\n"
    << "                       INITIATING DECONTAMINATION PROCESS. PLEASE STANDBY.\n\n"
    << "You feel a gentle rush of air wash over you. After a few seconds it stops and the door in front of\n"
    << "you opens.\n\n"
    << "In the next room you hear the soft, rythmic beeps of thousands of life-support systems. Arranged in\n"
    << "rings around the center of the room are the ship's cryo-chambers - each containing the future of the\n"
    << "human race.\n\n"
    << "Before you detach the Cradles from the ship, you'll need to make sure the life-support systems are\n"
    << "powered and secured..."
    << std::endl;
}

void Scenes::cradleComplete()
{
    std::cout
    << "You approach the Cradle's control center and glance over the system's status. It looks like\n"
    << "everything is in working order."
    << std::endl;
}

void Scenes::cradleIncomplete()
{
    std::cout
    << "You walk towards the center of the Cradle, brushing your fingertips along the tops of the\n"
    << "cryo-chambers as you move past them. In the center of the room is a tall, metal pillar that\n"
    << "stretches into the darkness above you. Lining the sides of the pillar are thin strips of red light,\n"
    << "each of which terminate in a ring of displays surrounding the base of the pillar. You've found the\n"
    << "Cradle's control center.\n\n"
    << "You approach the control center and examine the system's status. A warning flashes on the screens.\n\n"
    << "                                   LIFE-SUPPORT SYSTEMS UNSECURED\n"
    << "                                 PLEASE INSTALL BACKUP POWER SUPPLY\n\n"
    << "To the right of the screen you are in front of is small chamber for a power cell..."
    << std::endl;
}

void Scenes::cradleSuccess()
{
    std::cout
    << "You reach into your pack and grab one of the power cells you collected earlier. The cell has a\n"
    << "soft, green glow, and feels warm to the touch. You approach the Cradle's control center, lift the\n"
    << "cover to the power cell chamber, and push the cell into place.\n\n"
    << "You step back as the control center emits a solitary beep, and a kind voice begins to speak...\n\n"
    << "                                   BACKUP POWER SUPPLY DETECTED\n"
    << "                                      ALL SYSTEMS ARE SECURE"
    << std::endl;
}

void Scenes::cradleFail()
{
    std::cout
    << "You start to lift the cover to the power cell chamber before remembering that you don't have a\n"
    << "power cell.\n\n"
    << "Maybe you should go find one and come back later..."
    << std::endl;
}

/******************************************************************************
 ** POWER PLANT
 ** Functions to display Power Plant text
 ******************************************************************************/

void Scenes::displayPower()
{
    std::cout
    << "----------------------------------------------------------------------------------------------------\n"
    << "POWER PLANT\n"
    << "----------------------------------------------------------------------------------------------------\n\n"
    << "As you walk through the door you hear a faint humming noise and the occasional crackle of\n"
    << "electricity. It looks like you're in one of the ship's power plants.\n\n"
    << "The room is filled with what looks like dozens of rows of generators. You remember the Operations\n"
    << "Manual mentioning that the generators directly power the ship's systems and that each plant also\n"
    << "has a nuclear cell for emergency power generation.\n\n"
    << "If you can find a cell, it may prove useful..."
    << std::endl;
}

void Scenes::rulesPower()
{
    std::cout
    << "You approach the power cell and see a small sign with instructions posted next to it.\n\n"
    << "                                   PULL LEVERS IN ORDER TO UNLOCK\n"
    << "                                          POWER CELL #"
    << std::endl;
}

void Scenes::completePower()
{
    std::cout
    << "You walk along the rows of generators for a while, but can't seem to find anything useful."
    << std::endl;
}

void Scenes::incompletePower()
{
    std::cout
    << "You walk along the rows of generators for a few minutes until you spot a soft green glow out of the\n"
    << "corner of your eye. As you approach the source of the glow you realize it's a small nuclear power\n"
    << "cell. It looks like it's locked into place.\n\n"
    << "This cell could be useful for keeping some critical systems functioning after you detach the\n"
    << "Cradles. What do you do?"
    << std::endl;
}

/******************************************************************************
 ** STORAGE VAULT
 ** Functions to display Storage Vault text
 ******************************************************************************/

void Scenes::vaultDisplay()
{
    std::cout
    << "----------------------------------------------------------------------------------------------------\n"
    << "STORAGE VAULT\n"
    << "----------------------------------------------------------------------------------------------------\n\n"
    << "As you open the door you're hit by a blast of cold air. It looks like you're in one of the ship's\n"
    << "storage vaults.\n\n"
    << "You look left and right. There are rows of safes as far as you can see. Each of these safes\n"
    << "contains someone's memories and personal belongings.\n\n"
    << "You recall that the ship's Master Keys are stored somewhere in here..."
    << std::endl;
}

void Scenes::vaultComplete()
{
    std::cout
    << "You look around at some nearby safes. None of them look like they would hold anything useful."
    << std::endl;
}

void Scenes::vaultIncomplete()
{
    std::cout
    << "You start to stroll down the aisle in front of you when you notice a large, red sign hanging from\n"
    << "the column to your left.\n\n"
    << "                                         EMERGENCY SUPPLIES\n"
    << "                                                 _\n"
    << "                                                | |\n"
    << "                                               _| |_\n"
    << "                                               \\   /\n"
    << "                                                \\ /\n"
    << "                                                 V\n\n"
    << "How subtle.\n\n"
    << "You walk over to the safe directly below the sign. The door of the safe is completely blank, save\n"
    << "for a small display, a keypad, and a handle."
    << std::endl;
}

void Scenes::vaultSuccess()
{
    std::cout
    << "You hear a faint click as the display on the safe shows a new message.\n\n"
    << "                                           ACCESS GRANTED\n\n"
    << "The door to the safe pops open gently. You pull it the rest of the way open and look inside.\n"
    << "Sitting in the center of the safe is one of the ship's Master Keys - a small cylindrical object\n"
    << "with three long pins protruding from the end.\n\n"
    << "You slip the key into your pack. It will need to be decrypted before it's of any use..."
    << std::endl;
}

void Scenes::vaultFail()
{
    std::cout
    << "You hear three high-pitched, rapid beeps. The display on the safe shows a new message.\n\n"
    << "                                           ACCESS DENIED\n\n"
    << "Clearly that wasn't the correct combination..."
    << std::endl;
}

/******************************************************************************
 ** TITLES
 ** Functions to display title text
 ******************************************************************************/

void Scenes::inventoryTitle()
{
    std::cout
    << "----------------------------------------------------------------------------------------------------\n"
    << "YOUR INVENTORY\n"
    << "----------------------------------------------------------------------------------------------------\n"
    << std::endl;
}

void Scenes::gameTitle()
{
    std::cout
    << "----------------------------------------------------------------------------------------------------\n"
    << "COLONY SHIP: ETERNITY\n"
    << "----------------------------------------------------------------------------------------------------\n"
    << std::endl;
}