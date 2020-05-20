/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main (DONE)
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main to use your wrapper classes, which have your UDTs as pointer member variables.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example
 */



#include <iostream>
#include "LeakedObjectDetector.h"
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

    int getOctaves()
    {
        int octaves = this->range / 12;
        return octaves;
    }

    JUCE_LEAK_DETECTOR(Piano)
};

struct PianoWrapper
{
    Piano* adress = nullptr; //Initilaize Pointer to a Piano UDT to nullptr

    //Constructor for the PianoWrapper taking  a Pointer to a Piano UDT as an argument
    PianoWrapper(Piano* p) : 
    adress(p)        //updating the Pointer named piano to the adress of the UDT type pointerwe have a variable in the constructor
    {

    }
    ~PianoWrapper()
    {
        delete adress; //deleting the piano pointer when the destructor is called.
    }
};

Piano::Piano(int keyamount) : 
range(keyamount),
color('b')
{
    if (color == 'b')
    {
        std::cout << "I'm a Piano with " << this->range << " keys and " << getOctaves() << " Ocavtes." << std::endl;
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
        std::cout << "New Plugin is running at " << samplerate << " Samples per Second." << std::endl;
    } 
    
    ~AudioPlugin()
    {
        std::cout << "The Plugin has been removed." << std::endl;
    }

    void processAudio();

    void getData()
    {
        std::cout << "AudioPlugin instanceID(): " << this->instanceID() << " and AudioPlugin samplerate: " << this->samplerate << std::endl;  
    }


    int instanceID() { return 3; }
    //float memberVariable = 3.14f;

    JUCE_LEAK_DETECTOR(AudioPlugin)
};

struct AudioPluginWrapper
{
    AudioPlugin* adress = nullptr;

    AudioPluginWrapper(AudioPlugin* p) :
    adress (p)
    {

    }

   ~AudioPluginWrapper ()
   {
       delete adress;
   }
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
    CommonTreasureChest* adress = nullptr;

    CommonTreasureChestWrapper(CommonTreasureChest* c) :
    adress (c)
    {
    }

    ~CommonTreasureChestWrapper()
    {
        delete adress;
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
    PianoStore* adress = nullptr;

    PianoStoreWrapper(PianoStore* p) :
    adress (p)
    {
    }

    ~PianoStoreWrapper()
    {
        delete adress;
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
    Daw* adress = nullptr;

    DawWrapper (Daw* d) :
    adress (d)
    {
    }

    ~DawWrapper()
    {
        delete adress;
    }
};

#include <iostream>
int main()
{
/*
*/
    //UDT1
    CommonTreasureChestWrapper box1 (new CommonTreasureChest(false));   
    std::cout << "This is a common chest with a Max Capacity of " << box1.adress->numberOfItems << std::endl;
    
    CommonTreasureChestWrapper box2 (new CommonTreasureChest(false));   
    std::cout << "This is a rare chest with a Max Capacity of " << box2.adress->numberOfItems << std::endl;

    box1.adress->printTreasureCount();
    std::cout << "Rarity: " << box1.adress->isRare << std::endl;
    std::cout << "Treasure Count: " << box1.adress->numberOfItems << 
    " Rarity :" << box1.adress->isRare << std::endl;
    std::cout << std::endl;

    //UDT2
    AudioPluginWrapper eq (new AudioPlugin(44100));
    eq.adress->processAudio();
    eq.adress->getData();
    std::cout << "EQ instanceID(): " <<  eq.adress->instanceID() << " and EQ samplerate: " << 
    eq.adress->samplerate << std::endl; 
    std::cout << std::endl;
 
    //UDT3
    PianoWrapper piano(new Piano(88));
    std::cout << "I'm a Piano with " << piano.adress->range << " keys and " << piano.adress->getOctaves() << " Ocavtes"<< std::endl;
    piano.adress->pressSustainPedal();
    piano.adress->playKeys(25,30, 1);
    piano.adress->playKeys(50,80, 10);
    std::cout << std::endl;

    //UDT4 (using only UDTs)
    PianoStoreWrapper keyworld (new PianoStore());
    std::cout << "I'm a Piano with " << keyworld.adress->steinway.range << " keys and " << 
    keyworld.adress->steinway.getOctaves()  << " Octaves." << std::endl;
    std::cout << "I'm a Piano with " << keyworld.adress->practice.range << " keys and " << 
    keyworld.adress->practice.getOctaves()  << " Octaves." << std::endl;
    std::cout << "I'm a Piano with " << keyworld.adress->toybox.range << " keys and " << 
    keyworld.adress->toybox.getOctaves()  << " Octaves." << std::endl;
    std::cout << std::endl;

    //UDT5 (using only UDTs)
    DawWrapper cubase (new Daw());
    cubase.adress->checkInitialization();
    std::cout << "EQ:" << cubase.adress->equalizer.initialized << "  Compressor:" << cubase.adress->compressor.initialized << "  Reverb:" << cubase.adress->reverb.initialized << std::endl;



    std::cout << std::endl;
    std::cout << "good to go!" << std::endl;
    std::cout << std::endl;

}
