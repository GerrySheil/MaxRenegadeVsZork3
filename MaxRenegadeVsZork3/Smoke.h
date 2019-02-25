#ifndef SMOKE_H
#define SMOKE_H
#include <string>

using namespace std;

class Smoke
{
public:
    Smoke(string description);
    ~Smoke();
    string smokingDescription();
private:
    string description;
};

#endif // SMOKE_H
