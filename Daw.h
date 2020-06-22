#pragma once

#include "LeakedObjectDetector.h"
#include "AudioPlugin.h"

struct Daw 
{
    AudioPlugin equalizer;
    AudioPlugin compressor;
    AudioPlugin reverb;
    
    Daw();

    ~Daw();

    void checkInitialization ();


    JUCE_LEAK_DETECTOR(Daw)
};
