#include "Daw.h"

Daw::Daw() :
equalizer (48000),
compressor (48000),
reverb (48000)
{
    std::cout << "Showing the Daw Splashscreen" << std::endl;
}

Daw::~Daw()
{
    std::cout << "Saving Settings and closing the Software" << std::endl;
}

void Daw::checkInitialization ()
{
    std::cout << "EQ:" << this->equalizer.initialized << "  Compressor:" << this->compressor.initialized << "  Reverb:" << this->reverb.initialized << std::endl;
}
