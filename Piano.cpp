#include "Piano.h"

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

int Piano::getOctaves()
{
    int octaves = this->range / 12;
    return octaves;
}
