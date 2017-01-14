#pragma once

#include "Car.h"

using namespace std;

void GetInfo(ostream & output, CCar & car);

void EngineOn(ostream & output, CCar & car);

void EngineOff(ostream & output, CCar & car);

bool SetGear(CCar & car, int value);

bool SetSpeed(CCar & car, int value);