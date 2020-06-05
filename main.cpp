/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */






#include <iostream>
#include "LeakedObjectDetector.h"

#include "Wrappers.h"

#include "Piano.h"
#include "AudioPlugin.h"


struct Piano;
/*
struct PianoWrapper
{
    Piano* address = nullptr; //Initilaize Pointer to a Piano UDT to nullptr

    //Constructor for the PianoWrapper taking  a Pointer to a Piano UDT as an argument
    PianoWrapper(Piano* p) : 
    address(p)        //updating the Pointer named piano to the address of the UDT type pointerwe have a variable in the constructor
    {

    }
    ~PianoWrapper()
    {
        delete address; //deleting the piano pointer when the destructor is called.
    }
};
*/


/*
 copied UDT 2:
 */







/*
 copied UDT 3:
 */
struct CommonTreasureChest
{
    int numberOfItems;
    bool isOpened;
    bool isRare;  

    CommonTreasureChest(bool rarity)
    {
        this->isRare = rarity;
        this->isOpened = false;
        this->numberOfItems = 5;

        if (isRare == false)
        {
             std::cout << "This is a common chest with a Max Capacity of " << numberOfItems << std::endl;
        }
        else if (isRare == true)
        {
            std::cout << "This is a rare chest with a Max Capacity of " << numberOfItems << std::endl;
        }
    }

    ~CommonTreasureChest() 
    {
        std::cout << "This TreasureChest has been destroyed." << std::endl;
    }

    bool openChest(bool openState);
    bool closeChest(bool openState);
    void lootChest();
    int printTreasureCount();
    bool printRarity();
    void changeRarity(bool rarity);


    JUCE_LEAK_DETECTOR(CommonTreasureChest)
};

struct CommonTreasureChestWrapper
{
    CommonTreasureChest* address = nullptr;

    CommonTreasureChestWrapper(CommonTreasureChest* c) :
    address (c)
    {
    }

    ~CommonTreasureChestWrapper()
    {
        delete address;
    }
};



bool CommonTreasureChest::openChest (bool openState)
{
    if (openState == false) 
    {
        std::cout << "You've opened the Box, sadly there's nothing in it!" << std::endl;
        return true;
    }
    std::cout << "This Box is already opened.. find another one!" << std::endl;
    return false;
}

bool CommonTreasureChest::closeChest (bool openState)
{
    if (openState == true) 
    {
        std::cout << "You've closed the Box and locked it" << std::endl;
        return false;
    }
    std::cout << "You can't lock an already locked box" << std::endl;
    return true;
}

void CommonTreasureChest::lootChest ()
{
    for (int i = numberOfItems; i != 0; i -= 1 )
    {
        if (isRare == true && i == 1)
        {
            std::cout << "Legendary Item!!!" << std::endl;
            return;
        }
        std::cout << "Found a common item!" << std::endl;   
    }
}

int CommonTreasureChest::printTreasureCount()
{
    std::cout << "Treasure Count: " << this->numberOfItems << 
    " Rarity :" << this->isRare << std::endl;
    return this->numberOfItems;
}


void CommonTreasureChest::changeRarity(bool rarity)
{
    this->isRare = rarity;
}


/*
 new UDT 4:
  */

 struct PianoStore
 {
    PianoStore();
    ~PianoStore();

    Piano steinway;
    Piano practice;
    Piano toybox;

    JUCE_LEAK_DETECTOR(PianoStore)

 };

PianoStore::PianoStore() :
steinway (88),
practice (64),
toybox (24)
{
    std::cout << "The Piano Store is opened!" << std::endl;
}

PianoStore::~PianoStore()
{
     std::cout << "The Piano Store is closed!" << std::endl;
}

struct PianoStoreWrapper
{
    PianoStore* address = nullptr;

    PianoStoreWrapper(PianoStore* p) :
    address (p)
    {
    }

    ~PianoStoreWrapper()
    {
        delete address;
    }
};



/*
 new UDT 5:
*/

struct Daw 
{
    AudioPlugin equalizer;
    AudioPlugin compressor;
    AudioPlugin reverb;
    
    Daw() :
    equalizer (48000),
    compressor (48000),
    reverb (48000)
    {
        std::cout << "Showing the Daw Splashscreen" << std::endl;
    }

    ~Daw()
    {
        std::cout << "Saving Settings and closing the Software" << std::endl;
    }

    void checkInitialization ()
    {
        std::cout << "EQ:" << this->equalizer.initialized << "  Compressor:" << this->compressor.initialized << "  Reverb:" << this->reverb.initialized << std::endl;
    }

    JUCE_LEAK_DETECTOR(Daw)
};

struct DawWrapper
{
    Daw* address = nullptr;

    DawWrapper (Daw* d) :
    address (d)
    {
    }

    ~DawWrapper()
    {
        delete address;
    }
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
/*
*/
    //UDT1
    CommonTreasureChestWrapper box1 (new CommonTreasureChest(false));   
    std::cout << "This is a common chest with a Max Capacity of " << box1.address->numberOfItems << std::endl;
    
    CommonTreasureChestWrapper box2 (new CommonTreasureChest(false));   
    std::cout << "This is a rare chest with a Max Capacity of " << box2.address->numberOfItems << std::endl;

    box1.address->printTreasureCount();
    std::cout << "Rarity: " << box1.address->isRare << std::endl;
    std::cout << "Treasure Count: " << box1.address->numberOfItems << 
    " Rarity :" << box1.address->isRare << std::endl;
    std::cout << std::endl;

    //UDT2
    AudioPluginWrapper eq (new AudioPlugin(44100));
    eq.address->processAudio();
    eq.address->getData();
    std::cout << "EQ instanceID(): " <<  eq.address->instanceID() << " and EQ samplerate: " << 
    eq.address->samplerate << std::endl; 
    std::cout << std::endl;
 
    //UDT3
    PianoWrapper piano(new Piano(88));
    std::cout << "I'm a Piano with " << piano.address->range << " keys and " << piano.address->getOctaves() << " Ocavtes"<< std::endl;
    piano.address->pressSustainPedal();
    piano.address->playKeys(25,30, 1);
    piano.address->playKeys(50,80, 10);
    std::cout << std::endl;

    //UDT4 (using only UDTs)
    PianoStoreWrapper keyworld (new PianoStore());
    std::cout << "I'm a Piano with " << keyworld.address->steinway.range << " keys and " << 
    keyworld.address->steinway.getOctaves()  << " Octaves." << std::endl;
    std::cout << "I'm a Piano with " << keyworld.address->practice.range << " keys and " << 
    keyworld.address->practice.getOctaves()  << " Octaves." << std::endl;
    std::cout << "I'm a Piano with " << keyworld.address->toybox.range << " keys and " << 
    keyworld.address->toybox.getOctaves()  << " Octaves." << std::endl;
    std::cout << std::endl;

    //UDT5 (using only UDTs)
    DawWrapper cubase (new Daw());
    cubase.address->checkInitialization();
    std::cout << "EQ:" << cubase.address->equalizer.initialized << "  Compressor:" << cubase.address->compressor.initialized << "  Reverb:" << cubase.address->reverb.initialized << std::endl;



    std::cout << std::endl;
    std::cout << "good to go!" << std::endl;
    std::cout << std::endl;

}
