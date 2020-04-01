/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3 and will take you through how to write code that doesn't leak as well as how to refactor. 

 Destructors

 If you didn't do Project3, write 3 UDTs below (where it asks for Copied UDTs) that have: 
        member functions,
        member variables, 
        constructors that initialize the members. 
        for() or while() loops that modify member variables
        
 Define your implementations of all functions OUTSIDE of the class. 
 Then do instruction 2)
 
 If you DID do Project 3, do instruction 1)
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 6) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */
#include <iostream>
/*
 copied UDT 1:
 */
struct Piano 
{
    Piano(int keyrange);
    ~Piano();

    int range;
    char color;

    void pressSustainPedal();
    void releaseSustainPedal();
    void playKeys(int startingKey, int endingKey, int noteSteps);
};

Piano::Piano(int keyrange) : 
range(keyrange),
color('b')
{
    if (color == 'b')
    {
        std::cout << "I'm a Piano with " << keyrange << " keys." << std::endl;
    }
}

Piano::~Piano() 
{
    std::cout << "The Piano has been removed from the stage." << std::endl;
}

void Piano::pressSustainPedal()
{
    std::cout << "Sustain Pedal is pressed" << std::endl;
}

void Piano::releaseSustainPedal()
{
    std::cout << "Sustain Pedal is released" << std::endl;
}

void Piano::playKeys(int startingKey, int endingKey, int noteSteps)
{
    std::cout << "-> Playing " << ((endingKey-startingKey+noteSteps) / noteSteps) 
    << " Keys from: " << startingKey << " to " << endingKey << std::endl;
    for (int i = startingKey; i <= endingKey; i += noteSteps)
    {
        std::cout << "Playing Key " << i << std::endl;
    }
}
/*
 copied UDT 2:
 */
struct AudioPlugin 
{
    bool bypass;
    bool initialized;
    int samplerate;

    AudioPlugin (int plugsamplerate) :
    bypass (false),
    initialized (true),
    samplerate(plugsamplerate)
    {
        std::cout << "The Plugin is running at " << samplerate << " Samples per Second." << std::endl;
    } 
    
    ~AudioPlugin()
    {
        std::cout << "The Plugin has been removed." << std::endl;
    }

    void processAudio();
};

void AudioPlugin::processAudio()
{
    int i = 0;
    int sampleblock = 32;
    int processingspeed = 8;
    while (i < sampleblock)
    {
        i += processingspeed;
        std::cout << i << " out of " << sampleblock << " Samples updated.." << std::endl;
    }


}

/*
 copied UDT 3:
 */
struct CommonTreasureChest
{
    int numberOfItems = 5;
    bool isOpened;
    bool isRare;  

    CommonTreasureChest(bool rarity) : 
    isOpened (false), 
    isRare (rarity)
    {
        if (isRare == false)
        {
             std::cout << "This is a common chest with a Max Capacity of 5 items" << std::endl;
        }
        else if (isRare == true)
        {
            std::cout << "This is a rare chest with a Max Capacity of 5 items" << std::endl;
        }
    }

    ~CommonTreasureChest() 
    {
        std::cout << "This TreasureChest has been destroyed." << std::endl;
    }

    bool openChest(bool openState);
    bool closeChest(bool openState);
    void lootChest();
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


};


#include <iostream>
int main()
{

    std::cout << std::endl;

    CommonTreasureChest Box01 (false);
    Box01.lootChest();
    Box01.isOpened = Box01.openChest(Box01.isOpened);
    Box01.openChest(Box01.isOpened);
    Box01.isOpened = Box01.closeChest(Box01.isOpened);
    Box01.closeChest(Box01.isOpened);
    CommonTreasureChest Box02 (true);
    Box02.lootChest();

    std::cout << std::endl;

    AudioPlugin MultibandCompressor (44100);
    MultibandCompressor.processAudio();

    std::cout << std::endl;

    Piano GrandPiano (88);
    GrandPiano.pressSustainPedal();
    GrandPiano.playKeys(25,30, 1);
    GrandPiano.playKeys(50,80, 10);

    std::cout << std::endl;

    PianoStore keyWorld;

    std::cout << std::endl;

    Daw cubase;
  

    std::cout << std::endl;
    std::cout << "good to go!" << std::endl;
    std::cout << std::endl;
}
