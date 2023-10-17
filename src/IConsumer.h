#ifndef ICONSUMER
#define ICONSUMER

#include <vector>
#include "Request.h"

using namespace std;

class IConsumer 
{
    public:
        virtual vector<Request*>* GetRequests() = 0;
};

#endif