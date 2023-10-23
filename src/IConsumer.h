#ifndef ICONSUMER
#define ICONSUMER

#include <vector>
#include "Request.h"

using namespace std;

class IConsumer 
{
    public:
        virtual vector<Request*>* Require() = 0;
        virtual void Deliver(Resource* resource, double quantity) = 0;
};

#endif