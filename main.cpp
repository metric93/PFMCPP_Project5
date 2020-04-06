/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}  
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}


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
    int printTreasureCount();
    bool printRarity();
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
    std::cout << "Treasure Count: " << this->numberOfItems << std::endl;
    return this->numberOfItems;
}

bool CommonTreasureChest::printRarity()
{
    std::cout << "Rarity: " << this->isRare << std::endl;
    return this->isRare;
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
	Example::main();
    std::cout << std::endl;

    CommonTreasureChest Box01 (false);
    CommonTreasureChest Box02 (true);
    /*
    Box01.lootChest();
    Box01.isOpened = Box01.openChest(Box01.isOpened);
    Box01.openChest(Box01.isOpened);
    Box01.isOpened = Box01.closeChest(Box01.isOpened);
    Box01.closeChest(Box01.isOpened);
    Box02.lootChest();
    */

    std::cout << "Treasure Count: " << Box01.numberOfItems << std::endl;
    Box01.printTreasureCount();


    std::cout << "Rarity: " << Box01.isRare << std::endl;
    Box01.printRarity();
    std::cout << "Rarity: " << Box02.isRare << std::endl;
    Box02.printRarity();

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
