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

    int getOctaves();

    JUCE_LEAK_DETECTOR(Piano)
};