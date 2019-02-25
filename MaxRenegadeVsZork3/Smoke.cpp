#include "Smoke.h"
#include <iostream>
#include <string>

using namespace std;

Smoke::Smoke(string description)
{
    this->description = description;
    cout << "Cigarette has been lit" << endl;
}

Smoke::~Smoke()
{
    cout << "Cigarette has been put out" << endl;
}

string Smoke::smokingDescription()
{
    return description;
}

