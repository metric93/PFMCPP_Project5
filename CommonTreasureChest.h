#pragma once

#include "LeakedObjectDetector.h"

struct CommonTreasureChest
{
    int numberOfItems;
    bool isOpened;
    bool isRare;  

    CommonTreasureChest(bool rarity);
    ~CommonTreasureChest();

    bool openChest(bool openState);
    bool closeChest(bool openState);
    void lootChest();
    int printTreasureCount();
    bool printRarity();
    void changeRarity(bool rarity);


    JUCE_LEAK_DETECTOR(CommonTreasureChest)
};
