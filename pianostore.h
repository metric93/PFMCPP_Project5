struct PianoStore
 {
    PianoStore();
    ~PianoStore();

    Piano steinway;
    Piano practice;
    Piano toybox;

    JUCE_LEAK_DETECTOR(PianoStore)

 };