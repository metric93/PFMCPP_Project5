#include "CommonTreasureChest.h"

CommonTreasureChest::CommonTreasureChest(bool rarity)
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

CommonTreasureChest::~CommonTreasureChest() 
{
    std::cout << "This TreasureChest has been destroyed." << std::endl;
}

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