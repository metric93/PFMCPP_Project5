struct AudioPlugin 
{
    bool bypass;
    bool initialized;
    int samplerate;

    AudioPlugin (int plugsamplerate) :
    bypass (false),
    initialized (true),
    samplerate(plugsamplerate)
    {
        std::cout << "New Plugin is running at " << samplerate << " Samples per Second." << std::endl;
    } 
    
    ~AudioPlugin()
    {
        std::cout << "The Plugin has been removed." << std::endl;
    }

    void processAudio();

    void getData()
    {
        std::cout << "AudioPlugin instanceID(): " << this->instanceID() << " and AudioPlugin samplerate: " << this->samplerate << std::endl;  
    }


    int instanceID() { return 3; }
    //float memberVariable = 3.14f;

    JUCE_LEAK_DETECTOR(AudioPlugin)
};