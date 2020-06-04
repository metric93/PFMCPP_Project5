struct Piano;
struct PianoWrapper
{
    Piano* address = nullptr; //Initilaize Pointer to a Piano UDT to nullptr

    //Constructor for the PianoWrapper taking  a Pointer to a Piano UDT as an argument
    PianoWrapper(Piano* p) : 
    address(p)        //updating the Pointer named piano to the address of the UDT type pointerwe have a variable in the constructor
    {

    }
    ~PianoWrapper()
    {
        delete address; //deleting the piano pointer when the destructor is called.
    }
};