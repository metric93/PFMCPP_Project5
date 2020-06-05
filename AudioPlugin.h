#pragma once

#include "LeakedObjectDetector.h"

struct AudioPlugin 
{
    bool bypass;
    bool initialized;
    int samplerate;

    AudioPlugin (int plugsamplerate);

    ~AudioPlugin();

    void processAudio();

    void getData();


    int instanceID() { return 3; }
    //float memberVariable = 3.14f;

    JUCE_LEAK_DETECTOR(AudioPlugin)
};
