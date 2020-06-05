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
