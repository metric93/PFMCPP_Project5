#pragma once

#include "LeakedObjectDetector.h"

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