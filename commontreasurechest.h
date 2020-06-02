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