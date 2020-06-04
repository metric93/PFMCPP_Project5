#pragma once

#include "Wrappers.h"
#include "Piano.h"

PianoWrapper::PianoWrapper(Piano* p) : address(p) {}

PianoWrapper::~PianoWrapper()
{
    delete address;
    address = nullptr;
}
