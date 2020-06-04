struct Piano;
struct PianoWrapper
{
    Piano* address = nullptr; 
    PianoWrapper(Piano* p);
    ~PianoWrapper();
};
