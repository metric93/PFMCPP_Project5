#include "AudioPlugin.h"

AudioPlugin::AudioPlugin (int plugsamplerate) :
bypass (false), initialized (true), samplerate(plugsamplerate)
{
    std::cout << "New Plugin is running at " << samplerate << " Samples per Second." << std::endl;
} 


AudioPlugin::~AudioPlugin()
{
    std::cout << "The Plugin has been removed." << std::endl;
}





void AudioPlugin::getData()    
{
    std::cout << "AudioPlugin instanceID(): " << this->instanceID() << " and AudioPlugin samplerate: " << this->samplerate << std::endl;  
}

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
