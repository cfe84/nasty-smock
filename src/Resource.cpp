#include <string>
#include "Resource.h"

using namespace std;

Resource::Resource(string name)
{
    this->name = name;
}

string Resource::getName()
{
    return this->name;
}