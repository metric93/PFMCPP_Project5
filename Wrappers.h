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



struct PianoStore;
struct PianoStoreWrapper
{
    PianoStore* address = nullptr;

    PianoStoreWrapper(PianoStore* p);

    ~PianoStoreWrapper();
};


struct Daw;
struct DawWrapper
{
    Daw* address = nullptr;

    DawWrapper (Daw* d);

    ~DawWrapper();
};
