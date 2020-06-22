#include "Wrappers.h"
#include "Piano.h"
#include "AudioPlugin.h"
#include "CommonTreasureChest.h"
#include "PianoStore.h"
#include "Daw.h"

PianoWrapper::PianoWrapper(Piano* p) : address(p) {}

PianoWrapper::~PianoWrapper()
{
    delete address;
    address = nullptr;
}




AudioPluginWrapper::AudioPluginWrapper(AudioPlugin* p) : address(p) {}

AudioPluginWrapper::~AudioPluginWrapper()
{
    delete address;
    address = nullptr;
}



CommonTreasureChestWrapper::CommonTreasureChestWrapper(CommonTreasureChest* c) :
    address (c)
    {
    }

CommonTreasureChestWrapper::~CommonTreasureChestWrapper()
{
    delete address;
    address = nullptr;
}



PianoStoreWrapper::PianoStoreWrapper(PianoStore* p) : address(p) {}

PianoStoreWrapper::~PianoStoreWrapper()
{
    delete address;
    address = nullptr;
}



DawWrapper::DawWrapper(Daw* p) : address (p) {}

DawWrapper::~DawWrapper()
{
    delete address;
    address = nullptr;
}
