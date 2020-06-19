struct Piano;
struct PianoWrapper
{
    Piano* address = nullptr; 
    PianoWrapper(Piano* p);
    ~PianoWrapper();
};



struct AudioPlugin;
struct AudioPluginWrapper
{
    AudioPlugin* address = nullptr;

    AudioPluginWrapper(AudioPlugin* p);
   ~AudioPluginWrapper ();
};




struct CommonTreasureChest;
struct CommonTreasureChestWrapper
{
    CommonTreasureChest* address = nullptr;

    CommonTreasureChestWrapper(CommonTreasureChest* c); 
    ~CommonTreasureChestWrapper();
};
